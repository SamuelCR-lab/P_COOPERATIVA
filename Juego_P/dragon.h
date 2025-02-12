#include <stdio.h>
#include <stdlib.h>


typedef struct{
	char nombre[10];
	int vida;
	int daño;
	int velocidad;
}Dragon

Dragon * inicializar();