#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "JuegoPrincipal.h"
#include <string.h>

int batalla(Caballero * jugador, Dragon npc){ // Pasamos dragón por valor para que cuando acabe la batalla, el dragón tenga las mismas estadísticas que antes.
    int ronda = 1;
    static int vidas = 1;
    srand(time(NULL)); // crea una llista de numeros random en funcion de los segundos del PC
                       // Cada vez que hace rand() selecciona el siguiente número de la lista.
    //system("clear");
    system("cat < Batalla.txt");
	while (jugador->vidaActual >= 0 && npc.vidaActual >= 0){
        printf("Ronda %d: \n", ronda);
        if (jugador->velocidad >= npc.velocidad){
           ataqueCaballero(jugador, &npc);
            if(npc.vidaActual <= 0){
                npc.vidaActual = 0;
                printf("El caballero %s ha ganado la batalla\n", jugador->alias);
                jugador->monedas += npc.monedas;
                if (strcmp(npc.nombre,"Charizard") == 0){
                    return 3;
                }else{
                    return 0;
                }
            }
            ataqueDragon(jugador, &npc);
            if (jugador->vidaActual <= 0){
                printf("El dragon %s ha ganado la batalla\n", npc.nombre);
                if(vidas == 1){
                    vidas--;
                    system("cat < Dios.txt");
                    jugador->monedas /= 2;
                    jugador->vidaActual = jugador->vida;
                    return 1;
                }else if(vidas == 0){
                    vidas--;
                    system("cat < Muerte.txt");
                    return 2;
                }else{
                    printf("Ya no hay mas intentos, GAME OVER");
                    return 3;
                }
            }
        }else{
            ataqueDragon(jugador, &npc);
            if (jugador->vidaActual <= 0){
                jugador->vidaActual = 0;
                printf("El dragon %s ha ganado la batalla\n", npc.nombre);
                if(vidas == 1){
                    vidas--;
                    system("cat < Dios.txt");
                    jugador->monedas /= 2;
                    return 1;
                }else if(vidas == 0){
                    vidas--;
                    system("cat < Muerte.txt");
                    return 2;
                }else{
                    printf("Ya no hay mas intentos, GAME OVER\n");
                    return 3;
                }
            }
            ataqueCaballero(jugador, &npc);
            if(npc.vidaActual <= 0){
                npc.vidaActual = 0;
                printf("El caballero %s ha ganado la batalla\n", jugador->alias);
                jugador->monedas += npc.monedas;
                if (strcmp(npc.nombre,"Charizard") == 0){
                    return 3;
                }else{
                    return 0;
                }
            }
        }
        ronda ++;
    }
	return 0;
}

