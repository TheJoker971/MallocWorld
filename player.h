#ifndef PLAYER_H
#define PLAYER_H
#include "object.h"
#include "npc.h"


typedef struct Player
{
    int hp;
    int maxHp;
    int xp;
    int level;
    Object* inventory;
} Player;

Player initPlayer();
void initInventory(Object*);
void showInventory(Player);
void deleteObject(Object*);
int addInventory(Object*,Object);
Object* isInInventory(Object*);
void storeInChest(Player,Npc);
void withdrawOfChest(Player p,Npc npc);



#endif // PLAYER_H