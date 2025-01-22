#include <stdio.h>
#include <stdlib.h>
#define MAX_TAMANIO 50
#define NOTA_MAXIMA 10
typedef struct{
	char nombre[MAX_TAMANIO];
	char apellido[MAX_TAMANIO];
	float nota;
}Estudiante;


void añadir_alumno(Estudiante ** pupilo, int cantidad);

int main(){
	Estudiante * alumnos;
	int cantidad = 0;
	printf("Cuántos alumnos quieres añadir? ");
	int comprobacion = scanf("%d", &cantidad);
	if (comprobacion == 0){
		printf("Error, introduce un número\n");
		return 1;
	}
	alumnos = (Estudiante *) malloc (sizeof(Estudiante) * cantidad);
	if(alumnos == NULL) return 1;
	añadir_alumno(&alumnos, cantidad);
	//Ordenar(&alumnos, cantidad);
	for (int i = 0; i < cantidad; ++i){
		printf("Estudiante %d:\n- Nombre: %s- Apellido: %s- Nota: %.2f\n", i+1, alumnos[i].nombre, alumnos[i].apellido, alumnos[i].nota);
	}
	free(alumnos);
return 0;
}

void añadir_alumno(Estudiante ** pupilo, int cantidad){
	for (int i = 0; i < cantidad; i++)
	{
		printf("Escribe el nombre del estudiante: ");
		scanf(" ");
		fgets((*pupilo)[i].nombre, MAX_TAMANIO, stdin);
		printf("Escribe el apellido del estudiante: ");
		scanf(" ");
		fgets((*pupilo)[i].apellido, MAX_TAMANIO, stdin);
		printf("Escribe la nota del estudiante: ");
		scanf("%f", &((*pupilo)[i].nota));
	}
}