#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <unistd.h>
#include "dragon.h"
#include "caballero.h"
#include "colors.h"

// Pasamos los dragones por referencia, que seran copiados en la reserva
// de memoria dinámica del main, lo cual cualquier cambio solo se vera afectado 
// en la copia que haremos de los dragones en el malloc.

void CrearMushu(Dragon * Mushu){
	strcpy(Mushu->nombre,"Mushu");
	Mushu->vida =  60;
	Mushu->vidaActual = 60;
	Mushu->ataque = 25;
	Mushu->velocidad = 10;
	Mushu->monedas = 20;
}

void CrearShenlong(Dragon * Shenlong){
	strcpy(Shenlong->nombre,"Shenlong");
	Shenlong->vida =  70;
	Shenlong->vidaActual = 70;
	Shenlong->ataque = 50;
	Shenlong->velocidad = 13;
	Shenlong->monedas = 40;
}

void CrearBalerion(Dragon * Balerion){
	strcpy(Balerion->nombre,"Balerion");
	Balerion->vida =  85;
	Balerion->vidaActual = 85;
	Balerion->ataque = 72;
	Balerion->velocidad = 16;
	Balerion->monedas = 80;
}

void CrearCharizard(Dragon * Charizard){
    strcpy(Charizard->nombre, "Charizard");
    Charizard->vida = 120;
	Charizard->vidaActual = 120;
    Charizard->ataque = 100;
    Charizard->velocidad = 20;
	Charizard->monedas = 0;
}
// Funcion del ataque del Dragón.
/**
	Se consideran ataques criticos, que se le sumará al básico del presonaje.
	Restara el total del ataque a la vida del contrincante.
**/
void ataqueDragon(Caballero * jugador, Dragon * npc){ // Necesitamos que se pase por referencia para que la vida se reste y se vea reflejado en la batalla
	int critico = 0; // Inicializo critico a 0
	int randomCri = rand() % 10;
    if (randomCri == 3){
    	printf("El dragón ha hecho un ataque crítico!!\n");
    	critico = npc->ataque;
        critico /= 5;
    }
    jugador->vidaActual -= npc->ataque + critico;
    sleep(1);
    printf("\tEl dragon %s, ataca al caballero %s\n",npc->nombre, jugador->alias);
    if (strcmp(npc->nombre, "Mushu")==0){
  		printf(RED"\n"); // TODO: Asignar las estadísticas a cada dragón.
	 	system("cat < Mushu.txt");
	 	printf(WHITE "\n");
    }else if (strcmp(npc->nombre, "Shenlong")==0){
    	printf(GREEN"\n");
	 	system("cat < Shenlong.txt");
		printf(WHITE "\n");
    }else if (strcmp(npc->nombre, "Balerion")==0){
    	printf(MAGENTA"\n");
	 	system("cat < Balerion.txt");
	 	printf(WHITE "\n");
    }else if (strcmp(npc->nombre, "Charizard")==0){
    	printf(ORANGE"\n");
	 	system("cat < Charizard.txt");
	 	printf(WHITE "\n");
    }

    if(jugador->vidaActual < 0){
    	jugador->vidaActual = 0;
    }
    printf("\tSalud de %s: %d / %d\n", jugador->alias, jugador->vidaActual, jugador->vida);

}
