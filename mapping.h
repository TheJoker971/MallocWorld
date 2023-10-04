#ifndef MAPPING_H
#define MAPPING_H

int** initMap();
void draw(int**);
void freeMap(int**);

struct Coordonnee{
    int x;
    int y;
};

typedef struct Coordonnee Coordonnee;

#endif // MAPPING_H