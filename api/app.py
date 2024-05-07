from flask import Flask, request, jsonify
from flask_cors import CORS
import spacy
import logging

app = Flask(__name__)
CORS(app, origins='*')

logging.basicConfig(level=logging.INFO)

# Tentativa de carregar o modelo spaCy
try:
    nlp = spacy.load("en_core_web_sm")
    logging.info("Modelo spaCy carregado com sucesso.")
except Exception as e:
    nlp = None
    logging.error(f"Erro ao carregar o modelo spaCy: {e}")

@app.route('/vectorize', methods=['POST'])
def vectorize():
    if not nlp:
        return jsonify({"error": "Modelo spaCy não está carregado."}), 500

    data = request.get_json()
    if isinstance(data, dict):
        texts = data.get('texts', [])
    elif isinstance(data, list):
        texts = data
    else:
        logging.warning("Formato de dados inválido recebido.")
        return jsonify({"error": "Formato de dados inválido."}), 400

    vectors = []
    try:
        for text in texts:
            if text.strip():  # Verifica se o texto não está vazio
                doc = nlp(text)
                vectors.append(doc.vector)
        logging.info("Vetores gerados com sucesso.")
        return jsonify([vector.tolist() for vector in vectors])
    except Exception as e:
        logging.error(f"Erro durante a vetorização: {e}")
        return jsonify({"error": str(e)}), 500

if __name__ == '__main__':
    app.run(port=5003)
