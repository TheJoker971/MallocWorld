#include "player.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
    // Initialisation of the npc and the player
    Npc npc = initNpc();
    Player p = initPlayer();
    //-----------------------------------------------
    // Creation of the Object Tests
    Object first = initObject(5,5,0);
    Object second = initObject(6,6,0);
    Object third = initObject(6,20,0);
    Object fourth = initObject(6,20,0);
    //-----------------------------------------------
    // Add these Object in the player inventory and npc chest
    //addObject(npc.chest,&first);
    addObject(npc.chest,&second);
    addInventory(p.inventory,third);
    addInventory(p.inventory,fourth);
    addObject(npc.chest,&third);
    // Show the chest
    printf("Affichage du coffre avant l'ajout de l'element du player\n");
    showChest(npc.chest);
    //--------------------------------------------------
    //-----------------------------------------------------------
    // Calling function store in chest to get an object of the player inventory on the chest
    storeInChest(p,npc);
    //-------------------------------------------------
    // Show the chest
    printf("Affichage du coffre apres l'ajout de l'element du player\n");
    showChest(npc.chest);
    withdrawOfChest(p,npc);
    showChest(npc.chest);
    //--------------------------------------------------
    // Show inventory of the player after transaction
    printf("Affichage de l'inventaire apres l'ajout de l'element du player dans le coffre\n");
    showInventory(p);
    //----------------------------------------------------
    return 0;
}