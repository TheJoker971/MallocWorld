#ifndef MAP_H
#define MAP_H

#define height  10 
#define width   10

struct Coordonnee{
    int x;
    int y;
};

typedef struct Coordonnee Coordonnee;

int** initMap();
int** allowMemory();
void draw(int**);
void freeMap(int**);
void genereMobs(int**,int);
void setBlankMap(int**);
void genereFlowers(int**,int);
void genereRocks(int**,int);
void genereTrees(int**,int);
void genereNoRoad(int**);
Coordonnee verifyBlank(int**);
void setPlayer(int**);
void preSaveMap(int**);
void drawInFile(FILE*,int**);

#endif // MAP_H