#include <stdio.h>
#include <stdlib.h>
#include "map.h"


// voiD saveMap(){
//     // fopen("world.txt","a+")
//     FILE* file = fopen("world.txt","a+");

// }
int*** initMap(){
    int*** mapping = malloc(sizeof(int**)*3);
    for(int i = 0; i < 3;i++){
        mapping[i] = initPart(i);
    }
    preSaveMap(mapping);
    return mapping;
}
int** initPart(int n){
    int** part = allowMemory();
    setBlankMap(part);
    generePortals(part,n);
    if(n == 0){ 
       setPlayer(part);
    }
    if(n == 2){
        genereBoss(part);
    }
    setPnj(part);
    genereMobs(part,10);
    genereFlowers(part,(height+width)/2);
    genereRocks(part,(height+width)/2);
    genereTrees(part,(height+width)/2);
    genereNoRoad(part);
    
    return part;
}

int** allowMemory(){
    // Allocation de la memoire du tableau 2D
    int** part = malloc(sizeof(int*)*height);
    for(int i =0;i<height;i++){
        part[i] = malloc(sizeof(int)*width);
    }
    return part;
}

void drawMap(int** map[]){
    printf("=== MAP ===\n");
    for(int i=0;i<3;i++){
        if(i == 0){
            printf("-- ZONE 1 --\n");
            drawPart(map[i]);
        }else if(i == 1){
            printf("-- ZONE 2 --\n");
            drawPart(map[i]);
        }else{
            printf("-- ZONE 3 --\n");
            drawPart(map[i]);
        }
    }
}

void drawPart(int** map){
    // Dessine le mapleau en console
    for(int i =0; i<height;i++){
        for(int j =0;j<width;j++){
            if(j == width-1){
                printf("%d\n",map[i][j]);
            }else{
                printf("%d ",map[i][j]);
            }
        }
    }
}

void freeMap(int** map[]){
    // Libère la mémoire utilisée par le tableau
    for(int i = 0;i<3;i++){
        for(int x =0;x<height;x++){
            free(map[i][x]);
        }
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
        int monster = rand() % 99;
        while(monster<12){
            monster = rand() % 99;
        }
        map[xy.x][xy.y] = monster;     
    }
}

void genereBoss(int** map){
    Coordonnee xy;
    xy.x = height-1;
    xy.y = rand() % width;
    while(map[xy.x][xy.y]!= 0)  {
        xy.y = rand() % width;
    }
    map[xy.x][xy.y] = 99;
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
    int n = rand()%(height+width);
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

void setPnj(int** map){
    Coordonnee xy = verifyBlank(map);
    map[xy.x][xy.y] = 2;     
}


void generePortals(int** map,int n){
    switch(n){
        case 0:
            map[height-1][rand()%width] = -2;
            break;
        case 1:
            map[0][rand()%width] = -2;
            map[height -1][rand()%width] = -3;
            break;
        case 2:
            map[0][rand()%width] = -3;
            break;
    }
}

void drawInFile(FILE* f,int** map){
    for(int i =0;i<height;i++){
        for(int j =0;j<width;j++){
            if(j<width-1){
                fprintf(f,"%d ",map[i][j]);
            }else{
                fprintf(f,"%d\n",map[i][j]);
            }
        }
    }
}

void preSaveMap(int** map[]){
    FILE* file = fopen("presave.txt","w+");
    while(file != NULL){
        fprintf(file,"=== MAP ===\n");
        for(int i=0;i<3;i++){
            if(i == 0){
                fprintf(file,"-- ZONE 1 --\n");
                drawInFile(file,map[i]);
            }else if(i == 1){
                fprintf(file,"-- ZONE 2 --\n");
                drawInFile(file,map[i]);
            }else{
                fprintf(file,"-- ZONE 3 --\n");
                drawInFile(file,map[i]);
            }
        }
        fclose(file);
        file = NULL;
    }
}
