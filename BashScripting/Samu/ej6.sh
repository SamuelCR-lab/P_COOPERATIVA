#!/bin/bash

for fichero in test6/*.txt; do
	if [[ -f "$fichero" ]];then
		Total_Lineas=$(grep -c '^' "$fichero")
		if [[ "$Total_Lineas" -gt 3 ]];then
			echo "El archivo $fichero tiene más de 3 líneas"
		else
			echo "El archivo $fichero tiene 3 líneas o menos"
		fi
	fi
done


