#!/bin/bash

# Autor: Arnau Blanch

for i in {1..5}
do
	if (( i%2 == 0 )); then
		echo "El número $i es par"
	else
		echo "El número $i es impar"
	fi
done
