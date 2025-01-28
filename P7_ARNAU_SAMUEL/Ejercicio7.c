#include <stdio.h>
#include <stdlib.h>

void array(int m);
void primos_encontrados(int m);

int main(){
	int m, primos, primos_encontrados;

	printf("Introduce un número cualquiera: ");
	scanf(" %d",&m);
	primos = primos_encontrados(m);
	int * arr = array(primos);
	guardado_primos(primos); 

return 0;
}
void array(int m){
	arr = (int*) malloc(m * sizeof(int));
	if(arr == NULL) return 1;
}
void primos_encontrados(int m){
	for(int i = 1; i = m ; i++){
		primos = i/i;
		if (primos = 1){
			primos_encontrados = primos + primos_encontrados;
		}
	}
}
void guardado_primos(int primos){
	for(int i = 1; i = m ; i++){
		primos = i/i;
}