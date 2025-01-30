#!/bin/bash

# Autor: Arnau Blanch

for file in test3/*log*
do
	if [ $( grep -c "ERROR" $file ) -ge 1 ]; then
		echo "El log $file tiene errores"
	else
		echo "El log $file no tiene errores"
	fi
done
