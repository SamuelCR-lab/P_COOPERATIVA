!/bin/bash

for fichero $(find -path test3/*log*);do
	if ((grep -q "ERROR"));then
		

	fi
done
