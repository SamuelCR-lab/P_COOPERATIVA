#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "colors.h"
#include "textos.h"

#define NOMBRE_MAX 100

int elegir_caballero();

int main(){
	int eleccion;
	char * alias;
	alias = (char *) malloc(NOMBRE_MAX);
	if (alias==NULL) return 1;
	system("clear");
	printf("%s",TXT_INTRO_01);
	eleccion = elegir_caballero(&alias);
	printf("Ya estás listo para pelear %s\n", alias);


	free(alias);
	return 0;
}

int elegir_caballero(char ** nombre_c){
	int elegir,errores,elegir_alias;
	char respuesta[5];
	do{ // Es un do while porque siempre se va a ejecutar mínimo una vez y las variables aún no tienen ningún valor asignado.
		printf(BLUE "\n\n\t1. LANCELOT\n"); 
		printf(RED "\t2. LA MONTAÑA\n");	
		printf(GREEN "\t3. CID");
		printf(WHITE "\n\n"); // Pongo WHITE para que se resetee el color para los próximos printfs.
		printf("Elige que caballero quieres ser: ");
		errores = scanf("%d",&elegir);
		if (errores==0){ // Entra en el condicional si ha escrito una letra.
			printf("No has introducido un número o has introducido mas/menos de los caballeros que tenemos\n");
			char buffer[50]; 
			scanf("%s",buffer); // Para limpiar el buffer y que no sea un bucle infinito.
		}
	}while (elegir < 1 || elegir > 3 || errores==0);

	printf("¿Quieres personalizar el nombre de tu caballero? ");
	scanf("%s", respuesta);
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
				strcpy(*nombre_c,"Lancelot");
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
