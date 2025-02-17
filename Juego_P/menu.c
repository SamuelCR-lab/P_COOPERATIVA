#include <stdio.h>
#include <stdlib.h>
#include "textos.h"


int menu(){
	int accion, errores;
	do{
		printf("%s\n",MENU);
		printf("\t%s\n \t%s\n \t%s\n",ELECCION1,ELECCION2,ELECCION3);
		errores = scanf(" %d",&accion);
		if (errores == 0){ // Entra en el condicional si ha escrito una letra.
			printf("No has introducido un número\n");
			char buffer[BUFFER]; 
			scanf("%s",buffer); // Para limpiar el buffer y que no sea un bucle infinito.
		} else if(accion < 1 || accion > 3){
			printf("Has introducido un número erróneo\n");
		}
	}while(accion < 1 || accion > 3 || errores == 0);
	return accion;
}