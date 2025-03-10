#include <stdio.h>
#include <stdlib.h>
#include "textos.h"
#include "caballero.h"

void mejorar_stats(Caballero * stats){
	int eleccion,errores;
	//system("clear");
	system("cat < Tienda.txt");
	printf("Tienes %d monedas de oro\n\n",stats->monedas);
	printf("\tTras la lucha tu caballero %s tiene estas estadísticas:\n\tSalud = %d/%d\n\tAtaque = %d\n\tVelocidad = %d\n\n",stats->alias,stats->vidaActual,stats->vida,stats->ataque,stats->velocidad);
	printf("%s",TIENDA);
	printf("%s",POCION);
	printf("%s",BOTAS);
	printf("%s",ESPADA);
	printf("%s",HACHA);
	printf("%s",ARCO);
	printf("%s",SALIR_TIENDA);
	do{
		printf("Opción: ");
		errores = scanf(" %d",&eleccion);
		if(errores == 0){
			printf("Has elegido mal\n");
			char buffer[50]; 
			scanf("%s",buffer);
			eleccion = 7;
		}
		switch(eleccion){
			case 1:
				printf("%s",POCION_lore);
				if (stats->monedas < 15){
					printf("%s",POBREZA);
					break;
				}else{
					stats->vidaActual += 20;
					if (stats->vidaActual > stats->vida){
						stats->vida = stats->vidaActual;
					}
					stats->monedas -=15;
					printf("La pocion te ha aumentado 20 de salud y ahora tu salud es = %d\n\n",stats->vidaActual);
					printf("La pocion te ha costado 15 monedas y ahora tu riqueza se remonta a %d monedas de oro\n\n",stats->monedas);
					break;
				}
				break;
			case 2:
				printf("%s\n",BOTAS_lore);
				
				if (stats->monedas < 25){
					printf("%s",POBREZA);
					break;
				}else{
					stats->velocidad += 3;
					stats->monedas -=25;
					printf("Las botas te ha aumentado 3 de velocidad y ahora tu velocidad es = %d\n\n",stats->velocidad);
					printf("Las botas te ha costado 25 monedas y ahora tu riqueza se remonta a %d monedas de oro\n\n",stats->monedas);
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
					printf("La espada te ha costado 35 monedas y ahora tu riqueza se remonta a %d monedas de oro\n\n",stats->monedas);
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
					printf("El hacha te ha costado 45 monedas y ahora tu riqueza se remonta a %d monedas de oro\n\n",stats->monedas);
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
					printf("El arco te ha aumentado 5 en ataque y ahora tu ataque es = %d\n\n",stats->ataque);
					printf("El arco te ha costado 25 monedas y ahora tu riqueza se remonta a %d monedas de oro\n\n",stats->monedas);
					break;
				}
			case 6:
				printf("Que tengas buena suerte, valiente caballero nos volveremos a ver mas pronto que tarde...\n\n");
				break;
			default:
				break;
		}
	}while (eleccion != 6);

}

void tienda_inframundo(Caballero * stats){
	int eleccion,errores;
	//system("clear");
	system("cat < Tienda_inframundo.txt");
	// TODO: lore tienda
	printf("\tTras la lucha tu caballero %s tiene estas estadísticas:\n\tSalud = %d/%d\n\tAtaque = %d\n\tVelocidad = %d\n\n",stats->alias,stats->vidaActual,stats->vida,stats->ataque,stats->velocidad);
	
	printf("%s",ALMA1);
	printf("%s",ALMA2);
	printf("%s",ALMA3);
	do{
		printf("Opción: ");
		errores = scanf(" %d",&eleccion);
		if(errores == 0){
			printf("Has elegindo mal\n");
			char buffer[50]; 
			scanf("%s",buffer);
			eleccion = 5;
		}
		switch(eleccion){
			case 1:
					stats->ataque -= 5;
					stats->velocidad -= 5;
				if (stats->ataque < 0 || stats->velocidad < 0){
					printf("No puedes comprar esta alma\n");
					eleccion=0; // Lo igualo a 0 para que se repita el bucle
					stats->ataque += 5;
					stats->velocidad += 5;
				} else {
					stats->vidaActual += 20;
					if (stats->vidaActual > stats->vida){
						stats->vida = stats->vidaActual;
					}
					printf("%s",ALMA1_lore);
					printf("La pocion te ha aumentado 20 de salud y ahora tu salud es = %d\n\n",stats->vidaActual);
				}
				break;
			case 2:
					stats->ataque -= 10;
					stats->velocidad -= 7;
				if (stats->ataque < 0 || stats->velocidad < 0){
					printf("No puedes comprar esta alma\n");
					eleccion=0; // Lo igualo a 0 para que se repita el bucle
					stats->ataque += 10;
					stats->velocidad += 7;
				} else {
					stats->vidaActual += 50;
					if (stats->vidaActual > stats->vida){
						stats->vida = stats->vidaActual;
					}
					printf("%s",ALMA2_lore);
					printf("La pocion te ha aumentado 50 de salud y ahora tu salud es = %d\n\n",stats->vidaActual);
				}
				break;
			case 3:
				stats->ataque -= 15;
				stats->velocidad -= 9;
				if (stats->ataque < 0 || stats->velocidad < 0){
					printf("No puedes comprar esta alma\n");
					eleccion=0; // Lo igualo a 0 para que se repita el bucle
					stats->ataque += 15;
					stats->velocidad += 9;
				} else {
					stats->vidaActual += 120;
					if (stats->vidaActual > stats->vida){
						stats->vida = stats->vidaActual;
					}
					printf("%s",ALMA3_lore);
					printf("La pocion te ha aumentado 120 de salud y ahora tu salud es = %d\n\n",stats->vidaActual);
				}
				break;
			default:
				printf("Escribe 1, 2 o 3 porque si no, te quedas sin salud\n");
				break;
		}
	}while(eleccion < 1 || eleccion > 3);
}