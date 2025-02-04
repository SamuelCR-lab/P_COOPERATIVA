#!/bin/bash

for fichero in "test3/*log*";do
	if (grep -q "ERROR" $fichero);then
		echo "El log $fichero tiene errores."
	else
		echo "El log $fichero no tiene errores."
	fi
done
