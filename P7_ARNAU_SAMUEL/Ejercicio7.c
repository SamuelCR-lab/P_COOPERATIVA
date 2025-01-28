#include <stdio.h>
#include <stdlib.h>

void array(int m);
int primos_totales(int m);
void guardado_primos(int * primos_a_guardar, int m);

int main(){
	int m, primos, arr;
	int * arr_primos;
	printf("Introduce un número cualquiera: ");
	scanf(" %d",&m);
	primos = primos_totales(m);
	arr_primos = (int*) malloc(primos * sizeof(int));
	if(arr_primos == NULL) return 1;
	guardado_primos(arr_primos, m); 
	free(arr_primos);
return 0;
}

int primos_totales(int m){
	int primos_encontrados,primos;

	for(int i = 0; i <= m ; i++){
		for(int j = 2; j <= i/2; j++){
			if (i % j == 0){
				primos_encontrados++;
			}
		}
	}
	return primos_encontrados;
}
void guardado_primos(int * primos_a_guardar, int m){
	int numeros_primos;
	for(int i = 0; i <= m ; i++){
		for(int j = 2; j <= i/2; j++){
			if (i % j != 0){
				primos_a_guardar[i] = i;
			}
		}
	}
}