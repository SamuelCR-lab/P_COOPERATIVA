#!/bin/bash

# Autor: Arnau Blanch

for file in $(ls test6/*); do
	lines=$(wc -l $file | awk -v FS=' ' '{ print $1 }')
	if [[ $(grep -c .txt <<< $file) -ge 1 ]]; then
		if [[ $lines -gt 3 ]]; then
			echo "El archivo $file tiene más de 3 líneas"
		else
			echo "El archivo $file tiene 3 líneas o menos"
		fi
	fi
done
