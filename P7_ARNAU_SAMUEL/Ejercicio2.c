#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
	Trabajo realizado por Arnau y Samuel
*/

#define MAX_TAMANIO 50//le damos un tamaño a los nombres y apellidos para no ir 
//Definicion de un struct para que la variable estudiante contenga cada uno de los tipos de datos
typedef struct{
	char nombre[MAX_TAMANIO];
	char apellido[MAX_TAMANIO];
	float nota;
}Estudiante;

void añadir_alumno(Estudiante ** pupilo, int cantidad);
void imprimir_estudiantes(Estudiante ** imprimir_alumnos, int cantidad);
void OrdenarNota(Estudiante ** ordenado_nota, int cantidad);
void OrdenarApellido(Estudiante ** ordenado_apellido, int cantidad);
void IntercambiarEstudiante(Estudiante ** menor, int posicion, Estudiante ** mayor);

int main(){
	Estudiante * alumnos;//Es un puntero de tipo estudiante
	int cantidad = 0;
	printf("Cuántos alumnos quieres añadir? ");
	int comprobacion = scanf("%d", &cantidad);
	if (comprobacion == 0){
		printf("Error, introduce un número\n");
		return 1;
	}
	alumnos = (Estudiante *) malloc (sizeof(Estudiante) * cantidad);//Reservamos memoria para en la variable alumno que es de tipo estudiante y por ello le hacemos un cast al malloc para que tambien lo sea (Estudiante*)
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
//Esta función es ordena la nota dada por doble referencia por ello lo igualamos a una variable orden de tipo estudiante que es un puntero
void OrdenarNota(Estudiante ** ordenado_nota, int cantidad){
	if (cantidad <= 1){
		return;
	}
	Estudiante * orden = *ordenado_nota+cantidad-1;//le restamos 1 para que comience por el ultimo, de los alumnos guardados
	for (int i = 0; i < cantidad; i++){
		if ((*orden).nota > (*ordenado_nota)[i].nota){//realizamos la comparacion con cada uno de ellos y se lo damos a la función IntercambiarEstudiante
			IntercambiarEstudiante(ordenado_nota, i, &orden);
		}
	}
	OrdenarNota(ordenado_nota, cantidad-1);
}
//En esta función seguimos el mismo procedimiento de la funcion ordenar nota
void OrdenarApellido(Estudiante ** ordenado_apellido, int cantidad){
	if (cantidad <= 1){
		return;
	}
	Estudiante * orden = *ordenado_apellido+cantidad-1;
	for (int i = 0; i < cantidad; i++){
		if (strcmp((*orden).apellido, (*ordenado_apellido)[i].apellido) <= 0){//Realizamos la comparacion mediante el strcmp de las dos cadenas de caracteres que si es <= 0 se realizara el intercambio
			IntercambiarEstudiante(ordenado_apellido, i, &orden);
		}
	}
	OrdenarApellido(ordenado_apellido, cantidad-1);
} 
//Fúncion encargada de realizar los cambios de orden de los alumnos dependiendo del orden que queremos realizar
void IntercambiarEstudiante(Estudiante ** menor, int posicion, Estudiante ** mayor){
	Estudiante comodin = *(*menor+posicion); // Guardamos los datos del estudiante menor en una variable comodin
	// Copiamos los datos del estudiante mayor en el estudiante menor
	strcpy((*menor+posicion)->nombre, (*mayor)->nombre);
	strcpy((*menor+posicion)->apellido, (*mayor)->apellido);
	(*menor+posicion)->nota = (*mayor)->nota;
	// Guardamos en mayor lo que había en menor que está en la variable comodín
	strcpy((*mayor)->nombre, comodin.nombre);
	strcpy((*mayor)->apellido, comodin.apellido);
	(*mayor)->nota = comodin.nota;
}
//Función que llamamos para añadir cada uno de los alumnos
void añadir_alumno(Estudiante ** pupilo, int cantidad){
	for (int i = 0; i < cantidad; i++){
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
//Función para imprimir los estudiantes
void imprimir_estudiantes(Estudiante ** imprimir_alumnos, int cantidad){//Le damos por referencia la direccion de memoria de la memoria reservada y la variable cantidad para que el bucle se detenga un alumno menos
	for (int i = 0; i < cantidad; i++){
		printf("Estudiante %d:\n- Nombre: %s- Apellido: %s- Nota: %.2f\n", i+1, (*imprimir_alumnos)[i].nombre, (*imprimir_alumnos)[i].apellido, (*imprimir_alumnos)[i].nota);
	}
}
