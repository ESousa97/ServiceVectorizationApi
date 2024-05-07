#!/bin/bash

# Verificar se o módulo distutils está instalado
if ! python3.12 -c "import distutils" &> /dev/null; then
    echo "Instalando o módulo distutils..."
    pip3.12 install distutils
fi

# Instalar os requisitos do projeto
pip3.12 install --disable-pip-version-check --target . --upgrade -r /vercel/path0/requirements.txt
