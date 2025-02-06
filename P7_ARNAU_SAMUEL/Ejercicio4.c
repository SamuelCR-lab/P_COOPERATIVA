#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
	Trabajo realizado por Arnau y Samuel
*/

int comprobar_palindromo(char * string, int longitud, int i);

int main(){
	char palindromo[100];
	printf("Escribe una palablra/frase: ");
	scanf(" ");
	fgets(palindromo, 100, stdin);
	if(comprobar_palindromo(palindromo, strlen(palindromo)-1, 1)){
		printf("Se puede leer del derecho y del revés!\n");
	} else {
		printf("No se puede leer del derecho y del revés\n");
	}
	return 0;
}

int comprobar_palindromo(char * string, int longitud, int i){
	char ini = string[0];
	char fin = string[longitud-i];
	if(longitud/2 <= 2){
		if(ini == fin){
			return 1;
		} else {
			return 0;
		}	
	}

	if(ini == fin){
		return comprobar_palindromo(&string[1], --longitud, ++i);
	} else {
		return 0;
	}
	return 0;
}
