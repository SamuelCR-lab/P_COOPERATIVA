#!/bin/bash

for fichero in $(ls test5/*);do
	if [[ "$fichero" == *.jpg.old ]];then
		sed 's/.jpg.old/.old/' "*.jpg.old"
	fi
done
