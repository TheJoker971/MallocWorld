#include <stdio.h>
#include <stdlib.h>
#include "map.h"
#include "movePlayer.h"

int main(int argc, const char* argv[]){
    // Initialisation de la map
    int*** map = initMap();
  //Dessin de la map
    draw(map);
  //Conditions qui demande à l'utilisateur d'entrer une touche
    char depl = 'A';
    do {
        printf("Entrer un truc : ");
        scanf(" %c", &depl);

        if (depl == 'z' || depl == 's' || depl == 'q' || depl == 'd') {
            // Appele de la fonction movePlayer
            movePlayer(map, depl);
        } else {
            printf("Entrée non valide. Veuillez réessayer.\n");
        }
    } while (1);
    // Libération de la Memoire
    freeMap(map);
    
    printf("\n");
    drawMap(map);
    return 0;
}