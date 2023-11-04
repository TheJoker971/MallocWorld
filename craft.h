#ifndef CRAFT_H
#define CRAFT_H
#include "object.h"

typedef struct Craft{
    int id;
    Object* composent;
}Craft;

Craft* initCraft();
Object* crafting(int);
Object* armorCraft(int);
Object* healthCraft(int);
Object* swordCraft(int);
Object* toolCraft(int);
Object* lanceCraft(int);
Object* hammerCraft(int);
void showCraft(Craft* c);

#endif // CRAFT_H