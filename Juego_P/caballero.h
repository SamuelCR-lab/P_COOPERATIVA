#include <stdio.h>
#include <stdlib.h>


typedef struct{
	char alias[20];
	int vida;
	int daño;
	int velocidad;
}Caballero

Caballero * inicializar();