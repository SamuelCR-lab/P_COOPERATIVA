#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAMANIO 50

typedef struct{
	char nombre[MAX_TAMANIO];
	char apellido[MAX_TAMANIO];
	float nota;
}Estudiante;

void añadir_alumno(Estudiante ** pupilo, int cantidad);
void imprimir_estudiantes(Estudiante ** imprimir_alumnos, int cantidad);
void OrdenarNota(Estudiante ** ordenado_nota, int cantidad);
void OrdenarApellido(Estudiante ** ordenado_apellido, int cantidad);
void IntercambiarEstudiante(Estudiante ** menor, Estudiante ** mayor);
//void OrdenarApellido(Estudiante ** ordenado_apellido, int cantidad);
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
	printf("\nAlumnos que has añadido\n");
	imprimir_estudiantes(&alumnos, cantidad);
	OrdenarNota(&alumnos, cantidad);
	printf("\nAlumnos ordenados por nota\n");
	imprimir_estudiantes(&alumnos, cantidad);
	OrdenarApellido(&alumnos, cantidad);
	printf("\nAlumnos ordenados por apellido\n");
	imprimir_estudiantes(&alumnos, cantidad);
	free(alumnos);
return 0;
}

void OrdenarNota(Estudiante ** ordenado_nota, int cantidad){
	if (cantidad <= 1){
		return;
	}
	Estudiante * orden = *ordenado_nota+0;
	for (int i = 1; i < cantidad; i++){
		if ((*orden).nota < (*ordenado_nota)[i].nota){
			IntercambiarEstudiante(&ordenado_nota[i], &orden);
		}
	}
	OrdenarNota((*ordenado_nota)+1, cantidad-1);
}
void OrdenarApellido(Estudiante ** ordenado_apellido, int cantidad){
	Estudiante * orden = ordenado_apellido[0];
	for (int i = 0; i < cantidad; i++){
		if (strcmp((*orden).apellido, (*ordenado_apellido)[i].apellido) <= 0){
			*orden = (*ordenado_apellido)[i];
		}	
		IntercambiarEstudiante(&ordenado_apellido[i],&orden);
		}
	} 


void IntercambiarEstudiante(Estudiante ** menor, Estudiante ** mayor){
	Estudiante * comodin = *menor;
	*menor = *mayor;
	*mayor = comodin;
}
/*
void IntercambiarEstudiante(Estudiante ** OrdenApellido, Estudiante ** ApellidoMenor){
	Estudiante * orden = *OrdenApellido;
	*OrdenApellido = *ApellidoMenor;
	*ApellidoMenor = orden;
}
*/
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
