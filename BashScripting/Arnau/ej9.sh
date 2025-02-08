#!/bin/bash

# Autor: Arnau Blanch

busca_directorio(){
	for directorio in $(ls $1); do
		if [ -d "$1$directorio" ]; then
			busca_directorio $1$directorio/
		elif [ $(grep -c .txt <<< $directorio) -ge 1 ]; then
			head -n 1 $1$directorio
			echo ""
		fi
	done
}

busca_directorio test9/
