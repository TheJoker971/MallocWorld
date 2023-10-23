#ifndef CHEST_H
#define CHEST_H
#include "object.h"

typedef struct Chest{
    Object object;
    struct Chest* next;
}Chest;

Chest* initChest();
Chest* newObject(Object*);
void addObject(Chest*,Object*);
void firstAdd(Chest*,Object*);
void showChest(Chest*);
Object* getObject(Chest*,int);

#endif // CHEST_H