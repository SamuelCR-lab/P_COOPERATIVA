#include <stdio.h>
#include <stdlib.h>


typedef struct{
	char nombre[50];
	int vida;
	int ataque;
	int velocidad;
}Caballero;

void CrearBoromir(Caballero* Boromir);
void CrearLa_Montana(Caballero* La_Montana);
void CrearEl_Cid(Caballero* El_Cid);
void mejorar_stats(Caballero * stats, int * monedas);
void batalla(Cabllero * jugador, Dragon * npc);
