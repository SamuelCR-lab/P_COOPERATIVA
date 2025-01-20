#include <stdio.h>
#include <stdlib.h>
/*
	Trabajo realizado por Arnau y Samuel
*/

void ajustar_tamanio(int ** puntero_a_puntero, int tamanio){
	*puntero_a_puntero = (int *) realloc(*puntero_a_puntero,tamanio * sizeof(int));
}
<<<<<<< HEAD

=======
*/
int encontrar_menor(int const * numero1, int n){
	int menor = numero1[0];
	for (int i = 1; i < n; i++){//
		if (menor > numero1[i]){
			menor = numero1[i];
		}
	}
	return menor;
}
>>>>>>> 065cf9627baff6ac31acaf3e5e7d22401e685b2e
int main(){
	int exit;
	int vueltas = 0;
	int * numeros;
	int * ordenados;
	printf("Escribe cuantos numeros quieras y escribe exit para salir\n");
	numeros = (int *) malloc(sizeof(int));
	do{
		vueltas++;
		ajustar_tamanio(&numeros, vueltas);
		//numeros = (int *) realloc(numeros, vueltas * sizeof(int));
		exit = scanf(" %d", &numeros[vueltas-1]);
	}while(exit != 0);
	ordenados = (int *) malloc(vueltas * sizeof(int));
	for(int i = 0; i < vueltas; i++){
	ordenados[i] = encontrar_menor(numeros, vueltas);
	}
	free(numeros);
return 0;
}
