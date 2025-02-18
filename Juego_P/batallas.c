#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "caballero.h"
#include "dragon.h"

void batalla(Caballero * jugador, Dragon * npc){
    int randomCri, randomAtaque, critico, ronda = 1;
    srand(time(NULL)); // crea una llista de numeros random en funcion de los segundos del PC
                       // Cada vez que hace rand() selecciona el siguiente número de la lista.
	while (jugador->vidaActual >= 0 || npc->vidaActual >= 0){
        critico = 0;
        randomAtaque = 0;
        printf("Ronda %d: \n", ronda);
        if (jugador->velocidad > npc->velocidad){
           ataqueCaballero(&Jugador, &Dragon);
            critico = 0;
            if(npc->vidaActual <= 0){
                printf("El caballero %s ha ganado la batalla\n", jugador->nombre);
                break;
            }
            ataqueDragon(&Jugador, &Dragon);
            if (jugador->vidaActual <= 0){
                printf("El dragon %s ha ganado la batalla\n", npc->nombre);
                break;
            }
        }else{
            ataqueDragon(&Jugador, &Dragon);
            if (jugador->vidaActual <= 0){
                printf("El dragon %s ha ganado la batalla\n", npc->nombre);
                break;
            }
            critico = 0;
            ataqueCaballero(&Jugador, &Dragon);
            if(npc->vidaActual <= 0){
                printf("El caballero %s ha ganado la batalla\n", jugador->nombre);
                break;
            }
            }
            ronda ++;
        }
    }
    system("cat < Muerte.txt");
}