#include <stdio.h>
#include <stdlib.h>
#include "caballeros.h"

// Pasamos los Caballeros por referencia, que sera copiado en la reserva de memoria
// del main, así, cualquier cambio solo se vera reflejado en la copia que hagamos 
// del caballero en el malloc del main.

Caballero* CrearBoromir(Caballero* Boromir){
	strcpy(Boromir->nombre,"Boromir");
	Boromir->vida =  55;
	Boromir->ataque = 27;
	Boromir->vleocidad = 18;
	return Boromir;
}
Caballero* CrearLa_Montana(Caballero* La_Montana){
	strcpy(La_Montaña->nombre,"La_Montaña");
	La_Montana->vida =  50;
	La_Montana->ataque = 47;
	La_Montana->vleocidad = 12;
	return La_Montaña;
}
Caballero* CrearEl_Cid(Caballero* El_Cid){
	strcpy(El_Cid->nombre,"El_Cid");
	El_Cid->vida =  58;
	El_Cid->ataque = 35;
	El_Cid->vleocidad = 15; 
	return El_Cid;
}

