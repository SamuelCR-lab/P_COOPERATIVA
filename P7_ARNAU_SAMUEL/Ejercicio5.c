#include <stdio.h>
#include <stdlib.h>

/*
	Trabajo realizado por Arnau y Samuel
*/

void matriz_rellena(int ** matriz_n,int n,int m);
void mostrar_matriz(int ** mostrar,int n,int m);
void mostrar_matriz(int ** mostrar,int n,int m);
void suma_contorno(int ** contornos,int n,int m, int reinicio);

int main(){
	int n,m;
	printf("Introduce las filas que quieres que tenga una matriz: ");
	scanf(" %d",&n);
	printf("Introduce las columnas que quieres que tenga una matriz: ");
	scanf(" %d",&m);
	int ** matriz = (int**) malloc(n * sizeof(int*));
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

void matriz_rellena(int ** matriz_nm,int n,int m){
	for (int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if (j > 0 && i % j == 0){
				matriz_nm[i][j] = i+j+3 ;
			}else{
				matriz_nm[i][j] = i+j+1;
			}
		}
	}
}
void mostrar_matriz(int ** mostrar,int n,int m){
	for (int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if (j == 0){
				printf("( %d", mostrar[i][j]);
			}else if (j == m-1){
				printf("%d )\n", mostrar[i][j]);
			}else{
				printf("%d", mostrar[i][j]);
			}
		}
	}
}
void suma_contorno(int ** contornos,int n,int m, int reinicio){
	int suma_primera = 0;
	int suma_ultima = 0;
	if (reinicio == 0){
		for(int i = 0; i < m; i++){
			suma_primera += contornos[0][i];
			suma_ultima += contornos[n-1][i];
		}
		printf("La suma de la primera fila de la matriz = %d\n", suma_primera);
		printf("La suma de la ultima fila de la matriz = %d\n", suma_ultima);
		suma_contorno(contornos,n,m,reinicio+1);
	}else{
		for(int i = 0; i < n; i++){
			suma_primera += contornos[i][0];
			suma_ultima += contornos[i][m-1];
		}
		printf("La suma de la primera columna de la matriz = %d\n", suma_primera);
		printf("La suma de la ultima columna de la matriz = %d\n", suma_ultima);
	}
}