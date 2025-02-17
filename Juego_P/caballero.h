#include <stdio.h>
#include <stdlib.h>


typedef struct{
	char nombre[50];
	char alias[50];
	int vida;
	int ataque;
	int velocidad;
}Caballero;


void CrearBoromir(Caballero* Boromir, char* alias);
void CrearLa_Montana(Caballero* La_Montana, char* alias);
void CrearEl_Cid(Caballero* El_Cid, char* alias);
void mejorar_stats(Caballero * stats, int * monedas);
int elegir_caballero(char ** nombre_c);

