#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "colors.h"
#include "textos.h"

#define NOMBRE_MAX 100

int caballeros();

int main(){
	int eleccion;
	system("clear");
	printf("%s",TXT_INTRO_01);
	eleccion = caballeros();




	return 0;
}
int caballeros(){
	char nombre_c[NOMBRE_MAX];
	int elegir,errores;
	printf("\tQue nombre le quieres dar a tu caballero: ");
	scanf(" %[^\n]",nombre_c);
	printf("\tElige que caballero quieres ser: \n\n");
	printf(BLUE "\t1. LANCELOT\n"); 
	printf(RED "\t2. LA MONTAÑA\n");	
	printf(WHITE "\t3. CID\n");
	errores = scanf("%d",&elegir);
	if (errores == 0 || elegir < 1 || elegir > 3){
		printf("No has introducido un número o has introducido mas/menos de los caballeros que tenemos");
		return EXIT_FAILURE;
	}
	switch (elegir){
	case 1:
		printf("\t\tUn estratega nato y un líder inspirador, Cid es la imagen misma del honor y la caballería. ");
		printf("Nacido en una familia de nobles guerreros, su espada ha protegido Eldoria desde su juventud. ");
		printf("Maneja con destreza la espada y el escudo, equilibrando defensa y ataque con maestría.\n");
		printf("\t\tSe dice que su armadura brilla con un resplandor dorado en la batalla, y que su voz es capaz de alzar el ánimo de sus aliados incluso en los momentos más oscuros. ");
		printf("Sin embargo, Cid no solo lucha con acero, sino con su ingenio, siempre buscando el mejor camino para vencer sin caer en la brutalidad o la imprudencia.\n");
		printf("\t\tHabilidades: Balance perfecto entre ataque, defensa y agilidad. ");
		printf("Su liderazgo y estrategia lo convierten en el alma del equipo.\n");

	case 2:
		printf("");
	default:
		printf("");

	}
	return elegir;

}
