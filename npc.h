#ifndef NPC_H
#define NPC_H
#include "craft.h"
#include "chest.h"

typedef struct Npc{
    Craft* crafts;
    Chest* chest;
}Npc;

Npc initNpc();
void canCraft(Craft*,Object*);
int haveComponent(Object*, Object* );
int isInInventory(Object,Object*);
void repair(Object*);
#endif // NPC_H