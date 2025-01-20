#include <stdio.h>
#include <stdlib.h>
/*
	Trabajo realizado por Arnau y Samuel
*/

/*void ajustar_tamanio(int ** x, int n){
	x = (int **) realloc(*x,n * sizeof(int));
}
*/
int main(){
	int exit;
	int vueltas = 0;
	int * numeros;
	printf("Escribe cuantos numeros quieras y escribe exit para salir\n");
	numeros = (int *) malloc(sizeof(int));
	do{
		vueltas++;
		//ajustar_tamanio(&numeros, vueltas);
		numeros = (int *) realloc(numeros, vueltas * sizeof(int));
		exit = scanf(" %d", &numeros[vueltas-1]);
	}while(exit != 0);
	
	free(numeros);
return 0;
}
