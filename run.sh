#!/usr/bin/env bash
if [[ -f "./div.so" ]] && [[ -d "./venv" ]]
then
source ./venv/bin/activate
python3 main.py
deactivate
else
echo "You need to run install.sh first."
fi
