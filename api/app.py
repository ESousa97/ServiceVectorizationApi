from flask import Flask, request, jsonify
from flask_cors import CORS
import spacy

app = Flask(__name__)
CORS(app, origins='*')

# Carrega o modelo spaCy
try:
    nlp = spacy.load("en_core_web_sm")
except Exception as e:
    print(f"Erro ao carregar o modelo spaCy: {e}")

@app.route('/vectorize', methods=['POST'])
def vectorize():
    texts = request.get_json().get('texts', [])
    # Processa os textos e obtém os vetores médios dos tokens
    vectors = []
    for text in texts:
        if text.strip():  # Verifica se o texto não está vazio
            doc = nlp(text)
            vectors.append(doc.vector)
    return jsonify([vector.tolist() for vector in vectors])  # Retorna vetores como lista para facilitar serialização

if __name__ == '__main__':
    app.run(port=5003)
