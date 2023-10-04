#include <stdio.h>
#include <stdlib.h>
#include "mapping.h"

// voiD saveMap(){
//     // fopen("world.txt","a+")
//     FILE* file = fopen("world.txt","a+");

// }

int** initMap(){
    Coordonnee joueur;
    joueur.x = 5;
    joueur.y = 5;
    // Allocation de la memoire du tableau 2D
    int** map = malloc(sizeof(int*)*10);
    for(int i =0;i<10;i++){
        map[i] = malloc(sizeof(int)*10);
    }
    // Affectation des valeurs du tableau
    for (int i = 0;i<10;i++){
        for(int j = 0;j<10;j++){
            if(i == joueur.x && j == joueur.y){
                map[i][j] = 1;
            }else{
                map[i][j] = 0;
            }
        }
    }
    return map;
}

void draw(int** tab){
    for(int i =0; i<10;i++){
        for(int j =0;j<10;j++){
            printf("%d ",tab[i][j]);
        }
        printf("\n");
    }
}

void freeMap(int** tab){
    for(int i = 0;i<10;i++){
        free(tab[i]);
    }
    free(tab);
}