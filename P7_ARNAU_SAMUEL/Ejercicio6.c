#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
	Trabajo realizado por Arnau y Samuel
*/

char cifrado_cesar(char frase, int saltos);

int main(){
	int cifrado;
	char frase[1000];
	int lon_frase;
	printf("Introduce una frase a cifrar: ");
	scanf(" %[^\n]",frase);
	lon_frase = strlen(frase);

	char * arr= (char*) malloc(lon_frase*sizeof(char));
	if(arr == NULL) return 0;

	for (int i = 0; i <= lon_frase; i++){
		arr[i] = frase[i];
	}

	printf("Introduce cuanto quieres el desplazamiento para el cifrado cesar: ");
	scanf("%d",&cifrado);
	for (int i = 0; i < lon_frase; i++){
		arr[i] = cifrado_cesar((char)*(arr+i), cifrado);	
	}

	printf("La frase '%s' antes de cifrar\nLa frase '%s' después de cifrar\n", frase, arr);

	return 0;
}

char cifrado_cesar(char frase, int saltos){
	int letras_saltar = 0;
	letras_saltar = frase;
	if(frase >= 65 && frase <= 90){
		letras_saltar = (letras_saltar - 13 + saltos) % 26;
		letras_saltar = letras_saltar + 65;
	} else if(frase >= 97 && frase <= 122){
		letras_saltar = (letras_saltar - 19 + saltos) % 26;
		letras_saltar = letras_saltar + 97;
	}
	frase = letras_saltar;
	return frase;
}
