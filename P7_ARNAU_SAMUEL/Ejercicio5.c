#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
	Trabajo realizado por Arnau y Samuel
*/

void matriz_rellena(int ** matriz_n,int n,int m);
void mostrar_matriz(int ** mostrar,int n,int m);
void mostrar_matriz(int ** mostrar,int n,int m);
void suma_contorno(int ** contornos,int n,int m, int reinicio);

int main(){
	int n,m;//n son las filas de la matriz y m son las columnas 
	printf("Introduce las filas que quieres que tenga una matriz: ");
	scanf(" %d",&n);
	printf("Introduce las columnas que quieres que tenga una matriz: ");
	scanf(" %d",&m);
	int ** matriz = (int**) malloc(n * sizeof(int*));//Creamos un array de arrays o lo que es una reserva de memoria llamada matriz, que es un puntero doble de tipo doble puntero y el malloc que se multiplica por el tamaño de un puntero a entero que es lo que sera el interior de matriz, varios puntero a enteros que son memoria reservada para guardar los números 
	if(matriz == NULL) return 1;
	for (int i = 0; i < n; i++){
		matriz[i] = (int*) malloc (m * sizeof(int));
		if(matriz[i] == NULL) return 1;
	}
	matriz_rellena(matriz,n,m);
	mostrar_matriz(matriz,n,m);
	printf("La suma del contorno.\n");
	suma_contorno(matriz,n,m,0);
	for (int i = 0; i < n; i++){
		free(matriz[i]);
	}
	free(matriz);
return 0;
}
//Función para rellenar la matriz con números aleatorios
void matriz_rellena(int ** matriz_nm,int n,int m){//Recibe la direccion de memoria reservada, la variable n que es el número de filas y m es el número de columnas para poder rellenar cada uno de los valores sin problema 
	int r = 0;
	srand(time(NULL));
	for (int i = 0; i < n; i++){//Hay que hacer dos bucles para aignar valores hasta el número de filas n-1 y el número de columnas m-1
		for(int j = 0; j < m; j++){
			r = rand() % 9;
			matriz_nm[i][j] = r+1;
		}
	}
}
//Función para mostrar la matriz 
void mostrar_matriz(int ** mostrar,int n,int m){
	for (int i = 0; i < n; i++){//Hay que hacer dos bucles para mostrar los valores hasta el número de filas n-1 y el número de columnas m-1 
		for(int j = 0; j < m; j++){
			if (j == 0){//Esta condición como la siguiente del j == m-1, esta hecha para que los digitos cuando se expresen en pantalla sean lo más parecido a un una matriz  
				printf("( %d", mostrar[i][j]);
			}else if (j == m-1){
				printf("%d )\n", mostrar[i][j]);
			}else{
				printf("%d", mostrar[i][j]);
			}
		}
	}
}
//Función de suma de los contornos recibe matriz que es array de arrays asi que 
void suma_contorno(int ** contornos,int n,int m, int reinicio){//recibe esta variable reinicio para que se pueda hacer la recursión correctamente
	int suma_primera = 0;
	int suma_ultima = 0;
	if (reinicio == 0){
		for(int i = 0; i < m; i++){//Este bucle que tiene como condición llegar hasta uno menos que el número de columnas porque determina cada uno de los digitos guadados
			suma_primera += contornos[0][i];//Igualamos a 0, los primero corchetes que se refieren a los al primer puntero osea el numero de filas y como solo queremos la primera fila para realizar la suma del contorno correcta. Y para acceder a los digitos de la fila que almacena siendo esto menor al numero de columnas (m), accedemos a ellos mediante el segundo corchete y la i.
			suma_ultima += contornos[n-1][i];//Igualamos a la n-1 que es la ultima fila, ... explicado en la anterior linea
		}
		printf("La suma de la primera fila de la matriz = %d\n", suma_primera);
		printf("La suma de la ultima fila de la matriz = %d\n", suma_ultima);
		suma_contorno(contornos,n,m,reinicio+1);
	}else{
		for(int i = 0; i < n; i++){
			suma_primera += contornos[i][0];//Igualamos a 0, los segundos corchetes que se refieren a los al segundo puntero osea el numero de columnas y como solo queremos la primera columna para realizar la suma del contorno correcta. Y para acceder a los digitos de la columna que almacena siendo estos menor al numero de filas (n), accedemos a ellos mediante el primer corchete y la i.
			suma_ultima += contornos[i][m-1];//Igualamos a la m-1 que es la ultima columna, ... explicado en la anterior linea
		}
		printf("La suma de la primera columna de la matriz = %d\n", suma_primera);
		printf("La suma de la ultima columna de la matriz = %d\n", suma_ultima);
	}
}
