#include "player.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
    // Initialisation of the npc and the player
    Npc npc = initNpc();
    Player p = initPlayer();
    //-----------------------------------------------
    // Creation of the Object Tests
    // Object first = initObject(5,5);
    // Object second = initObject(6,6);
    // Object third = initObject(6,20);
    // Object fourth = initObject(17,20);
    //-----------------------------------------------
    // Add these Object in the player inventory and npc chest
    //addObject(npc.chest,&first);
    
    addInventory(p.inventory,initObject(17,20));
    addInventory(p.inventory,initObject(6,20));
    addInventory(p.inventory,initObject(5,20));
    addInventory(p.inventory,initObject(17,20));
    addInventory(p.inventory,initObject(18,20));
    addInventory(p.inventory,initObject(33,20));
    p.inventory[0].durability-=5;
    p.inventory[2].durability-=3;
    showInventory(p);
    //repair(p.inventory);
    //withdrawInventory(p,initObject(6,6));
    craftObject(npc.crafts,p);
    showInventory(p);
    //showCraft(npc.crafts);
    //canCraft(npc.crafts,p.inventory);
    // Show the chest
    
    return 0;
}