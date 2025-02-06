#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void cifrado_cesar(char * frase, int saltos);


int main(){
	int cifrado;
	char frase[1000];
	int lon_frase;
	printf("Introduce una frase a cifrar: ");
	scanf(" %[^\n]",frase);
	lon_frase = strlen(frase);
	lon_frase--;
	char * arr= (char*) malloc(lon_frase*sizeof(char));
	if(arr == NULL) return 0;
	for (int i = 0; i <= lon_frase; i++){
		arr[i] = frase[i];
	}

	printf("Introduce cuanto quieres el desplazamiento para el cifrado cesar: ");
	scanf("%d",&cifrado);
	for (int i = 0; i < lon_frase; i++){
		cifrado_cesar(&arr[i], cifrado);	
	}
	printf("La frase '%s' antes de cifrar\n La frase '%s' después de cifrar",frase,arr);


return 0;
}
void cifrado_cesar(char * frase, int saltos){
	int letras_saltar = 0;
	letras_saltar = frase;
	letras_saltar += saltos;
	frase = letras_saltar;
}
