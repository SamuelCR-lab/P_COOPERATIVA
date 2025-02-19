#include <stdio.h>
#include <stdlib.h>

typedef struct{
	char nombre[50];
	int vida;
	int vidaActual;
	int ataque;
	int velocidad;
	int monedas;
}Dragon;

void CrearMushu(Dragon * Mushu);
void CrearShenlong(Dragon * Shenlong);
void CrearBalerion(Dragon * Balerion);
void CrearCharizard(Dragon * Charizard);
int dificultad();