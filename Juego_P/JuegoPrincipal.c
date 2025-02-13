#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "colors.h"
#include "textos.h"
#include "caballero.h"
#include "dragon.h"

#define NOMBRE_MAX 100
#define MAX_DRAGONES 4


int elegir_caballero(char ** nombre_c);
int dificultad();


int main(){
	int eleccion, eleccion_opo;
	char * alias;
	alias = (char *) malloc(NOMBRE_MAX);
	if (alias==NULL) return 1;
	system("clear");
	printf("%s",TXT_INTRO_01);

	eleccion = elegir_caballero(&alias);
	printf("Ya estás listo para pelear %s\n", alias);

	Caballero* Jugador = (Caballero*) malloc (sizeof(Caballero));
	if (eleccion == 1){
		Jugador = CrearBoromir(Jugador);
		// A jugador se le asigna una copia del caballero.
	}else if (eleccion == 2){
		Jugador = CrearLa_Montana(Jugador); 
	}else {
		Jugador = CrearEl_Cid(Jugador);
	}

	// Reserva de memoria para los 4 dragones.
	Dragon* Oponente = (Dragon*) malloc (MAX_DRAGONES * sizeof(Dragon));
	if (Oponente == NULL){
		printf("Ha ocurrido un error con la memoria de lso dragones\n");
		return EXIT_FAILURE;

	}

	// Inicializacion de los cuatro dragones.
	for (int i = 0; i < MAX_DRAGONES; i++){
		if (i == 0){
			Oponente[0] = *CrearMushu(&Oponente[0]); //Se le asigna el contenido de la función.
		}else if( i == 1){
			Oponente[1] = *CrearShenlong(&Oponente[1]);
		}else if(i == 2){
			Oponente[2] = *CrearBalerion(&Oponente[2]);
		}else if(i == 3){
			Oponente[3] = *CrearCahrizar(&Oponente[3]);
		}
	
	}

	// Eleccion de dificultad.
	// TODO: crear la batalla.
	eleccion_opo = dificultad();

	if(eleccion_opo == 1){
		printf("\tHas decidido enfrentarte a Mushu, el dragón travieso y pequeño, con un corazón valiente. Aunque no es muy grande, su ingenio lo convierte en un oponente formidable.\n");
	}else if(eleccion_opo == 2){
		printf("\tHas decidido enfrentarte a Shenlong, el dragón ancestral de las leyendas. Su poder es inmenso, capaz de controlar los elementos con un solo rugido. ¡Solo los valientes se atreven a desafiarlo!.\n");
	}else if(eleccion_opo == 3){
		printf("\tHas decidido enfrentarte a Balerion, conocido como el terror de los cielos. Su tamaño y fuerza son legendarios, su aliento de fuego arrasa con todo a su paso. Desafiarlo es un acto de valentía, o de locura...\n");
	}else if(eleccion_opo == 4){
		printf("\tHas decidido enfrentarte a Charizar, el dragón primordial, el destructor de mundos. Con su poder descomunal y su fuego incontrolable, ha arrasado imperios enteros. Solo los más valientes, o los más desesperados, se atreven a desafiarlo.\n");
	}



	free(alias);
	free(Jugador);
	free(Oponente);
	return 0;
}

int elegir_caballero(char ** nombre_c){
	int elegir,errores,elegir_alias;
	char respuesta[5];
	do{ // Es un do while porque siempre se va a ejecutar mínimo una vez y las variables aún no tienen ningún valor asignado.
		printf(BLUE "\n\n\t1. BOROMIR\n"); // TODO: Estadísticas de los personajes
		printf(RED "\t2. LA MONTAÑA\n");	
		printf(GREEN "\t3. CID CAMPEADOR");
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

// Función para elegir la dificultad.
int dificultad(){
	int elegir_opo, errores_opo;
	 do{
	 	printf(GREEN"\n\n\t 1. Mushu\n"); // TODO: Asignar las estadísticas a cada dragón.
	 	printf(YELLOW"\t 2. Shenlong \n");
	 	printf(MAGENTA"\t 3. Balerion \n");
	 	printf(RED"\t 4. Charizar \n");
	 	printf(WHITE "\n\n");
	 	printf("¿A que dragón te vas a enfrentar?: ");
		errores_opo = scanf("%d",&elegir_opo);
		if (errores_opo==0){ // Entra en el condicional si ha escrito una letra.
			printf("No has introducido un número o has introducido un número que no está asignado a ningún dragón\n");
			char buffer[50]; 
			scanf("%s",buffer); // Para limpiar el buffer y que no sea un bucle infinito.
		}
	 }while (elegir_opo < 1 || elegir_opo > 4 || errores_opo==0);

	 return elegir_opo;
}
