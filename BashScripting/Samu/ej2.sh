#!/bin/bash


for ((numero = 1; numero<=10; numero++));
do
	if ((numero % 2 == 0));then
		echo "$numero es par"
	else
		echo "$numero es impar"
	fi
done
 echo " "
for numero in {1..10};do
	if ((numero % 2 == 0));then
		echo "$numero es par"
	else
		echo "$numero es impar"
	fi
done