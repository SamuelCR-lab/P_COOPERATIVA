#include <stdio.h>
#include <stdlib.h>


typedef struct{
	char nombre[50];
	int vida;
	int ataque;
	int velocidad;
}Dragon;

void CrearMushu(Dragon * Mushu);
void CrearShenlong(Dragon * Shenlong);
void CrearBalerion(Dragon * Balerion);
void CrearCharizar(Dragon * Charizar);
void batalla(Cabllero * jugador, Dragon * npc);