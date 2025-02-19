#include <stdio.h>
#include <stdlib.h>
#include "textos.h"
#include "caballero.h"

void mejorar_stats(Caballero * stats){
	int eleccion,errores;
	printf("Tienes %d monedas de oro\n\n",stats->monedas);
	printf("\tTras la lucha tu caballero %s tiene estas estadísticas:\n\tSalud = %d\n\tAtaque = %d\n\tVelocidad = %d\n\n",stats->alias,stats->vidaActual,stats->ataque,stats->velocidad);
	printf("%s",TIENDA);
	printf("%s",POCION);
	printf("%s",BOTAS);
	printf("%s",ARCO);
	printf("%s",ESPADA);
	printf("%s",HACHA);
	printf("%s",SALIR_TIENDA);
	printf("Opción: \n");
	errores = scanf(" %d",&eleccion);
	if(errores == 0){
		printf("Has elegindo mal\n");
	}
	switch(eleccion){
		case 1:
			printf("%s",POCION_lore);
			if (stats->monedas < 15){
				printf("%s",POBREZA);
				break;
			}else{
				stats->vidaActual += 20;
				stats->monedas -=15;
				printf("La pocion te ha aumentado 20 de salud y ahora tu salud es = %d\n\n",stats->vidaActual);
				printf("La pocion te ha costado 15 monedas y ahora tu riqueza se remonta a %d monedas de oro\n\n",stats->monedas);
				break;
			}
			
		case 2:
			printf("%s\n",BOTAS_lore);
			
			if (stats->monedas < 25){
				printf("%s",POBREZA);
				break;
			}else{
				stats->velocidad += 3;
				stats->monedas -=25;
				printf("Las botas te ha aumentado 3 de velocidad y ahora tu velocidad es = %d\n\n",stats->velocidad);
				printf("La pocion te ha costado 25 monedas y ahora tu riqueza se remonta a %d monedas de oro\n\n",stats->monedas);
				break;
			}
			
		case 3:
			printf("%s\n",ESPADA_lore);
			if (stats->monedas < 35){
				printf("%s",POBREZA);
				break;
			}else{
				stats->ataque += 10;
				stats->monedas -=35;
				printf("La espada te ha aumentado 10 de ataque y ahora tu ataque es = %d\n\n",stats->ataque);
				printf("La pocion te ha costado 35 monedas y ahora tu riqueza se remonta a %d monedas de oro\n\n",stats->monedas);
				break;
			}
		case 4:
			printf("%s\n",HACHA_lore);
			if (stats->monedas < 45){
				printf("%s",POBREZA);
				break;
			}else{
				stats->ataque += 15;
				stats->monedas -=45;
				printf("El hacha te ha aumentado 15 en ataque y ahora tu ataque es = %d\n\n",stats->ataque);
				printf("La pocion te ha costado 45 monedas y ahora tu riqueza se remonta a %d monedas de oro\n\n",stats->monedas);
				break;
			}
		case 5:
			printf("%s\n",ARCO_lore);
			if (stats->monedas < 25){
				printf("%s",POBREZA);
				break;
			}else{
				stats->ataque += 5;
				stats->monedas -=25;
				printf("El hacha te ha aumentado 5 en ataque y ahora tu ataque es = %d\n\n",stats->ataque);
				printf("La pocion te ha costado 25 monedas y ahora tu riqueza se remonta a %d monedas de oro\n\n",stats->monedas);
				break;
			}
		default:
			break;
	}
}
