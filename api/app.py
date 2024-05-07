from flask import Flask, request, jsonify
from sklearn.feature_extraction.text import TfidfVectorizer
from flask_cors import CORS

app = Flask(__name__)
CORS(app, origins='*')
vectorizer = TfidfVectorizer(stop_words='english')

@app.route('/vectorize', methods=['POST'])
def vectorize():
    texts = request.get_json().get('texts', [])
    X = vectorizer.fit_transform(texts)
    return jsonify(X.toarray().tolist())  # Retorna vetores como lista para facilitar serialização

if __name__ == '__main__':
    app.run(port=5003)
