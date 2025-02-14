#include <stdio.h>
#include <stdlib.h>
#include "Objetos.h"
#include "caballero.h"
#include "tienda.h"

void mejorar_stats(Caballero ** stats, int * monedas){
	int eleccion,errores;
	printf("Tienes %d monedas\n",*monedas);
	printf("\tTras la lucha tu caballero %s tiene estas estadísticas:\n\tSalud = %d\n\tAtaque = %d\n\t Velocidad = %d\n\n",(*stats)->nombre,(*stats)->vida,(*stats)->ataque,(*stats)->velocidad);
	printf("%s",TIENDA);
	printf("\t1. Poción --> te incrementa la vida +20 --> por 15 monedas\n");
	printf("\t2. Botas --> te incrementa la velocidad +3,1 --> por 25 monedas\n");
	printf("\t3. Espada --> te incrementa el ataque +10 --> por 35 monedas\n");
	printf("\t4. Hacha --> te incrementa el ataque +15 --> por 45 monedas\n");
	printf("\t5. Arco --> te incrementa el ataque +5 --> por 25 monedas\n");
	printf("\t6. Salir\n");
	printf("Opción: ");
	errores = scanf("%d",&eleccion);
	if(errores == 0){
		printf("Has elegindo mal\n");
	}
	switch(eleccion){
		case 1:
			printf("%s",POCION);
			(*stats)->vida += 20; 
			break;
		case 2:
			printf("%s",BOTAS);
			(*stats)->velocidad += 3;
			break;
		case 3:
			printf("%s",ESPADA);
			(*stats)->ataque += 10;
			break;
		case 4:
			printf("%s",HACHA);
			(*stats)->ataque += 15;
			break;
		case 5:
			printf("%s",ARCO);
			(*stats)->ataque += 5;
			break;
		default:
			break;
	}
}
