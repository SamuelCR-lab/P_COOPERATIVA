#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include "JuegoPrincipal.h"

// Pasamos los dragones por referencia, que seran copiados en la reserva
// de memoria dinámica del main, lo cual cualquier cambio solo se vera afectado 
// en la copia que haremos de los dragones en el malloc.

void CrearMushu(Dragon * Mushu){
	strcpy(Mushu->nombre,"Mushu");
	Mushu->vida =  60;
	Mushu->vidaActual = 60;
	Mushu->ataque = 25;
	Mushu->velocidad = 10;
}

void CrearShenlong(Dragon * Shenlong){
	strcpy(Shenlong->nombre,"Shenlong");
	Shenlong->vida =  70;
	Shenlong->vidaActual = 70;
	Shenlong->ataque = 50;
	Shenlong->velocidad = 13;
}

void CrearBalerion(Dragon * Balerion){
	strcpy(Balerion->nombre,"Balerion");
	Balerion->vida =  85;
	Balerion->vidaActual = 55;
	Balerion->ataque = 72;
	Balerion->velocidad = 16;
}

void CrearCharizar(Dragon * Charizar){
    strcpy(Charizar->nombre, "Charizar");
    Charizar->vida = 120;
	Charizar->vidaActual = 55;
    Charizar->ataque = 100;
    Charizar->velocidad = 20;
}
void ataqueDragon(Caballero * jugador, Dragon * npc){
	int critico;
	int randomCri = rand() % 10;
    if (randomCri == 3){
    	critico = npc->ataque;
        critico /= 5;
    }
    jugador->vidaActual -= npc->ataque + critico;
    sleep(2);
    printf("\tEl dragon %s, ataca al caballero %s",npc->nombre, jugador->nombre);
    printf("\tSalud de %s: %d / %d totales", jugador->nombre, jugador->vidaActual, jugador->vida);


}
