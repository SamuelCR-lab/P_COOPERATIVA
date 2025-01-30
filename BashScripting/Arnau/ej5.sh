#!/bin/bash

# Autor: Arnau Blanch

echo "Antes:"
ls test5/
for file in test5/*
do
	echo -e "\t$file"
#	if [[ $file == *.jpg ]]; then
	if [ $( grep -c .jpg $file) -ge 1 ]; then
		echo "SI"
		# sed 's/.jpg/.old/' $file
	fi
done
echo "Después:"
ls test5/
