#!/bin/bash

# Autor: Arnau Blanch

for i in {1..5}
do
	if (( i==3 )); then
		echo "Saltamos el número $i"
		continue
	fi
	echo "i = $i"
done
