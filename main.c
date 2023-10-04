#include <stdio.h>
#include <stdlib.h>
#include "mapping.h"
#include "player.h"
#include "pnj.h"

int main(int argc, const char *argv[])
{
    // // initialisation de la map
    // int **map = initMap();
    // // Dessiner la map
    // draw(map);
    // // On libere la ram
    // freeMap(map);

    // joueur
    Player p;

    startPlayer(&p);
    // pnj
    Pnj pn;
    stockPnj(&pn);

    // show inventaire

    showInventaire(p);

    return 0;
}
