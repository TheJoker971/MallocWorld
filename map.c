#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "map.h"

void saveMap(int** map[]){
    //moveUp(map);
    FILE* f = fopen("./world.txt","w+");
    while(f != NULL){
        fprintf(f,"=== MAP ===\n");
        for(int i=0;i<3;i++){
            if(i == 0){
                fprintf(f,"-- ZONE 1 --\n");
                drawInFile(f,map[i]);
            }else if(i == 1){
                fprintf(f,"-- ZONE 2 --\n");
                drawInFile(f,map[i]);
            }else{
                fprintf(f,"-- ZONE 3 --\n");
                drawInFile(f,map[i]);
            }
        }
        fclose(f);
        f = NULL;
    }
}

int percent(){
    int p = rand() % 19;
    while(p < 10){
        p = rand() % 19;
    }
    int value = PIXELS * p/100;
    return value;
}

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
    genereMobs(part);
    genereFlowers(part,n);
    genereRocks(part,n);
    genereTrees(part,n);
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

void genereMobs(int** map){
    int monster = 0;
    int n = percent();
    for(int i = 0;i <n;i++){
        Coordonnee xy = verifyBlank(map);
        while(monster <12){
            monster = rand() % 99;
        }
        map[xy.x][xy.y] = monster; 
        monster = 0;    
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

void genereFlowers(int** map,int s){
    int n = percent();
    for(int i = 0;i <n;i++){
        Coordonnee xy = verifyBlank(map);
        map[xy.x][xy.y] = 3+(3*s);     
    }
}

void genereRocks(int** map,int s){
    int n = percent();
    for(int i = 0;i <n;i++){
        Coordonnee xy = verifyBlank(map);
        map[xy.x][xy.y] = 4+(3*s);     
    }
}

void genereTrees(int** map,int s){
    int n = percent();
    for(int i = 0;i <n;i++){
        Coordonnee xy = verifyBlank(map);
        map[xy.x][xy.y] = 5+(3*s);     
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
    FILE* file = fopen("./presave.txt","w+");
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

void chargePart(int n,int** part){
    FILE* f = fopen("world.txt","r");
    int jump = 0;
    switch (n)
    {
    case 0 :
        jump = 2;
        break;
    case 1:
        jump = 2+height+1;
        break;
    
    case 2:
        jump = 2*2 + height*2;
        break;
    }
    do{
        char c = getc(f);
        if(c == '\n'){
            jump--;
        }

    }while(jump != 0);
    for(int i =0;i<height;i++){
        for(int j =0;j<width;j++){
            if(j == width-1){
               fscanf(f,"%d\n",&part[i][j]);
            }else{
                fscanf(f,"%d ",&part[i][j]);
            }
        }
    }
    fclose(f);
}

int*** chargeMap(){
    int*** map = malloc(sizeof(int**)*3);
    for(int i =0;i<3;i++){
        map[i] = allowMemory();
        chargePart(i,map[i]);
    }
    return map;
}