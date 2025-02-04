#!/bin/bash

for archivo in *.txt; do
    if grep -q '.' "$archivo"; then
        echo "El archivo $archivo tiene contenido."
    else
        echo "El archivo $archivo está vacío."
    fi
done
