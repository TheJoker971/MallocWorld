#ifndef NPC_H
#define NPC_H
#include "craft.h"
#include "chest.h"

typedef struct Npc{
    Craft* crafts;
    Chest* chest;

}Npc;

Npc initNpc();
#endif // NPC_H