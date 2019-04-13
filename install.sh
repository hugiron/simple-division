#!/bin/bash
gcc -c -Wall -Werror -fPIC div.c
gcc -shared -o div.so div.o
rm div.o
virtualenv -p python3.6 ./venv/
source ./venv/bin/activate
# pip install -r requirements.txt
deactivate
