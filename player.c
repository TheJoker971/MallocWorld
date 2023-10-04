#include <stdio.h>
#include <stdlib.h>
#include "player.h"

Player initPlayer(){
    Player p;
    p.pv = 100;
    p.maxPv = 100;
    p.exp = 1;
    p.inventaire = malloc(sizeof(int)*10);
    p.inventaire[0] = 1,p.inventaire[1] =2, p.inventaire[2] = 3, p.inventaire[3] = 4;
    return p;
}

void showInventaire(Player p){
    int i = 0;
    while(p.inventaire[i] <5 && i < 10){
        printf("Une arme dans l'inventaire case %d\n",i+1);
        printf("%d\n",p.inventaire[i]);
        i++;
    }
}