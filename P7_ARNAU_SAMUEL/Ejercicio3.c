#include <stdio.h>
#include <stdlib.h>

/*
	Trabajo realizado por Arnau y Samuel
*/
char ** crear_tablero(int n,int m);
void borde_tablero (char ** borde, int n, int m);
void imprimir_tablero(char ** inicio, int n,int m);
void movimiento(char ** movimiento,int * n,int * m, char sbid);

int main(int argcount, char ** argvalue){
	int n,m;//n son filas y m columnas
	int * x;
	int * y;
	int tmpx, tmpy;
	char ** tablero; 
	char sbid;
	if(argcount == 1){
		n = 12;
		m = 12;
		tmpx = n/2;
		x = &tmpx;
		tmpy = m/2;
		y = &tmpy;
		tablero = crear_tablero(n,m);
		borde_tablero(tablero,n,m);
		do{
			scanf(" %c",&sbid);
			movimiento(tablero,x,y,sbid);
			imprimir_tablero(tablero,n,m);
		} while (sbid == 'w' || sbid == 's' || sbid == 'd' || sbid == 'a');

	}else if(argcount == 3){
		if (argvalue[1] < 0){
			printf("Introduce un número positivo para el ancho y poder crear un tablero");
		}else if (argvalue[2] < 0){
			printf("Introduce un número positivo para el largo y poder crear un tablero");
		}else{
			n = atoi(argvalue[1]);
			m = atoi(argvalue[2]);
			tmpx = n/2;
			x = &tmpx;
			tmpy = m/2;
			y = &tmpy;
			tablero = crear_tablero(n,m);
			borde_tablero(tablero,n,m);
			do{
				scanf(" %c",&sbid);
				movimiento(tablero,x,y,sbid);
				imprimir_tablero(tablero,n,m);
			} while (sbid == 'w' || sbid == 's' || sbid == 'd' || sbid == 'a');
			
		}

	}else{
		printf("Error pocos o demasiados argumentos por lineas de comandos, puedes escribir el ancho y largo del tablero\n");
        return 0;
	}
	for(int i = 0; i < n; i++){
			free(tablero[i]);
		}
		free(tablero);
return 0;
}
char ** crear_tablero(int n,int m){
	char ** arr= (char**) malloc(n * sizeof(char*));
		if(arr == NULL) return 0;
		for(int i = 0; i < n; i++){
			arr[i] = (char*) malloc(m * sizeof(char));
			if(arr[i] == NULL) return 0;
		}
		return arr;
}
void borde_tablero(char ** borde, int n, int m){
	for (int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(i == 0 || i == n-1 || j == 0 || j == m-1){
				borde[i][j] = '*';
			}else{
				borde[i][j] = ' ';
			}
		}
	}
	borde[n/2][m/2] = '#';
	imprimir_tablero(borde,n,m);
}
void imprimir_tablero(char ** inicio, int n,int m){
	system("clear");
	for (int i = 0; i < n; i++){
		printf("\t\t\t\t\t\t");
		for(int j = 0; j < m; j++){
			printf("%c", inicio[i][j]);
		}
		printf("\n");
	}
}
void movimiento(char ** movimiento,int * n,int * m, char sbid){
	switch (sbid){
		case 'w':
			movimiento[*n][*m] = ' ';
			(*n)--;
			movimiento[*n][*m] = '#';
			break;
		case 's':
			movimiento[*n][*m] = ' ';
			(*n)++;
			movimiento[*n][*m] = '#';
			break;
		case 'd':
			movimiento[*n][*m] = ' ';
			(*m)++;
			movimiento[*n][*m] = '#';
			break;
		case 'a':
			movimiento[*n][*m] = ' ';
			(*m)--;
			movimiento[*n][*m] = '#';
			break;
	}
}