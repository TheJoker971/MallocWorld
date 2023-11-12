#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "map.h"
#include "player.h"
#include "npc.h"
#include "movePlayer.h"
#include "monsters.h"

int main(int argc, const char* argv[]){
    // Initialisation de la map, du npc et du joueur
    int*** map = initMap();
    Npc npc = initNpc();
    Player p = initPlayer();
    // Autres initialisations...

    char startCommand[10];
    printf("Tapez 'start' pour commencer le jeu : ");
    scanf("%s", startCommand);

    if (strcmp(startCommand, "start") == 0) {
        int gameRunning = 1;
        while (gameRunning && p.hp > 0) {
            char depl;
            printf("Entrer un truc : ");
            scanf(" %c", &depl);

            if (depl == 'z' || depl == 's' || depl == 'q' || depl == 'd') {
                movePlayer(map, depl, p);
                
            } else {
                printf("Entrée non valide. Veuillez réessayer.\n");
            }

            // Vérifier si le joueur est mort
            if (p.hp <= 0) {
                printf("Game Over. Le joueur est mort.\n");
                gameRunning = 0;
            }

            // Autres conditions pour arrêter le jeu...
        }
    } else {
        printf("Commande non reconnue. Le jeu ne démarre pas.\n");
    }

    // Nettoyage et libération des ressources
    freeMap(map);

    return 0;
}


