# Service Vectorization Api

Este projeto combina uma aplicação Flask simples com um ambiente Next.js. O foco deste README é no backend, explicando como configurar, executar e utilizar a API Flask para vetorização de textos utilizando o modelo spaCy.

## Funcionalidade

A API Flask fornece um endpoint /vectorize que recebe textos e retorna seus vetores de representação gerados pelo modelo spaCy. Esta funcionalidade é útil para aplicações de processamento de linguagem natural (NLP), onde a representação vetorial de textos é frequentemente utilizada para diversas análises e modelagens.

### Pré-requisitos

Certifique-se de ter os seguintes softwares instalados:

- Python 3.12
- pip (gerenciador de pacotes do Python)
- Node.js e npm (gerenciador de pacotes do Node.js)

## Instalação

### Backend (Flask)

**1. Clone o repositório:**

```bash

git clone <URL-do-repositório>
cd <nome-do-diretório>

```

**2. Crie um ambiente virtual:**

```bash

python3 -m venv env
source env/bin/activate  # Para Linux/Mac
.\env\Scripts\activate   # Para Windows

```

**3. Instale as dependências do Python:**

```bash

pip install -r requirements.txt

```

**4. Baixe e instale o modelo spaCy:**

```bash

python -m spacy download https://github.com/explosion/spacy-models/releases/download/en_core_web_sm-3.7.0/en_core_web_sm-3.7.0.tar.gz

```

### Frontend (Next.js)

**1. Instale as dependências do Node.js:**

```bash

npm install

```

## Execução

### Backend (Flask)

**1. Inicie o servidor Flask:**

```bash

python api/app.py

```
O servidor estará rodando em `http://127.0.0.1:5003`.

## Endpoints da API

### Vectorize

- **URL:** `/vectorize`

- **Método:** `POST`

- **Descrição:** Recebe uma lista de textos e retorna os vetores de representação gerados pelo modelo spaCy.

- **Exemplo de Requisição:**

```json

{
  "texts": ["Hello world", "API for testing"]
}

```

- **Exemplo de Resposta:**

```json

[
  [0.1, 0.2, ..., 0.3],  // Vetor representando "Hello world"
  [0.4, 0.5, ..., 0.6]   // Vetor representando "API for testing"
]

```

## Estrutura dos Arquivos

- **api/app.py:** Código principal da API Flask.
- **package.json:** Arquivo de configuração do Node.js com scripts e dependências.
- **vercel.json:** Arquivo de configuração para implantação no Vercel.
- **requirements.txt:** Lista de dependências do Python.

## Detalhes do Código

### app.py

O arquivo `app.py` define a aplicação Flask e a rota `/vectorize`. Aqui estão os principais componentes:

**1. Carregamento do modelo spaCy:**

O modelo `en_core_web_sm` é carregado no início. Se houver algum erro, o modelo não é carregado e uma mensagem de erro é registrada.

```python

try:
    nlp = spacy.load("en_core_web_sm")
    logging.info("Modelo spaCy carregado com sucesso.")
except Exception as e:
    nlp = None
    logging.error(f"Erro ao carregar o modelo spaCy: {e}")

```

**2. Rota `/vectorize`:**

- Recebe uma requisição POST com uma lista de textos.
- Verifica se o modelo spaCy foi carregado.
- Processa os textos, gerando vetores para cada um.
- Retorna os vetores como uma lista de listas.

```python

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

```

## Vercel.json

O arquivo `vercel.json` configura a implantação da aplicação no Vercel.

```json

{
  "version": 2,
  "builds": [
    {
      "src": "api/app.py",
      "use": "@vercel/python",
      "config": { "runtime": "python-3.12.0" }
    }
  ],
  "routes": [
    {
      "src": "/vectorize",
      "dest": "/api/app.py"
    },
    {
      "src": "/api/(.*)",
      "dest": "/api/app.py"
    }
  ]
}

```

## Implantação no Vercel

**1. Configure o Vercel CLI:**

```bash

npm install -g vercel
vercel login

```

**2. Implante o projeto:**

```bash

vercel

```

### Dependências

- **Flask:** Framework web para Python.
- **Flask-CORS:** Extensão para permitir CORS.
- **spaCy:** Biblioteca para processamento de linguagem natural.
- **Werkzeug:** Biblioteca WSGI para Python.

### Licença

Este projeto está licenciado sob a licença MIT. Veja o arquivo LICENSE para mais detalhes.

##