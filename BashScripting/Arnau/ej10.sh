#!/bin/bash

# Autor: Arnau Blanch

ps aux >> processes.txt

for proc in $(cat processes.txt | awk -v FS=' ' '{ print $2 }'); do
	if $(ps aux | awk -v FS=' ' '{ print $2 }' | grep -q "$proc"); then
		echo "El proceso $proc está en ejecución"
	else
		echo "El proceso $proc no está en ejecución"
	fi
done
