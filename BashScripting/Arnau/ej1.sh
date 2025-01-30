#!/bin/bash

# Autor: Arnau Blanch

for file in test1/*.txt
do
	if [[ -s $file ]]; then
		echo "El archivo $file NO está vacío"
	else
		echo "El archivo $file está vacío"
	fi
done
