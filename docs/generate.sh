#!/bin/bash

CURRENT_DIRECTORY=$(basename "$PWD")

if [ "$CURRENT_DIRECTORY" = "docs" ]
then
    cd ..
fi

gcc docs/main.c -o main
./main 10000
rm main

source ./venv/bin/activate
python ./docs/generate_graphs.py
