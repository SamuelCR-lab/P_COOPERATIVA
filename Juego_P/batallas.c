#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "JuegoPrincipal.h"

void batalla(Caballero * jugador, Dragon npc){ // Pasamos dragón por valor para que cuando acabe la batalla, el dragón tenga las mismas estadísticas que antes.
    int ronda = 1;
    srand(time(NULL)); // crea una llista de numeros random en funcion de los segundos del PC
                       // Cada vez que hace rand() selecciona el siguiente número de la lista.
	while (jugador->vidaActual >= 0 && npc.vidaActual >= 0){
        printf("Ronda %d: \n", ronda);
        if (jugador->velocidad >= npc.velocidad){
           ataqueCaballero(jugador, &npc);
            if(npc.vidaActual <= 0){
                npc.vidaActual = 0;
                printf("El caballero %s ha ganado la batalla\n", jugador->nombre);
                jugador->monedas += npc.monedas;
                jugador->vidaActual += jugador->vida * 0.3;
                break;
            }
            ataqueDragon(jugador, &npc);
            if (jugador->vidaActual <= 0){
                jugador->vidaActual = 0;
                printf("El dragon %s ha ganado la batalla\n", npc.nombre);
                system("cat < Muerte.txt");
                break;
            }
        }else{
            ataqueDragon(jugador, &npc);
            if (jugador->vidaActual <= 0){
                jugador->vidaActual = 0;
                printf("El dragon %s ha ganado la batalla\n", npc.nombre);
                system("cat < Muerte.txt");
                break;
            }
            ataqueCaballero(jugador, &npc);
            if(npc.vidaActual <= 0){
                npc.vidaActual = 0;
                printf("El caballero %s ha ganado la batalla\n", jugador->nombre);
                jugador->monedas += npc.monedas;
                jugador->vidaActual += jugador->vida * 0.3;
                break;
            }
        }
        ronda ++;
    }
    if (jugador->vidaActual > jugador->vida){
        jugador->vidaActual = jugador->vida;
    }
}