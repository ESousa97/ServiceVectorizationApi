#!/bin/bash

# Instalar o módulo distutils
pip3.12 install distutils

# Instalar os requisitos do projeto
pip3.12 install --disable-pip-version-check --target . --upgrade -r /vercel/path0/requirements.txt
