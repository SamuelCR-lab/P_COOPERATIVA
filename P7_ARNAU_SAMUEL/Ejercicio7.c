#include <stdio.h>
#include <stdlib.h>

/*
	Trabajo realizado por Arnau y Samuel
*/

void array(int m);
int primos_totales(int m);
void guardado_primos(int * primos_a_guardar, int m);
void mostrar(int * mostar_array, int n);

int main(){
	int m, primos;
	int * arr_primos;
	printf("Introduce un número cualquiera: ");
	scanf(" %d",&m);

	primos = primos_totales(m);//Buscamos los primos que se encuentran antes del número guadado en la variable m 
	arr_primos = (int*) malloc(primos * sizeof(int));//Despúes de obtener la cantidad de números primos que hay entre el 0 y el número dado  
	if(arr_primos == NULL) return 1;

	guardado_primos(arr_primos, m);
	printf("Los primos encontrados hasta el número %d\n",m);
	mostrar(arr_primos, primos);

	free(arr_primos);
return 0;
}

int primos_totales(int m){
	int primos_encontrados = 0;//Iniciamos a 0 un contador de números primos 
	for(int i = 2; i <= m ; i++){//Inicializamos la i en 2 porque es el primo que tenemos
		int busqueda_primos = 1;//Creamos y inicializamos a 1 una varible nueva que se llama busqueda_primos que es asumir que i es = a un primo
		for(int j = 2; j < i; j++){//Inicializamos la j en 2 porque es la primera comparacion que se debe hacer para saber si es primo, ya que es el primer número primo
			if (i % j == 0){//Hacemos una comparación y si el modulo es igual a 0 no es un número primo 
				busqueda_primos = 0;
				break;//Si entra en esta condicion sale al primer bucle
			}
		}
		if (busqueda_primos == 1){//Si se sale del segundo bucle sin que busqueda_primo sea 0 en esta condicion sumamos uno a primos
			primos_encontrados++;
		}
	}
	return primos_encontrados;//Se da la cantidad de primos obtenidos para poder hacer la reserva de memoria por ellos 
}
//Función que guarda cada primo 
void guardado_primos(int * primos_a_guardar, int m){
	int numeros_primos = 0;//Iniciamos a 0 un contador de números primos
	for(int i = 2; i <= m ; i++){//Este bucle es igual que en la funcion de buscarlos pero aqui los guardamos en el espacio reservado de memoria dado como direccion de memoria a primos_a_guardar siendo el número que guadamos igual que la variable i
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
//Función para mostrar el array de números 
void mostrar(int * mostar_array, int n){//La variable n son los números primos encontrados dede el 0 hasta el número ingresado por el usuario
	for(int i = 0; i < n; i++){//Bucle para mostrar cada uno de los números primos
		printf("%d° numero primo = %d\n",i+1,mostar_array[i]);
	}
}
