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
	if (alias == NULL) return EXIT_FAILURE;

	system("clear");
	system("cat < Demonio.txt");
	printf("%s",TXT_INTRO_01);
    sleep(5);

	eleccion = elegir_caballero(&alias);
	printf("%s",TXT_INTRO_02);
	printf(ROSE "\n");
	system("cat < Princesa.txt");
	printf(WHITE "\n");
    sleep(5);

    // Reserva de memória para un jugador.
	Caballero* Jugador = (Caballero*) malloc (sizeof(Caballero));
	if (Jugador == NULL){
		printf("Ha ocurrido un error con la memoria del caballero\n");
		free(alias);
		return EXIT_FAILURE;
	}
	switch (eleccion){
		case 1:
			CrearBoromir(Jugador, alias);
			// A jugador se le asigna una copia del caballero.
			break;
		case 2:
			CrearLa_Montana(Jugador, alias); 
			break;
		case 3:
			CrearEl_Cid(Jugador, alias);
			break;
		case 4:
			CrearCaballeroNuevo(Jugador, alias);
			break;
		default:
			printf("ERROR en la eleccion de personaje.\n");
			break;
	}

	// Reserva de memória para los 4 dragones.
	Dragon* Oponente = (Dragon*) malloc (MAX_DRAGONES * sizeof(Dragon));
	if (Oponente == NULL){
		printf("Ha ocurrido un error con la memoria de los dragones\n");
		free(alias);
		free(Jugador);
		return EXIT_FAILURE;
	}

	// Inicialización de los cuatro dragones.
	CrearMushu(&Oponente[0]); //Se le asigna el contenido de la función.
	CrearShenlong(&Oponente[1]);
	CrearBalerion(&Oponente[2]);
	CrearCharizard(&Oponente[3]);

	if (strcmp(Jugador->alias,"Víctor de Juan") == 0 && eleccion != 4)
		Jugador->monedas += 100;

	// Elección de dificultad.
	do{
		accion = menu();
		if (accion == 1){
			eleccion_opo = dificultad();
			switch(eleccion_opo){
				case 1:
					printf("%s",D_MUSHU);
	    			sleep(1);
	    			break;
	    		case 2:
					printf("%s",D_SHENLONG);
	    			sleep(1);
	    			break;
				case 3:
					printf("%s",D_BALERION);
	    			sleep(1);
	    			break;
				default:
				printf("%s",D_CHARIZARD);
    			sleep(1);
			}
			resultado = batalla(Jugador, Oponente[eleccion_opo-1]);
			switch(resultado){
				case 0:
					printf("\tIncreible!\n");
					printf("\tTodo por la princesa!\n");
					break;
				case 1:
					printf("%s",TXT_DIOS);
					sleep(2);
					break;
				case 2:
					printf("%s",TXT_CAMINO_INFRA);
					printf("%s",TXT_TIENDA_INFRA);
					sleep(2);
					tienda_inframundo(Jugador);
					break;
				case 3:
					accion = 4;
					break;
				default:
					accion = 4;
					// Lore de la princesa
					printf("%s",TXT_FINAL1);
					printf("\t\t'¿Eres tú… mi salvador?' —susurra, con lágrimas de emoción en los ojos.\n");
					printf("Asientes, respirando con dificultad, y antes de que puedas decir una palabra más, ella corre hacia ti y te abraza con fuerza.\n");
					printf("\t\t'Creí que nunca volvería a ver la luz del día...' exclama con efucividad\n");
					printf("Tomas su rostro con suavidad, limpiando con tus dedos una lágrima que resbala por su mejilla.\n");
					printf("\t\tNunca iba a dejar que estos dragones te alejaran de tu hogar…\n");
					printf("%s",TXT_FINAL2);
					system("cat < Beso.txt");
					printf("%s",TXT_FINAL3);
					system("cat < Fin.txt");
			}
		}else if(accion == 2){
			mejorar_stats(Jugador);
		} // TODO: Si la opción es 3 que guarde la partida.
	} while (accion != 3);
	printf("Saliendo");
	for (int i = 0;i<3;i++){
		printf(".");
		fflush(stdout);
		sleep(1);	
	}
	printf("\n");
	free(alias);
	free(Jugador);
	free(Oponente);
	return 0;
}




