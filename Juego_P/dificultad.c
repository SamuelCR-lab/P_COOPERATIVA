#include <stdio.h>
#include <stdlib.h>


// Función para elegir la dificultad.
int dificultad(){
	int elegir_opo, errores_opo;
	 do{
	 	printf(GREEN"\n\n\t 1. Mushu\n"); // TODO: Asignar las estadísticas a cada dragón.
	 	printf(YELLOW"\t 2. Shenlong \n");
	 	printf(MAGENTA"\t 3. Balerion \n");
	 	printf(RED"\t 4. Charizar \n");
	 	printf(WHITE "\n\n");
	 	printf("¿A que dragón te vas a enfrentar?: ");
		errores_opo = scanf("%d",&elegir_opo);
		if (errores_opo==0){ // Entra en el condicional si ha escrito una letra.
			printf("No has introducido un número o has introducido un número que no está asignado a ningún dragón\n");
			char buffer[50]; 
			scanf("%s",buffer); // Para limpiar el buffer y que no sea un bucle infinito.
		}
	 }while (elegir_opo < 1 || elegir_opo > 4 || errores_opo==0);

	 return elegir_opo;
}