#include <stdio.h>
#include <stdlib.h>
#include "caballero.h"
#include "dragon.h"


#define BUFFER 50
#define NOMBRE_MAX 100
#define MAX_DRAGONES 4



int menu();
int batalla(Caballero * jugador, Dragon npc);
void ataqueCaballero(Caballero* jugador, Dragon* npc);
void ataqueDragon(Caballero * jugador, Dragon * npc);
void tienda_inframundo(Caballero * stats);
