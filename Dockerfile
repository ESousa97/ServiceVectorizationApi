# Usa uma imagem base do Python 3.9, que ainda inclui distutils
FROM python:3.9-slim

# Define o diretório de trabalho no contêiner
WORKDIR /app

# Copia os arquivos de requisitos primeiro, para aproveitar o cache de camadas do Docker
COPY requirements.txt .

# Instala as dependências do projeto
RUN pip install --no-cache-dir -r requirements.txt

# Copia o restante dos arquivos do projeto
COPY . .

# Expõe a porta que o Flask vai usar
EXPOSE 5003

# Comando para rodar a aplicação
CMD ["python", "api/app.py"]
