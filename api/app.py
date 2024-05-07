from flask import Flask, request, jsonify
from gensim.corpora import Dictionary
from gensim.models import TfidfModel
from flask_cors import CORS

app = Flask(__name__)
CORS(app, origins='*')

@app.route('/vectorize', methods=['POST'])
def vectorize():
    texts = request.get_json().get('texts', [])
    # Lista de documentos como listas de palavras
    documents = [doc.split() for doc in texts]
    # Cria um dicionário
    dictionary = Dictionary(documents)
    # Cria um corpus usando o dicionário
    corpus = [dictionary.doc2bow(doc) for doc in documents]
    # Treina o modelo TF-IDF
    tfidf = TfidfModel(corpus)
    # Aplica o modelo ao corpus e converte para uma lista densa
    tfidf_vectors = [sorted(tfidf[doc], key=lambda x: x[0]) for doc in corpus]
    # Convertendo para formato denso baseado no número total de tokens
    dense_vectors = [[x[1] for x in sorted(vec, key=lambda x: x[0])] for vec in tfidf_vectors]
    return jsonify(dense_vectors)

if __name__ == '__main__':
    app.run(port=5003)
