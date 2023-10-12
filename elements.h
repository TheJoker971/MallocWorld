#ifndef ELEMENTS_H
#define ELEMENTS_H

struct Elements
{
    int elements; // Le num de l'element afficher sur la map et inventaire
    int capacity;
    int maxCapacity;
    int type;
};

enum type
{
    ARMES = 1,
    CRAFTS = 2
};

typedef struct Elements Elements;

#endif