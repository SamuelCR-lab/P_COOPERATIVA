#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "caballero.h"

// Pasamos los Caballeros por referencia, que sera copiado en la reserva de memoria
// del main, así, cualquier cambio solo se vera reflejado en la copia que hagamos 
// del caballero en el malloc del main.

void CrearBoromir(Caballero* Boromir){
	strcpy(Boromir->nombre,"Boromir");
	Boromir->vida =  55;
	Boromir->ataque = 27;
	Boromir->velocidad = 18;
}
void CrearLa_Montana(Caballero* La_Montana){
	strcpy(La_Montana->nombre,"La_Montaña");
	La_Montana->vida =  50;
	La_Montana->ataque = 47;
	La_Montana->velocidad = 12;
}
void CrearEl_Cid(Caballero* El_Cid){
	strcpy(El_Cid->nombre,"El_Cid");
	El_Cid->vida =  58;
	El_Cid->ataque = 35;
	El_Cid->velocidad = 15; 
}

