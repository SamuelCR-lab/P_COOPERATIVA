#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include "JuegoPrincipal.h"
#include "colors.h"

// Pasamos los Caballeros por referencia, que sera copiado en la reserva de memoria
// del main, así, cualquier cambio solo se vera reflejado en la copia que hagamos 
// del caballero en el malloc del main.

void CrearBoromir(Caballero* Boromir, char* alias){
	strcpy(Boromir->nombre,"Boromir");
	strcpy(Boromir->alias, alias);
	Boromir->vida =  55;
	Boromir->vidaActual = 55;
	Boromir->ataque = 27;
	Boromir->velocidad = 18;
	Boromir->monedas = 0;
}
void CrearLa_Montana(Caballero* La_Montana, char* alias){
	strcpy(La_Montana->nombre,"La_Montaña");
	strcpy(La_Montana->alias, alias);
	La_Montana->vida =  50;
	La_Montana->vidaActual = 50;
	La_Montana->ataque = 47;
	La_Montana->velocidad = 12;
	La_Montana->monedas = 0;
}
void CrearEl_Cid(Caballero* El_Cid, char* alias){
	strcpy(El_Cid->nombre,"El_Cid");
	strcpy(El_Cid->alias, alias);
	El_Cid->vida =  58;
	El_Cid->vidaActual = 58;
	El_Cid->ataque = 35;
	El_Cid->velocidad = 15;
	El_Cid->monedas = 0; 
}
void CrearCaballeroNuevo(Caballero* Nuevo, char* alias){
	int puntos = 110, vida, ataque, velocidad, errores, bandera;
	strcpy(Nuevo->nombre, alias);
	strcpy(Nuevo->alias, alias);
	printf("Tienes un máximo de 110 puntos que puedes reartir entre las tres estadísticas:\n");
	do {
		bandera = 0;
		Nuevo->vida =  0;
		Nuevo->vidaActual = 0;
		Nuevo->ataque = 0;
		Nuevo->velocidad = 0;
		printf("¿Cuánta vida quieres?: ");
		errores = scanf("%d", &vida);
		if (errores==0){ // Entra en el condicional si ha escrito una letra.
			printf("No has introducido un número\n");
			char buffer[50]; 
			scanf("%s",buffer); // Para limpiar el buffer y que no sea un bucle infinito.
			bandera ++;
		} else if(puntos < vida){
			printf("La suma de tus estadísticas supera el máximo permitido (110)\n");
			bandera ++;
		} else {
			Nuevo->vida =  vida;
			Nuevo->vidaActual = vida;
		}
		printf("¿Cuánto ataque quieres?: ");
		errores = scanf("%d", &ataque);
		if (errores==0){ // Entra en el condicional si ha escrito una letra.
			printf("No has introducido un número\n");
			char buffer[50]; 
			scanf("%s",buffer); // Para limpiar el buffer y que no sea un bucle infinito.
			bandera ++;
		} else if(puntos < vida+ataque){
			printf("La suma de tus estadísticas supera el máximo permitido (110)\n");
			bandera ++;
		} else {
			Nuevo->ataque =  ataque;
		}
		printf("¿Cuánta velocidad quieres?: ");
		errores = scanf("%d", &velocidad);
		if (errores==0){ // Entra en el condicional si ha escrito una letra.
			printf("No has introducido un número\n");
			char buffer[50]; 
			scanf("%s",buffer); // Para limpiar el buffer y que no sea un bucle infinito.
			bandera ++;
		} else if(puntos < vida+ataque+velocidad){
			printf("La suma de tus estadísticas supera el máximo permitido (110)\n");
			bandera ++;
		} else {
			Nuevo->velocidad = velocidad;
		}
		Nuevo->monedas = 0;
		printf("\n\n");
	} while (bandera != 0);
}
void ataqueCaballero(Caballero* jugador, Dragon* npc){
	int critico = 0, randomAtaque = 0;
	int randomCri = rand() % 8;
    if (randomCri == 1){
    	printf("El caballero ha hecho un ataque crítico!!\n");
        critico = jugador->ataque;
        critico /= 3;
    }
    randomAtaque = rand() % 5; 
    npc->vidaActual -= jugador->ataque + critico + randomAtaque;
    sleep(1);
    printf("\tEl caballero %s ataca al dragon %s\n", jugador->alias, npc->nombre);
    if (strcmp(jugador->nombre, "Boromir")==0){
    	printf(BLUE "\n");
    	system("cat < Boromir.txt");
    	printf(WHITE "\n");
    }else if (strcmp(jugador->nombre, "La_Montaña")==0){
    	printf(RED "\n");
	 	system("cat < La_Montana.txt");
    	printf(WHITE "\n");
    }else if (strcmp(jugador->nombre, "El_Cid")==0){
    	printf(GREEN "\n");
    	system("cat < El_Cid.txt");
    	printf(WHITE "\n");
    }
    
    if(npc->vidaActual < 0){
    	npc->vidaActual = 0;
    }
    printf("\tSalud de %s: %d / %d\n", npc->nombre, npc->vidaActual, npc->vida);	
}
	