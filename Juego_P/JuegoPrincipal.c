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
	while (errores == 0 || elegir < 1 || elegir > 3){
		printf("\tElige que caballero quieres ser: \n\n");
		printf(BLUE "\t1. LANCELOT\n"); 
		printf(RED "\t2. LA MONTAÑA\n");	
		printf(WHITE "\t3. CID\n");
		errores = scanf("%d",&elegir);
		printf("No has introducido un número o has introducido mas/menos de los caballeros que tenemos");
	}
	switch (elegir){
		case 1:
			printf("%s",CABALLERO1);
			break;
		case 2:
			printf("%s",CABALLERO2);
			break;
		default:
			printf("%s",CABALLERO3);
	}
	return elegir;

}
