#include <stdio.h>
#include <stdlib.h>
/*
	Trabajo realizado por Arnau y Samuel
*/
int main(){
	int exit;
	printf("Escribe cuantos numeros quieras y escribe exit para salir\n");
	do{
		ajustar_tamanio();
		scanf("%d");
	}while(exit == 0);


return 0;
}
