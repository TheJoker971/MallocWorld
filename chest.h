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
Chest* getObject(Chest*,int);
void deleteChain(Chest*,int);
Object withdrawObject(Chest*);
void freeChest(Chest*);

#endif // CHEST_H