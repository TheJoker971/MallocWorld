#include <stdio.h>
#include <stdlib.h>
#include "map.h"

int main(int argc, const char* argv[]){
    // Initialisation de la map
    int** map = initMap();
    //Dessin de la map
    draw(map);
    // Libération de la Memoire
    freeMap(map);
    return 0;
}