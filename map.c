#include <stdio.h>
#include <stdlib.h>
#include "map.h"


// voiD saveMap(){
//     // fopen("world.txt","a+")
//     FILE* file = fopen("world.txt","a+");

// }
int** initMap(){
    int** map = allowMemory();
    setBlankMap(map);
    genereMobs(map,10);
    genereFlowers(map,3);
    genereRocks(map,3);
    genereTrees(map,3);
    genereNoRoad(map);
    setPlayer(map);
    return map;
}

int** allowMemory(){
    // Allocation de la memoire du tableau 2D
    int** map = malloc(sizeof(int*)*height);
    for(int i =0;i<height;i++){
        map[i] = malloc(sizeof(int)*width);
    }
    return map;
}

void draw(int** map){
    // Dessine le mapleau en console
    for(int i =0; i<height;i++){
        for(int j =0;j<width;j++){
            printf("%d ",map[i][j]);
        }
        printf("\n");
    }
}

void freeMap(int** map){
    // Libère la mémoire utilisée par le tableau
    for(int i = 0;i<height;i++){
        
        free(map[i]);
    }
    free(*map);
}

void setBlankMap(int** map){
    for(int i = 0;i<height;i++){
        for(int j = 0; j<width;j++){
            map[i][j] = 0;
        }
    }
}

void genereMobs(int** map,int n){
    for(int i = 0;i <n;i++){
        Coordonnee xy = verifyBlank(map);
        map[xy.x][xy.y] = 12;     
    }
}

void genereFlowers(int** map,int n){
    for(int i = 0;i <n;i++){
        Coordonnee xy = verifyBlank(map);
        map[xy.x][xy.y] = 3;     
    }
}

void genereRocks(int** map,int n){
    for(int i = 0;i <n;i++){
        Coordonnee xy = verifyBlank(map);
        map[xy.x][xy.y] = 4;     
    }
}

void genereTrees(int** map,int n){
    for(int i = 0;i <n;i++){
        Coordonnee xy = verifyBlank(map);
        map[xy.x][xy.y] = 5;     
    }
}

void genereNoRoad(int** map){
    int n = rand()%10;
    for(int i = 0;i <n;i++){
        Coordonnee xy = verifyBlank(map);
        map[xy.x][xy.y] = -1;     
    }
}

Coordonnee verifyBlank(int** map){
    int boolean = 0;
    Coordonnee xy;
    do{
        xy.x = rand()%height;
        xy.y = rand()%width;
        if(map[xy.x][xy.y] == 0 ){
            boolean = 1;
        }
    }while(boolean == 0);
    
    return xy;
}

void setPlayer(int** map){
    Coordonnee xy = verifyBlank(map);
    map[xy.x][xy.y] = 1;     
}