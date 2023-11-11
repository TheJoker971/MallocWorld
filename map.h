#ifndef MAP_H
#define MAP_H


#define height  10 
#define width   10
#define PIXELS      height * width

struct Coordonnee{
    int x;
    int y;
};

typedef struct Coordonnee Coordonnee;


//void moveUp(int**[]);
int*** initMap();
int** initPart(int);
int** allowMemory();
void drawMap(int**[]);
void drawPart(int**);
void freeMap(int**[]);
void genereMobs(int**);
void setBlankMap(int**);
void genereFlowers(int**,int);
void genereRocks(int**,int);
void genereTrees(int**,int);
void genereNoRoad(int**);
void generePortals(int**,int);
void genereBoss(int**);
Coordonnee verifyBlank(int**);
void setPlayer(int**);
void setPnj(int**);
void preSaveMap(int**[]);
void drawInFile(FILE*,int**);
int percent();
void saveMap(int** []);
int*** chargeMap(char[]);
void chargePart(int,int**,FILE*);
void reloadMap(int** []);



#endif // MAP_H