#include <stdio.h>
#include <stdlib.h>
/*
	Trabajo realizado por Arnau y Samuel
*/

void ajustar_tamanio(int ** puntero_a_puntero, int tamanio);
void intercambiarValores(int * primero, int * numero_m);
int * encontrar_menor(int * numero1, int cantidad_num);

int main(){
	int exit;
	int vueltas = 0;
	int * numeros; 
	int * num_menor;
	printf("Escribe cuantos numeros quieras y escribe exit para salir\n");
	numeros = (int *) malloc(sizeof(int));//creamos una reserva de memoria que vamos a agregar un espacio cada vez que se introduce un número.
	do{
		vueltas++;
		ajustar_tamanio(&numeros, vueltas);
		numeros = (int *) realloc(numeros, vueltas * sizeof(int));
		exit = scanf(" %d", &numeros[vueltas-1]);
	}while(exit != 0);
	vueltas	-= 1;
	for(int i = 0; i < vueltas; i++){
		num_menor = encontrar_menor(&numeros[i], vueltas-i);
		intercambiarValores(&numeros[i], num_menor);
		printf("%d ", numeros[i]);
	}
	printf("\n");
	free(numeros);
	return 0;
}
//Función para hacer el realloc para ajustar la memoria por cada valor ingresado 
void ajustar_tamanio(int ** puntero_a_puntero, int tamanio){
	*puntero_a_puntero = (int *) realloc(*puntero_a_puntero,tamanio * sizeof(int));
	if(*puntero_a_puntero == NULL) return;
}
//Función que después de haber pasado por la función encontrar menor lo intercambiamos en esta funcion 
void intercambiarValores(int * primero, int * numero_m){
	int posicion = *primero;
	*primero = *numero_m;
	*numero_m = posicion;
}
//función para el número menor de los introducidos por el usuario 
int * encontrar_menor(int * numero1, int cantidad_num){
	int * menor = &numero1[0];//menor guarda el primer número de los que tenemos guardados, por ello, dentro del siguiente bucle for haremos la comparacion con cada número del almacenamiento
	for (int i = 1; i < cantidad_num; i++){
		if (*menor > numero1[i]){
			menor = &numero1[i];
		}
	}
	return menor;//retornamos este numero que obtuvismo a la primera posicion
}