#include <stdio.h>
#include <stdlib.h>
#include "Objetos.h"
#include "caballero.h"


void * mejorar_stats(Caballero ** stats, int * monedas){
	int eleccion,errores;
	printf("Tienes %d monedas",*monedas);
	printf("\tTras la lucha tu caballero %s tiene estas estadísticas: \n\tSalud = %d \n\tAtaque = %d \n\t Velocidad = %d\n\n",(*stats).nombre,(*stats).salud,(*stats).ataque,(*stats).velocidad);
	printf("%s",TIENDA);
	printf("\t1. Poción --> te incrementa la salud +20 --> por 15 monedas");
	printf("\t2. Botas --> te incrementa la velocidad +3,1 --> por 25 monedas");
	printf("\t3. Espada --> te incrementa el ataque +10 --> por 35 monedas");
	printf("\t4. Hacha --> te incrementa el ataque +15 --> por 45 monedas");
	printf("\t5. Arco --> te incrementa el ataque +5 --> por 25 monedas");
	printf("\t6. Salir");
	errores = scanf("%d",&eleccion);
	switch(eleccion){
		case 1:
			(*stats).salud += 20; 
			break;
		case 2:
			(*stats).velocidad += 3;
			break;
		case 3:
			(*stats).ataque += 10;
			break;
		case 4:
			(*stats).ataque += 15;
			break;
		case 5:
			(*stats).ataque += 5;
			break;
		default:
			break;
	}
}