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


int main(){
	int eleccion, eleccion_opo, monedas, accion;
	char * alias;
	alias = (char *) malloc(NOMBRE_MAX);
	if (alias==NULL) return 1;
	system("clear");
	printf("%s",TXT_INTRO_01);

	eleccion = elegir_caballero(&alias);
	printf("Ya estás listo para pelear %s\n", alias);

	Caballero* Jugador = (Caballero*) malloc (sizeof(Caballero));
	if (eleccion == 1){
		CrearBoromir(&Jugador);
		// A jugador se le asigna una copia del caballero.
	}else if (eleccion == 2){
		CrearLa_Montana(&Jugador); 
	}else {
		CrearEl_Cid(&Jugador);
	}
	// TODO: Menú Jugar/Tienda/Exit
	// Reserva de memoria para los 4 dragones.
	Dragon* Oponente = (Dragon*) malloc (MAX_DRAGONES * sizeof(Dragon));
	if (Oponente == NULL){
		printf("Ha ocurrido un error con la memoria de los dragones\n");
		return EXIT_FAILURE;

	}

	// Inicializacion de los cuatro dragones.
	for (int i = 0; i < MAX_DRAGONES; i++){
		if (i == 0){
			CrearMushu(&Oponente[0]); //Se le asigna el contenido de la función.
		}else if( i == 1){
			CrearShenlong(&Oponente[1]);
		}else if(i == 2){
			CrearBalerion(&Oponente[2]);
		}else if(i == 3){
			CrearCharizar(&Oponente[3]);
		}
	
	}

	// Eleccion de dificultad.
	// TODO: crear la batalla.
	eleccion_opo = dificultad();

	if(eleccion_opo == 1){
		printf("%s",D_MUSHU);
	}else if(eleccion_opo == 2){
		printf("%s",D_SHENLONG);
	}else if(eleccion_opo == 3){
		printf("%s",D_BALERION);
	}else if(eleccion_opo == 4){
		printf("%s",D_CHARIZAR);
	}

	printf("\n\n");
	
	monedas = 50;
	mejorar_stats(&Jugador, &monedas);
	for (int i = 0; i <= 2000; i++){
		accion = menu();
		if (accion == 1){
			batalla(&Jugador, &Dragon[eleccion_opo]);
		}else if(accion == 2){
			eleccion_opo = dificultad();
		}else if(accion == 3){
			mejorar_stats(&Jugador, &monedas);
		}
	}

	free(alias);
	free(Jugador);
	free(Oponente);
	return 0;
}




