#!/bin/bash

# Instalar python3-distutils se não estiver instalado
if ! dpkg -s python3-distutils &> /dev/null; then
    echo "Instalando python3-distutils..."
    sudo apt-get update
    sudo apt-get install -y python3-distutils
fi

# Instalar os requisitos do projeto
pip3.12 install --disable-pip-version-check --target . --upgrade -r /vercel/path0/requirements.txt
