#include <stdio.h>
#include <stdlib.h>


typedef struct{
	char nombre[50];
	int vida;
	int ataque;
	int velocidad;
}Caballero;

// Declaraciones de las funciones
Caballero* CrearBoromir(Caballero* Boromir);
Caballero* CrearLa_Montana(Caballero* La_Montana);
Caballero* CrearEl_Cid(Caballero* El_Cid);
