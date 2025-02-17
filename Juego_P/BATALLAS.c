#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "caballero.h"
#include "dragon.h"

void batalla(Caballero * jugador, Dragon * npc){
    int randomCri, randomAtaque, critico, ronda = 1;
    srand(time(NULL)); // crea una llista de numeros random en funcion de los segundos del PC
                       // Cada vez que hace rand() selecciona el siguiente número de la lista.
	while (jugador->vida >= 0 || npc->vida >= 0){
        critico = 0;
        randomAtaque = 0;
        printf("Ronda %d: \n", ronda);
        if (jugador->velocidad > npc->velocidad){
            randomCri = rand() % 8;
            if (randomCri == 1){
                critico = jugador->ataque;
                critico /= 3;
            }
            randomAtaque = rand() % 5; 
            npc->vidaActual -= jugador->ataque + critico + randomAtaque;
            sleep(2);
            printf("\tEl caballero %s ataca al dragon %s", jugador->nombre, npc->nombre);
            printf("\tSalud de %s: %d / %d totales", npc->nombre, npc->vidaActual, npc->vida);
            critico = 0;
            randomCri = rand() % 10;
            if (randomCri == 3){
                critico = npc->ataque;
                critico /= 5;
            }
            jugador->vidaActual -= npc->ataque + critico;
            sleep(2);
            printf("\tEl dragon %s, ataca al caballero %s",npc->nombre, jugador->nombre);
            printf("\tSalud de %s: %d / %d totales", jugador->nombre, jugador->vidaActual, jugador->vida);
        }else{
            randomCri = rand() % 10;
            if (randomCri == 3){
                critico = npc->ataque;
                critico /= 5;
            }
            jugador->vidaActual -= npc->ataque + critico;
            sleep(2);
            printf("\tEl dragon %s, ataca al caballero %s",npc->nombre, jugador->nombre);
            printf("\tSalud de %s: %d / %d totales", jugador->nombre, jugador->vidaActual, jugador->vida);
            if (jugador->velocidad > npc->velocidad){
                randomCri = rand() % 8;
                if (randomCri == 1){
                    critico = jugador->ataque;
                    critico /= 3;
                }
                randomAtaque = rand() % 5; 
                npc->vidaActual -= jugador->ataque + critico + randomAtaque;
                sleep(2);
                printf("\tEl caballero %s ataca al dragon %s", jugador->nombre, npc->nombre);
                printf("\tSalud de %s: %d / %d totales", npc->nombre, npc->vidaActual, npc->vida);
        }
        ronda ++;
    }
}