#include <stdio.h>
#include <stdlib.h>
#include "map.h"

int main(int argc, const char* argv[]){
    
    // Initialisation de la map
    int*** map = initMap();

    //Dessin de la map
    drawMap(map);
    // SaveMap
    saveMap(map);
    printf("\n");
    // Chargement de la map
    freeMap(map);
    
    
    // showInventaire(p);

    return 0;
}