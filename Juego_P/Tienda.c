#include <stdio.h>
#include <stdlib.h>
#include "textos.h"
#include "caballero.h"

void mejorar_stats(Caballero * stats){
	int eleccion,errores;
	printf("Tienes %d monedas\n",stats->monedas);
	printf("\tTras la lucha tu caballero %s tiene estas estadísticas:\n\tSalud = %d\n\tAtaque = %d\n\tVelocidad = %d\n\n",stats->alias,stats->vida,stats->ataque,stats->velocidad);
	printf("%s",TIENDA);
	printf("%s",POCION);
	printf("%s",BOTAS);
	printf("%s",ARCO);
	printf("%s",ESPADA);
	printf("%s",HACHA);
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
			stats->monedas -=15;
			break;
		case 2:
			printf("%s",BOTAS_lore);
			stats->velocidad += 3;
			stats->monedas -=25;
			break;
		case 3:
			printf("%s",ESPADA_lore);
			stats->ataque += 10;
			stats->monedas -=35;
			break;
		case 4:
			printf("%s",HACHA_lore);
			stats->ataque += 15;
			stats->monedas -=45;
			break;
		case 5:
			printf("%s",ARCO_lore);
			stats->ataque += 5;
			stats->monedas -=25;
			break;
		default:
			break;
	}
}
