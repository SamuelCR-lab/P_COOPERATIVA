#!/bin/bash

# Autor: Arnau Blanch

i=1
for user in $(cat test8/usuarios.txt); do
	if [ "$user" = "maria" ]; then
		echo "Hola $user"
	else
		echo "Hola USUARIO $i"
	fi
	i=$(($i+1))
done
