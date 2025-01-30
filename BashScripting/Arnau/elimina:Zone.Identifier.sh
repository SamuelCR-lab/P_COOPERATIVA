#!/bin/bash

for ARCHIVO in $(find -path *.Identifier); do
	if [[ "$ARCHIVO" == *.Identifier ]]; then
		echo "Vas a eliminar: $ARCHIVO
		rm "$ARCHIVO"
	fi
done
