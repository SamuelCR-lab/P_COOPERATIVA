#!/bin/bash

for fichero in $(find -path *:Zone.Identifier);do
if [[ "$fichero" == *:Zone.Identifier ]];then 
	echo "Eliminando: $fichero"
	rm "$fichero"
fi
done
	
