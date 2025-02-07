#include <stdio.h>
#include <stdlib.h>

/*
	Trabajo realizado por Arnau y Samuel
*/
char ** crear_tablero(int n,int m); // Para reservar el espacio del tablero (sobre todo si lo elije el usuario)
void borde_tablero (char ** borde, int n, int m); // Para rellenar el tablero de espacios con un borde de asteriscos
void imprimir_tablero(char ** inicio, int n,int m); // Para limpiar la pantall y mostrar el tablero
void movimiento(char ** movimiento,int * n,int * m, char sbid); // Para moverse

int main(int argcount, char ** argvalue){
	int n,m;//n son filas y m columnas
	int x; // Posición filas
	int y; // Posición columnas
	char ** tablero; 
	char sbid; // subir, bajar, izquierda y derecha
	if(argcount == 1){
		n = 12;
		m = 12;
		x = n/2; // Lo dividimos entre 2 para que empiece en el medio
		y = m/2;
		tablero = crear_tablero(n,m);
		borde_tablero(tablero,n,m); // Mostramos el tablero con el # en medio
		do{
			scanf(" %c",&sbid);
			movimiento(tablero,&x,&y,sbid); // Le pasamos la posición de # por referencia para que se guarde cuando acabe la función
			imprimir_tablero(tablero,n,m);
		} while (sbid == 'w' || sbid == 's' || sbid == 'd' || sbid == 'a'); // Hasta que no escriba otra cosa, no acaba el bucle

	}else if(argcount == 3){
		if (atoi(argvalue[1]) < 2){
			printf("Introduce un número más grande para el ancho y poder crear un tablero\n");
			return 1; // Para que se acabe el programa
		}else if (atoi(argvalue[2]) < 2){
			printf("Introduce un número más grande para el largo y poder crear un tablero\n");
			return 1;
		}else{

			n = atoi(argvalue[1]);
			m = atoi(argvalue[2]);
			x = n/2;
			y = m/2;
			tablero = crear_tablero(n,m);
			borde_tablero(tablero,n,m);
			do{
				scanf(" %c",&sbid);
				movimiento(tablero,&x,&y,sbid);
				imprimir_tablero(tablero,n,m);
			} while (sbid == 'w' || sbid == 's' || sbid == 'd' || sbid == 'a');
		}

	}else{
		printf("Error pocos o demasiados argumentos por lineas de comandos, puedes escribir el ancho y largo del tablero\n");
        return 1;
	}
	
	for(int i = 0; i < n; i++){
			free(tablero[i]);
	}
	free(tablero);

	return 0;
}
char ** crear_tablero(int n,int m){
	char ** arr= (char**) malloc(n * sizeof(char*)); // Reserva de memoria para las filas
		if(arr == NULL) return 0;
		for(int i = 0; i < n; i++){
			arr[i] = (char*) malloc(m * sizeof(char)); // Reserva de memoria para las columnas
			if(arr[i] == NULL) return 0;
		}
		return arr;
}
void borde_tablero(char ** borde, int n, int m){
	for (int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(i == 0 || i == n-1 || j == 0 || j == m-1){
				borde[i][j] = '*'; // Ponemos * sólo en los bordes
			}else{
				borde[i][j] = ' '; // El resto lo llenamos de esapacios
			}
		}
	}
	borde[n/2][m/2] = '#';
	imprimir_tablero(borde,n,m);
}
void imprimir_tablero(char ** inicio, int n,int m){
	system("clear"); // Para limpiar la pantalla
	for (int i = 0; i < n; i++){
		printf("\t\t\t\t\t\t"); // Tabulamos para que se vea más centrado
		for(int j = 0; j < m; j++){
			printf("%c", inicio[i][j]);
		}
		printf("\n"); // Para pasar a la siguiente línea
	}
}
void movimiento(char ** movimiento,int * n,int * m, char sbid){
	switch (sbid){
		case 'w':
			if(movimiento[*n-1][*m] != '*'){ // Si la casilla a la que me voy a mover hay un * no me muevo
				movimiento[*n][*m] = ' ';
				(*n)--; // Para situarse en la línea de arriba
				movimiento[*n][*m] = '#';
			}
			break;
		case 's':
			if(movimiento[*n+1][*m] != '*'){
				movimiento[*n][*m] = ' ';
				(*n)++; // Para situarse en la línea de abajo
				movimiento[*n][*m] = '#';
			}
			break;
		case 'd':
			if(movimiento[*n][*m+1] != '*'){
				movimiento[*n][*m] = ' ';
				(*m)++; // Para situarse en la columna de la derecha
				movimiento[*n][*m] = '#';
			}
			break;
		case 'a':
			if(movimiento[*n][*m-1] != '*'){
				movimiento[*n][*m] = ' ';
				(*m)--; // Para situarse en la columna de la izquierda
				movimiento[*n][*m] = '#';
			}
			break;
	}
}