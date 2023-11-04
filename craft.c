#include "craft.h"
#include <stdlib.h>
#include <stdio.h>

Craft* initCraft(){
    int count = 0;
    Craft* c = malloc(sizeof(Craft)*22);
    for(int i =1;i<35;i++){
        if(!isCraft(i)){
            if(crafting(i) != NULL){
                c[count].id = i;
                c[count].composent = crafting(i);
                count++;
            }
        }
    }
    printf("%d\n",count);
    return c;
}

Object* crafting(int id){
    Object* o = malloc(sizeof(Object)*2);
    Object* tab[] = {
        swordCraft(id),
        armorCraft(id),
        healthCraft(id),
        toolCraft(id),
        lanceCraft(id),
        hammerCraft(id)
    };
    for(int i = 0;i<5;i++){
        if(tab[i] != NULL){
            o = tab[i];
            return o;
        }
    }
    return NULL;
}

Object* swordCraft(int id){
    Object* o = malloc(sizeof(Object)*2);
    switch (id)
    {
    case 1:
        o[0] = initObject(5,3,0);
        o[1] = blankObject();
        break;
    case 8:
        o[0] = initObject(5,2,0);
        o[1] = initObject(6,3,0);
        break;

    case 19:
        o[0] = initObject(16,2,0);
        o[1] = initObject(17,4,0);
        break;
    
    case 30:
        o[0] = initObject(27,2,0);
        o[1] = initObject(28,5,0);
        break;
    default:
        o = NULL;
    }
    return o;
}

Object* armorCraft(int id){
    Object* o = malloc(sizeof(Object)*2);
    switch(id){
        case 11:
            o[0] = initObject(6,10,0);
            o[1] = blankObject();
            break;
        case 22:
            o[0] = initObject(17,12,0);
            o[1] = blankObject();
            break;
        case 33:
            o[0] = initObject(28,16,0);
            o[1] = blankObject();
            break;
        default:
            o = NULL;
            break;
    }
    return o;
}

Object* healthCraft(int id){
    Object* o = malloc(sizeof(Object)*2);
    switch(id){
        case 15:
            o[0] = initObject(7,2,0);
            o[1] = blankObject();
            break;
        case 26:
            o[0] = initObject(18,2,0);
            o[1] = blankObject();
            break;
        case 34:
            o[0] = initObject(29,2,0);
            o[1] = blankObject();
            break;
        default:
            o = NULL;
            break;
    }
    return o;
}

Object* toolCraft(int id){
    Object* o = malloc(sizeof(Object)*2);
    if(id == 2 || id == 3 || id == 4){
        o[0] = initObject(5,3,0);
        o[1] = blankObject();
    }
    else if(id == 12 || id == 13 || id == 14){
        o[0] = initObject(5,2,0);
        o[1] = blankObject(6,3,0);
    }
    else if(id == 23 || id == 24 || id == 25){
        o[0] = initObject(16,2,0);
        o[1] = blankObject(17,4,0);
    }
    else{
        o = NULL;
    }
    return o;
}

Object* lanceCraft(int id){
    Object* o = malloc(sizeof(Object)*2);
    switch(id){
        case 9:
            o[0] = initObject(6,3,0);
            o[1] = blankObject(7,4,0);
            break;
        case 20:
            o[0] = initObject(16,3,0);
            o[1] = blankObject(17,5,0);
            break;
        case 31:
            o[0] = initObject(27,3,0);
            o[1] = blankObject(28,6,0);
            break;
        default:
            o = NULL;
            break;
    }
    return o;
}

Object* hammerCraft(int id){
    Object* o = malloc(sizeof(Object)*2);
    switch(id){
        case 10:
            o[0] = initObject(6,2,0);
            o[1] = blankObject(7,6,0);
            break;
        case 21:
            o[0] = initObject(16,2,0);
            o[1] = blankObject(17,7,0);
            break;
        case 32:
            o[0] = initObject(27,2,0);
            o[1] = blankObject(28,8,0);
            break;
        default:
            o = NULL;
            break;
    }
    return o;
}

void showCraft(Craft* c){
    for (int i =0;i<22;i++){
        printf("Craft numero %d\n",i+1);
        for(int comp = 0; comp < 2;comp++){
            printf("Composent numero %d : %d quantite : %d\n",comp+1,c[i].composent[comp].id,c[i].composent[comp].quantity);
        }
        printf("\n");
    }
}