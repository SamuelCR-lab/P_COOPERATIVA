#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include "colors.h"
#include "textos.h"
#include "JuegoPrincipal.h"



int main(){
	int eleccion, eleccion_opo, accion, resultado;
	char * alias;

	alias = (char *) malloc(NOMBRE_MAX);
	if (alias==NULL) return EXIT_FAILURE;

	system("clear");
	system("cat < Demonio.txt");
	printf("%s",TXT_INTRO_01);
    sleep(5);

	eleccion = elegir_caballero(&alias);
	printf("Ya estás listo para pelear %s\n", alias);

	Caballero* Jugador = (Caballero*) malloc (sizeof(Caballero));
	if (Jugador == NULL){
		printf("Ha ocurrido un error con la memoria del caballero\n");
		free(alias);
		return EXIT_FAILURE;
	}

	if (eleccion == 1){
		CrearBoromir(Jugador, alias);
		// A jugador se le asigna una copia del caballero.
	}else if (eleccion == 2){
		CrearLa_Montana(Jugador, alias); 
	}else {
		CrearEl_Cid(Jugador, alias);
	}

	// Reserva de memoria para los 4 dragones.
	Dragon* Oponente = (Dragon*) malloc (MAX_DRAGONES * sizeof(Dragon));
	if (Oponente == NULL){
		printf("Ha ocurrido un error con la memoria de los dragones\n");
		free(alias);
		free(Jugador);
		return EXIT_FAILURE;
	}

	// Inicializacion de los cuatro dragones.
	CrearMushu(&Oponente[0]); //Se le asigna el contenido de la función.
	CrearShenlong(&Oponente[1]);
	CrearBalerion(&Oponente[2]);
	CrearCharizard(&Oponente[3]);

	// Eleccion de dificultad.
	Jugador->monedas = 50;
	do{
		accion = menu();
		if (accion == 1){
			eleccion_opo = dificultad();
			if(eleccion_opo == 1){
				printf("%s",D_MUSHU);
    			sleep(1);
			}else if(eleccion_opo == 2){
				printf("%s",D_SHENLONG);
    			sleep(1);
			}else if(eleccion_opo == 3){
				printf("%s",D_BALERION);
    			sleep(1);
			}else if(eleccion_opo == 4){
				printf("%s",D_CHARIZARD);
    			sleep(1);
			}
			resultado = batalla(Jugador, Oponente[eleccion_opo-1]);
			if (resultado == 0){
				continue;
			}else if(resultado == 1){
				// Tienda del inframundo y lore.
			}else if(resultado == 2){
				break;
			}else if(resultado == 3){
				// Lore de la princesa
				printf("\n\n");
				system("cat < Beso.txt");
				break;
			}
		}else if(accion == 2){
			mejorar_stats(Jugador);
		}
	} while (accion != 3);

	free(alias);
	free(Jugador);
	free(Oponente);
	return 0;
}




