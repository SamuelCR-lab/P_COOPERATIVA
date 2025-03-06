#include <stdio.h>
#include <stdlib.h>
#include "textos.h"
#include "JuegoPrincipal.h"

int menu(){
	int accion, errores;
	//system("clear");
	system("cat < Menu.txt");
	do{
		printf("\n%s\n",MENU);
		printf("%s\n %s\n %s\n",ELECCION1,ELECCION2,ELECCION3);
		printf("¿Que acción quieres realizar? ");
		errores = scanf(" %d",&accion);
		if (errores == 0){ // Entra en el condicional si ha escrito una letra.
			printf("No has introducido un número\n");
			char buffer[BUFFER]; 
			scanf("%s",buffer); // Para limpiar el buffer y que no sea un bucle infinito.
		} else if(accion < 1 || accion > 3){
			printf("Has introducido un número erróneo\n");
		} // TODO: Opcion de información.
	}while(accion < 1 || accion > 3 || errores == 0);
	return accion;
}