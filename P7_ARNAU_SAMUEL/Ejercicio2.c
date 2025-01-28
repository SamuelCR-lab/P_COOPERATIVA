#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAMANIO 50

typedef struct{
	char nombre[MAX_TAMANIO];
	char apellido[MAX_TAMANIO];
	float nota;
}Estudiante;

void OrdenarApellido(Estudiante ** OrdenApellido, Estudiante ** NotaMayor);
void OrdenarNota(Estudiante ** OrdenNota, Estudiante ** NotaMayor);
void Ordenar(Estudiante ** ordenado, int cantidad);
void añadir_alumno(Estudiante ** pupilo, int cantidad);
void imprimir_estudiantes(Estudiante ** imprimir_alumnos, int cantidad);
void Ordenar2(Estudiante ** ordenado_apellido, int cantidad);
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
	imprimir_estudiantes(&alumnos, cantidad);
	Ordenar(&alumnos, cantidad);
	imprimir_estudiantes(&alumnos, cantidad);
	Ordenar2(&alumnos, cantidad);
	imprimir_estudiantes(&alumnos, cantidad);
	free(alumnos);
return 0;
}

void Ordenar(Estudiante ** ordenado, int cantidad){
	Estudiante * orden = ordenado[0];
	for (int i = 0; i < cantidad; i++){
		if ((*orden).nota < (*ordenado)[i].nota){
			*orden = (*ordenado)[i];
		}
	OrdenarNota(&ordenado[i],&orden);

	}
}
void Ordenar2(Estudiante ** ordenado_apellido, int cantidad){
	Estudiante * orden = ordenado_apellido[0];
	for (int i = 0; i < cantidad; i++){
		if (strcmp((*orden).apellido, (*ordenado_apellido)[i].apellido) <= 0){
			*orden = (*ordenado_apellido)[i];
		}	
		OrdenarApellido(&ordenado_apellido[i],&orden);
		}
	} 


void OrdenarNota(Estudiante ** OrdenNota, Estudiante ** NotaMayor){
	Estudiante * orden = *OrdenNota;
	*OrdenNota = *NotaMayor;
	*NotaMayor = orden;
}

void OrdenarApellido(Estudiante ** OrdenApellido, Estudiante ** ApellidoMenor){
	Estudiante * orden = *OrdenApellido;
	*OrdenApellido = *ApellidoMenor;
	*ApellidoMenor = orden;
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

void imprimir_estudiantes(Estudiante ** imprimir_alumnos, int cantidad){
	for (int i = 0; i < cantidad; i++){
		printf("Estudiante %d:\n- Nombre: %s- Apellido: %s- Nota: %.2f\n", i+1, (*imprimir_alumnos)[i].nombre, (*imprimir_alumnos)[i].apellido, (*imprimir_alumnos)[i].nota);
	}
}