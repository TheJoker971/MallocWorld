#include "npc.h"
#include <stdio.h>
#include <stdlib.h>

Npc initNpc(){
    Npc npc;
    npc.crafts = initCraft();
    npc.chest = initChest();
    return npc;
}

int canCraft(Craft* c,Object* p){
    printf("You can craft these Object : \n");
    printf("---------------------------------\n");
    printf("|\tID\t|\tObject\t|\n");
    printf("---------------------------------\n");
    int ok =  0;
    for(int i =0;i<25;i++){
        if(haveComponent(c[i].composent,p)){
            printf("|\t%d\t|\t%d\t|\n",i+1,c[i].id);
            ok = 1;
        }else{
            printf("|\t \t|\t \t|\n");
        }
    }
    printf("---------------------------------\n");
    return ok;
}

int haveComponent(Object* o, Object* inv){
    int count = 0;
    for(int i = 0;i<2;i++){
        if(isInInventory(o[i],inv)){
            count++;
        }
    }
    if(count == 2){
        return 1;
    }
    return 0;
}

int isInInventory(Object o,Object* inv){
    for(int i =0;i<10;i++){
        if(o.id == inv[i].id && inv[i].quantity >= o.quantity ){
            return 1;
        }
        else if(o.id == 0){
            return 1;
        }
    }
    return 0;
}

void repair(Object* inv){
    for(int i =0;i<10;i++){
        if(isWeapon(inv[i].id) || isTools(inv[i].id)){
            inv[i] = initObject(inv[i].id,1);
        }
    }
    printf("Vos Outils/Armes ont été réparé\n");
}

void freeNpc(Npc npc){
    freeChest(npc.chest);
    free(npc.crafts);
}