#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <unistd.h>
#include "dragon.h"
#include "caballero.h"

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
	Balerion->vidaActual = 55;
	Balerion->ataque = 72;
	Balerion->velocidad = 16;
	Balerion->monedas = 80;
}

void CrearCharizard(Dragon * Charizard){
    strcpy(Charizard->nombre, "Charizard");
    Charizard->vida = 120;
	Charizard->vidaActual = 55;
    Charizard->ataque = 100;
    Charizard->velocidad = 20;
	Charizard->monedas = 0;
}
void ataqueDragon(Caballero * jugador, Dragon * npc){ // Necesitamos que se pase por referencia para que la vida se reste y se vea reflejado en la batalla
	int critico;
	int randomCri = rand() % 10;
	int critico;
    if (randomCri == 3){
    	printf("El dragón ha hecho un ataque crítico!!\n");
    	critico = npc->ataque;
        critico /= 5;
    }
    jugador->vidaActual -= npc->ataque + critico;
    sleep(1);
    printf("\tEl dragon %s, ataca al caballero %s\n",npc->nombre, jugador->nombre);
    if (strcmp(npc->nombre, "Mushu")==0){
    	system("cat < Mushu.txt");
    }else if (strcmp(npc->nombre, "Shenlong")==0){
    	system("cat < Shenlong.txt");
    }else if (strcmp(npc->nombre, "Balerion")==0){
    	system("cat < Balerion.txt");
    }else if (strcmp(npc->nombre, "Charizard")==0){
    	system("cat < Charizard.txt");
    }
    printf("\tSalud de %s: %d / %d\n", jugador->alias, jugador->vidaActual, jugador->vida);
}
