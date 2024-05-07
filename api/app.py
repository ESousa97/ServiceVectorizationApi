from flask import Flask, request, jsonify
from nltk.tokenize import word_tokenize
from nltk.corpus import stopwords
from nltk.stem import PorterStemmer
from collections import defaultdict
import numpy as np
from flask_cors import CORS

app = Flask(__name__)
CORS(app, origins='*')

# Download dos recursos necessários do NLTK
import nltk
nltk.download('punkt')
nltk.download('stopwords')

# Inicialização do stemmer e das stopwords
stemmer = PorterStemmer()
stop_words = set(stopwords.words('english'))

@app.route('/vectorize', methods=['POST'])
def vectorize():
    texts = request.get_json().get('texts', [])
    
    # Processamento do texto
    tokenized_texts = [word_tokenize(text.lower()) for text in texts]
    filtered_texts = [[stemmer.stem(word) for word in tokens if word.isalnum() and word not in stop_words] for tokens in tokenized_texts]
    
    # Criação do vetor de características
    vocabulary = defaultdict()
    index = 0
    for text in filtered_texts:
        for word in text:
            if word not in vocabulary:
                vocabulary[word] = index
                index += 1
    
    X = np.zeros((len(texts), len(vocabulary)))
    for i, text in enumerate(filtered_texts):
        for word in text:
            if word in vocabulary:
                X[i][vocabulary[word]] += 1
    
    return jsonify(X.tolist())

if __name__ == '__main__':
    app.run(port=5003)
