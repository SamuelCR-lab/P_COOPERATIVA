#include <stdio.h>
#include <stdlib.h>
#include "textos.h"
#include "caballero.h"

void mejorar_stats(Caballero * stats, int * monedas){
	int eleccion,errores;
	printf("Tienes %d monedas\n",*monedas);
	printf("\tTras la lucha tu caballero %s tiene estas estadísticas:\n\tSalud = %d\n\tAtaque = %d\n\tVelocidad = %d\n\n",stats->alias,stats->vida,stats->ataque,stats->velocidad);
	printf("%s",TIENDA);
	printf("%s",POCION);
	printf("%s",BOTAS);
	printf("%s",ESPADA);
	printf("%s",HACHA);
	printf("%s"ARCO);
	printf("%s",SALIR_TIENDA);
	printf("Opción: ");
	errores = scanf("%d",&eleccion);
	if(errores == 0){
		printf("Has elegindo mal\n");
	}
	switch(eleccion){
		case 1:
			printf("%s",POCION_lore);
			stats->vida += 20; 
			break;
		case 2:
			printf("%s",BOTAS_lore);
			stats->velocidad += 3;
			break;
		case 3:
			printf("%s",ESPADA_lore);
			stats->ataque += 10;
			break;
		case 4:
			printf("%s",HACHA_lore);
			stats->ataque += 15;
			break;
		case 5:
			printf("%s",ARCO_lore);
			stats->ataque += 5;
			break;
		default:
			break;
	}
}
