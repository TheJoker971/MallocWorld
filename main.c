#include <stdio.h>
#include <stdlib.h>
#include "map.h"
#include "player.h"
#include "pnj.h"
#include "movePlayer.h"

int main(int argc, const char* argv[]){
    
    // Initialisation de la map
    int*** map = initMap();


    //Dessin de la map
    drawMap(map);
    // SaveMap
    saveMap(map);
    printf("\n");
    // Chargement de la map
    int*** map1 = chargeMap();
    // Affichage des changements
    drawMap(map1);
    // Libération de la Memoire
    freeMap(map1);
  //Dessin de la map
    //draw(map);
  //Conditions qui demande à l'utilisateur d'entrer une touche
    char depl = 'A';
    do {
        printf("Entrer un truc : ");
        scanf(" %c", &depl);

        if (depl == 'z' || depl == 's' || depl == 'q' || depl == 'd') {
            // Appelle de la fonction movePlayer
            movePlayer(map, depl);
        } else {
            printf("Entrée non valide. Veuillez réessayer.\n");
        }
    } while (1);
  
    printf("\t-------PLAYER-----------\n");
    // joueur
    Player p;

    startPlayer(&p);
    // pnj
    Pnj pn;
    stockPnj(&pn);

    // show inventaire

    showInventaire(p);
    // Libération de la Memoire
    //drawMap(map);
    freeMap(map);
    
    printf("\n");

    return 0;
}
