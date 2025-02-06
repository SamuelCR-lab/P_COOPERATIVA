#include <stdio.h>
#include <stdlib.h>

void matriz_rellena(int ** matriz_n, int * matriz_m,n,m);

int main(){
	int n,m;
	printf("Introduce las filas que quieres que tenga una matriz: ");
	scanf(" %d",n);
	printf("Introduce las columnas que quieres que tenga una matriz: ");
	scanf(" %d",m);
	int ** matriz = (int**) malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++){
		matriz[i] = (int*) malloc (m * sizeof(int*))
	}
	matriz_rellena(*(matriz)[0], &matriz[0],n,m);
	mostrar_matriz();
return 0;
}

void matriz_rellena(int ** matriz_nm,n,m){
	for (int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if (i % j == 0){
				matriz_nm[i][j] = i+j+2;
			}else{
				matriz_nm[i][j] = i+j+1;
			}
		}
	}

}