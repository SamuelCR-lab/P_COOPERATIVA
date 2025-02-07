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
	scanf(" %[^\n]",frase);//Guarda la frase con espacios tambien
	lon_frase = strlen(frase);//strlen cuenta cuantas letras hay en la frase que guadamos

	char * arr= (char*) malloc(lon_frase*sizeof(char));//Reservamos memoria para la cantidad de caracteras que conto el strlen que se guarda en long_frase
	if(arr == NULL) return 0;

	for (int i = 0; i <= lon_frase; i++){
		arr[i] = frase[i];//se guarda cada caracter de la frase en la memoria reservada para caracteres que accedemos a el con frase[i].
	}

	printf("Introduce cuanto quieres el desplazamiento para el cifrado cesar: ");
	scanf("%d",&cifrado);
	for (int i = 0; i < lon_frase; i++){//En este bucle llamamos a la funcion cifrado para que dandole un caracter y cuantos caracteres quiere el autobus saltar
		arr[i] = cifrado_cesar((char)*(arr+i), cifrado);	
	}

	printf("La frase '%s' antes de cifrar\nLa frase '%s' después de cifrar\n", frase, arr);

	return 0;
}

char cifrado_cesar(char frase, int saltos){
	int letras_saltar = 0;
	letras_saltar = frase;//Igualamos cada caracter recibido para convertirlo en un entero que podamos encriptar
	if(frase >= 65 && frase <= 90){//Comparamos el caracter dentro de la tabla ascii para saber si es una letra mayúscula
		letras_saltar = (letras_saltar - 13 + saltos) % 26;//Mediante este calculo obtendremos la de letras que necesitamos saltar o retroceder para que se permitan saltos negativos o mayores a 26 en el cifrado.
		letras_saltar = letras_saltar + 65;//Esta ultima suma es para obtener el digito necesario

	} else if(frase >= 97 && frase <= 122){//Comparamos el caracter dentro de la tabla ascii para saber si es una letra minúscula
		letras_saltar = (letras_saltar - 19 + saltos) % 26;//Mediante este calculo obtendremos la de letras que necesitamos saltar o retroceder para que se permitan saltos negativos o mayores a 26 en el cifrado.
		letras_saltar = letras_saltar + 97;//Esta ultima suma es para obtener el digito necesario
	}
	frase = letras_saltar;
	return frase;//Devolvemos la frase osea el digito que vamos a intercambiar
}
