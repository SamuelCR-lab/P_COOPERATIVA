#!/bin/bash

# Autor: Arnau Blanch

for file in $(ls test7/*); do
	if [[ $(grep -c .conf <<< $file) -ge 1 ]]; then
		sed 's/localhost/127.0.0.1/g' $file
	fi
done
