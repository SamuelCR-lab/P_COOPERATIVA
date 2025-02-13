#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "dragon.h"

// Pasamos los dragones por referencia, que seran copiados en la reserva
// de memoria dinámica del main, lo cual cualquier cambio solo se vera afectado 
// en la copia que haremos de los dragones en el malloc.

Dragon* CrearMushu(Dragon* Mushu){
	strcpy(Mushu->nombre,"Mushu");
	Mushu->vida =  60;
	Mushu->ataque = 25;
	Mushu->velocidad = 10;
	return Mushu;
}

Dragon* CrearShenlong(Dragon* Shenlong){
	strcpy(Shenlong->nombre,"Shenlong");
	Shenlong->vida =  70;
	Shenlong->ataque = 50;
	Shenlong->velocidad = 13;
	return Shenlong;
}

Dragon* CrearBalerion(Dragon* Balerion){
	strcpy(Balerion->nombre,"Balerion");
	Balerion->vida =  85;
	Balerion->ataque = 72;
	Balerion->velocidad = 16;
	return Balerion;
}

Dragon* CrearCahrizar(Dragon* Charizar){
    strcpy(Charizar->nombre, "Charizar");
    Charizar->vida = 120;
    Charizar->ataque = 100;
    Charizar->velocidad = 20;
    return Charizar;
}

