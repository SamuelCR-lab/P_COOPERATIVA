#!/bin/bash

for ARCHIVO in $(ls -R); do
	if [[ "$ARCHIVO" == *.Identifier ]]; then
		echo "$ARCHIVO"
	fi
done
