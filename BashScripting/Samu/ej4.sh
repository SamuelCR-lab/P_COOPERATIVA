#!/bin/bash

for ((i = 0; i<=10; i++));do
	if ((i == 3));then
		echo "Saltamos el numero 3"
		continue
	fi
	echo "i = $i"
done
