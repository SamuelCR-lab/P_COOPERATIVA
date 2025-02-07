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
	fgets(palindromo, 100, stdin);//copiamos la cadena de enteras de caracteres de con el fgets en la variable palindromo 
	if(comprobar_palindromo(palindromo, strlen(palindromo)-1, 1)){//En este if comprobamos si es un palindromo mediante la función
		printf("Se puede leer del derecho y del revés!\n");
	} else {
		printf("No se puede leer del derecho y del revés\n");
	}
	return 0;
}
//Función de comprobar palindromo que recibe una direccion de memoria a una cadena, la longitud de la cadena y un variable i necesaria para la recursividad
int comprobar_palindromo(char * string, int longitud, int i){
	char ini = string[0];//Igualamos el primer caracter de la cadena string dada por referencia a una variable ini que es de tipo char para que solo sea el primer caracter
	char fin = string[longitud-i];//Igualamos el ultimo caracter de la cadena string dada por referencia a un variable fin
	if(longitud/2 <= 2){//Esta confirmacion se realiza para que cuando se haga la recursividad si la longitud es menor o igual a 2 entre y haga la comparacion final.
		if(ini == fin){//Condición que iguala los ultimos dos caracteres que guadamos anteriormente  
			return 1;//Si la condicion final se cumple devuelve 1 que en el main hacemos que se cumpla la condición
		} else {
			return 0;//Devuelve a main que si no se cumple hace que no se pueda leer del derecho del reves
		}	
	}

	if(ini == fin){//Los dos caracteres si son iguales se cumplen por lo que llamamos a la funcion recursivamente
		return comprobar_palindromo(&string[1], --longitud, ++i);
	} else {//Se le de este if si no es así
		return 0;
	}
	return 0;//Devuelve a main que si no se cumple hace que no se pueda leer del derecho del reves
}
