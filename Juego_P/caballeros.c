#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "caballero.h"

// Pasamos los Caballeros por referencia, que sera copiado en la reserva de memoria
// del main, así, cualquier cambio solo se vera reflejado en la copia que hagamos 
// del caballero en el malloc del main.

void CrearBoromir(Caballero* Boromir, char* alias){
	strcpy(Boromir->nombre,"Boromir");
	strcpy(Boromir->alias, alias);
	Boromir->vida =  55;
	Boromir->vidaActual = 55;
	Boromir->ataque = 27;
	Boromir->velocidad = 18;
	Boromir->monedas = 0;
}
void CrearLa_Montana(Caballero* La_Montana, char* alias){
	strcpy(La_Montana->nombre,"La_Montaña");
	strcpy(La_Montana->alias, alias);
	La_Montana->vida =  50;
	La_Montana->vidaActual = 50;
	La_Montana->ataque = 47;
	La_Montana->velocidad = 12;
	La_Montana->monedas = 0;
}
void CrearEl_Cid(Caballero* El_Cid, char* alias){
	strcpy(El_Cid->nombre,"El_Cid");
	strcpy(El_Cid->alias, alias);
	El_Cid->vida =  58;
	El_Cid->vidaActual = 58;
	El_Cid->ataque = 35;
	El_Cid->velocidad = 15;
	El_Cid->monedas = 0; 
}
void ataqueCaballero(Caballero* jugador, Dragon* npc){
	randomCri = rand() % 8;
            if (randomCri == 1){
                critico = jugador->ataque;
                critico /= 3;
            }
            randomAtaque = rand() % 5; 
            npc->vidaActual -= jugador->ataque + critico + randomAtaque;
            sleep(2);
            printf("\tEl caballero %s ataca al dragon %s", jugador->nombre, npc->nombre);
            printf("\tSalud de %s: %d / %d totales", npc->nombre, npc->vidaActual, npc->vida);
}

