#!/bin/bash

# Autor: Arnau Blanch
busca_directorio(){
	for directorio in $(ls $1); do
		echo -e "\t$1$directorio"
		if [ -d "$1$directorio" ]; then
			echo "He encontrado $directorio"
		fi
	done
}

busca_directorio test9/
