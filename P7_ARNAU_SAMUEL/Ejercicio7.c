#include <stdio.h>
#include <stdlib.h>

void array(int m);
int primos_totales(int m);
void guardado_primos(int * primos_a_guardar, int m);
void mostrar(int * mostar_array, int n);

int main(){
	int m, primos;
	int * arr_primos;
	printf("Introduce un número cualquiera: ");
	scanf(" %d",&m);

	primos = primos_totales(m);
	arr_primos = (int*) malloc(primos * sizeof(int));

	if(arr_primos == NULL) return 1;

	guardado_primos(arr_primos, m);
	printf("Los primos encontrados hasta el número %d\n",m);
	mostrar(arr_primos, primos); 

	free(arr_primos);
return 0;
}

int primos_totales(int m){
	int primos_encontrados = 0;
	for(int i = 2; i <= m ; i++){
		int busqueda_primos = 1;
		for(int j = 2; j < i; j++){
			if (i % j == 0){
				busqueda_primos = 0;
				break;
			}
		}
		if (busqueda_primos == 1){
			primos_encontrados++;
		}
	}
	return primos_encontrados;
}
void guardado_primos(int * primos_a_guardar, int m){
	int numeros_primos = 0;
	for(int i = 2; i <= m ; i++){
		int busqueda_primos = 1;
		for(int j = 2; j < i; j++){
			if (i % j == 0){
				busqueda_primos = 0;
				break;
			}
		}
		if (busqueda_primos == 1){
			primos_a_guardar[numeros_primos] = i;
			numeros_primos++;
		}
	}
}
void mostrar(int * mostar_array, int n){
	for(int i = 0; i < n; i++){
		printf("%d° numero primo = %d\n",i+1,mostar_array[i]);
	}
}
