#ifndef MAP_H
#define MAP_H

int **initMap();
void draw(int **);
void freeMap(int **);

struct Coordonnee
{
    int x;
    int y;
};

typedef struct Coordonnee Coordonnee;

#endif // MAP_H