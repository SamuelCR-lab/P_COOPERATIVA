#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "colors.h"
#include "dragon.h"


// Función para elegir la dificultad.
int dificultad(){
	int elegir_opo, errores_opo;
	 do{
	 	printf(RED"\n\n\t 1. Mushu (fácil)\n"); // TODO: Asignar las estadísticas a cada dragón.
	 	//system("cat < Mushu.txt");
    	//sleep(1);
	 	printf(GREEN"\t 2. Shenlong (medio)\n");
	 	//system("cat < Shenlong.txt");
    	//sleep(1);
	 	printf(MAGENTA"\t 3. Balerion (difícil)\n");
	 	//system("cat < Balerion.txt");
    	//sleep(1);
	 	printf(ORANGE"\t 4. Charizard (jefe final)\n");
	 	//system("cat < Charizard.txt");
	 	printf(WHITE "\n\n");
    	sleep(1);
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