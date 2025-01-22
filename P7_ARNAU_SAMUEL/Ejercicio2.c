#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAMANIO 50

typedef struct{
	char nombre[MAX_TAMANIO];
	char apellido[MAX_TAMANIO];
	float nota;
}Estudiante;

void OrdenarApellido(Estudiante ** OrdenApellido);
void OrdenarNota(Estudiante ** OrdenNota);
void Ordenar(Estudiante ** ordenado, int cantidad);

int main(){


return 0;
}

void Ordenar(Estudiante ** ordenado, int cantidad){
	Estudiante * orden = (*ordenado)[0];
	for (int i = 1; i < cantidad; i++){
		if (*orden.nota < ordenado[i]->nota){
			*orden = &ordenado[i];
		}
		OrdenarNota(&orden);
	}
	int apellidoI;
	int Primer_apellido;
	for (int i = 0; i < cantidad; i++){
	strncpy(Primer_apellido,&orden[i].apellido,1);
	strncpy(apellidoI,&ordenado[i+1].apellido, 1);
		if (Primer_apellido > apellidoI){
			OrdenarApellido(&ordenado[i+1].apellido);
		}
	}
	OrdenarApellido(&orden[i].apellido)

}

void OrdenarNota(Estudiante ** OrdenNota){
	float *
}

void OrdenarApellido(Estudiante ** OrdenApellido){

}