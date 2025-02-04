#!/bin/bash

# Autor: Arnau Blanch

echo "Antes:"
ls test5/
echo "Después:"
for file in test5/*
do
	if [ $( grep -c '.jpg' <<< $file) -ge 1 ]; then
		echo -n "$(sed 's/.jpg/.old/g' <<< $file) " 
	fi
done
echo ""
