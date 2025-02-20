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
	while (jugador->vidaActual >= 0 && npc.vidaActual >= 0){
        printf("Ronda %d: \n", ronda);
        if (jugador->velocidad >= npc.velocidad){
           ataqueCaballero(jugador, &npc);
            if(npc.vidaActual <= 0){
                npc.vidaActual = 0;
                printf("El caballero %s ha ganado la batalla\n", jugador->nombre);
                jugador->monedas += npc.monedas;
                jugador->vidaActual += jugador->vida * 0.3;
                if (strcmp(npc.nombre,"Charizard") == 0){
                    return 3;
                }else{
                    return 0;
                }
            }
            ataqueDragon(jugador, &npc);
            if (jugador->vidaActual <= 0){
                jugador->vidaActual = 0;
                printf("El dragon %s ha ganado la batalla\n", npc.nombre);
                if(vidas == 1){
                    vidas--;
                    system("cat < Dios.txt");
                    printf("lore");
                    jugador->monedas /= 2;
                    return 0;
                }else if(vidas == 0){
                    vidas--;
                    system("cat < Muerte.txt");
                    printf("lore");
                    return 1;
                }else{
                    printf("Ya no hay mas intentos, GAME OVER");
                    return 2;
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
                    printf("lore");
                    jugador->monedas /= 2;
                    return 0;
                }else if(vidas == 0){
                    vidas--;
                    system("cat < Muerte.txt");
                    printf("lore");
                    return 1;
                }else{
                    printf("Ya no hay mas intentos, GAME OVER");
                    return 2;
                }
            }
            ataqueCaballero(jugador, &npc);
            if(npc.vidaActual <= 0){
                npc.vidaActual = 0;
                printf("El caballero %s ha ganado la batalla\n", jugador->nombre);
                jugador->monedas += npc.monedas;
                jugador->vidaActual += jugador->vida * 0.3;
                if (strcmp(npc.nombre,"Charizard") == 0){
                    return 3;
                }else{
                    return 0;
                }
            }
        }
        ronda ++;
    }
    if (jugador->vidaActual > jugador->vida){
        jugador->vidaActual = jugador->vida;
    }
}

// TODO: si te mata un dragon, viene dios y te revive con la mitad de la vida.
//       Si te vuelve a matar, viene el demonio y te lleva a la tienda del inframundo y te vende almas, que cada una tiene una salud
//       basadas en las monedas que tengs. Si no tienes monedas, carricoche.
