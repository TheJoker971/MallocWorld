#include <stdio.h>
#include <stdlib.h>
#include "map.h"

int main(int argc, const char* argv[]){
    // Initialisation de la map
    int*** map = initMap();
    //Dessin de la map
    drawMap(map);
    // Libération de la Memoire
    freeMap(map);
    
    printf("\n");
    drawMap(map);
    return 0;
}