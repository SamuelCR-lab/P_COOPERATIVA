#!/bin/bash

for fichero in test5/*.jpg.old;do
	if [[ -f "$fichero" ]];then
		nuevo_nombre="${fichero/.jpg.old/.old}"
		mv "$fichero" "$nuevo_nombre"
	fi
done
