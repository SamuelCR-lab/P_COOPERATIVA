#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "textos.h"
#include "colors.h"
#include "caballero.h"

int elegir_caballero(char ** nombre_c){
	int elegir,errores,elegir_alias;
	char respuesta[5];
	do{ // Es un do while porque siempre se va a ejecutar mínimo una vez y las variables aún no tienen ningún valor asignado.
		printf(BLUE "\n\n\t1. BOROMIR\n\t\tAtaque: 30\n\t\tSalud: 55\n\t\tVelocidad: 18\n");
	 	system("cat < Boromir.txt");
		printf(RED "\t2. LA MONTAÑA\n\t\tAtaque: 50\n\t\tSalud: 50\n\t\tVelocidad: 12\n");
	 	system("cat < La_Montana.txt");
		printf(GREEN "\t3. CID CAMPEADOR\n\t\tAtaque: 38\n\t\tSalud: 58\n\t\tVelocidad: 15\n");
	 	system("cat < El_Cid.txt");
		printf(WHITE "\n"); // Pongo WHITE para que se resetee el color para los próximos printfs.
		printf("Elige que caballero quieres ser: ");
		errores = scanf("%d",&elegir);
		if (errores==0){ // Entra en el condicional si ha escrito una letra.
			printf("No has introducido un número\n");
			char buffer[50]; 
			scanf("%s",buffer); // Para limpiar el buffer y que no sea un bucle infinito.
		} else if(elegir < 1 || elegir > 3){
			printf("Has introducido un número erróneo\n");
		}
	}while (elegir < 1 || elegir > 3 || errores == 0);

	printf("¿Quieres personalizar el nombre de tu caballero? ");
	scanf(" %s", respuesta);
	if (strcmp(respuesta, "si")==0 ||strcmp(respuesta, "Si")==0 ||strcmp(respuesta, "sí")==0 ||strcmp(respuesta, "Sí")==0){
		printf("\tQue nombre le quieres dar a tu caballero: ");
		scanf(" %[^\n]", *nombre_c);
		elegir_alias=0; // Para saber que sí ha cambiado el nombre al caballero.
	}else{
		elegir_alias=1; // Para saber que no ha cambiado el nombre al caballero
	}
		
	switch (elegir){
		case 1:
			if (elegir_alias){
				strcpy(*nombre_c,"Boromir");
			}
			printf("%s",CABALLERO1);
			break;
		case 2:
			if (elegir_alias){
				strcpy(*nombre_c,"La Montaña");
			}
			printf("%s",CABALLERO2);
			break;
		case 3:
			if (elegir_alias){
				strcpy(*nombre_c,"Cid Campeador");
			}
			printf("%s",CABALLERO3);
			break;
	}
	return elegir;
}