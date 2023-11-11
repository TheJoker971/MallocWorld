#include "object.h"
#include <stdio.h>
#include <stdlib.h>

int stackable(Object* o,Object* ob){
    if(o->id == ob->id){
        if(isRessource(o->id)){
            return 1;
        }
    }
    return 0;
}

Object blankObject(){
    Object o; 
    o.id = 0;
    o.durability = 0;
    o.quantity = 0;
    o.damage = 0;
    return o;
}

Object initObject(int id,int q){
    Object tab[] = {
        ressource(id,q),
        sword(id),
        lance(id),
        hammer(id),
        health(id),
        armor(id),
        tool(id)
    };
    for(int i = 0;i<8;i++){
        if(tab[i].id != 0){
            return tab[i];
        }
    }
}

int isRessource(int id){
    int ids[] = {5,6,7,16,17,18,27,28,29};
    for(int i =0;i<9;i++){
        if(id == ids[i]){
            return 1;
        }
    }
    return 0;
}

void resetObject(Object* o){
    o->id = 0;
    o->durability = 0;
    o->quantity = 0;
    o->damage = 0;
}

int isWeapon(int id){
    int ids[] = {1,8,9,10,19,20,21,30,31,32};
    for(int i =0;i<13;i++){
        if(id == ids[i]){
            return 1;
        }
    }
    return 0;
}

int isArmor(int id){
    int ids[] = {11,22,33};
    for(int i =0;i<3;i++){
        if(id == ids[i]){
            return 1;
        }
    }
    return 0;
}

int isHealth(int id){
    int ids[] = {15,26,34};
    for(int i =0;i<3;i++){
        if(id == ids[i]){
            return 1;
        }
    }
    return 0;
}

int isTools(int id){
    int ids[] = {2,3,4,12,13,14,23,24,25};
    for(int i =0;i<9;i++){
        if(id == ids[i]){
            return 1;
        }
    }
    return 0;
}

Object ressource(int id,int q){
    Object o;
    if(isRessource(id)){
        o.id = id;
        o.durability = 0;
        o.quantity = q;
        o.damage = 0;
    }else{
        o = blankObject();
    }
    return o;
}

Object sword(int id){
    Object o;
    o.id = id;
    o.durability = 10;
    o.quantity = 1;
    switch(id){
        case 1:
            o.damage = 1;
            break;
        case 8:
            o.damage = 2;
            break;
        case 19:
            o.damage = 5;
            break;
        case 30:
            o.damage = 10;
            break;
        default:
            o = blankObject();
            break;
    }
    return o;
}

Object tool(int id){
    Object o;
    if(isTools(id)){
        o.id = id;
        o.durability = 10;
        o.quantity = 1;
        o.damage = 0;
    }else{
        o = blankObject();
    }
    return o;
}

Object lance(int id){
    Object o;
    o.id = id;
    o.durability = 5;
    o.quantity = 1;
    switch(id){
        case 9:
            o.damage = 4;
            break;
        case 20:
            o.damage = 10;
            break;
        case 31:
            o.damage = 20;
            break;
        default:
            o = blankObject();
            break;
    }
    return o;
}

Object hammer(int id){
    Object o;
    o.id = id;
    o.durability = 5;
    o.quantity = 1;
    switch(id){
        case 10:
            o.damage = 4;
            break;
        case 21:
            o.damage = 10;
            break;
        case 32:
            o.damage = 20;
            break;
        default:
            o = blankObject();
            break;
    }
    return o;
}

Object armor(int id){
    Object o;
    if(isArmor(id)){
        o.id = id;
        o.durability = 0;
        o.quantity = 1;
        o.damage = 0;
    }else{
        o = blankObject();
    }
    return o;
}

Object health(int id){
    Object o;
    if(isHealth(id)){
        o.id = id;
        o.durability = 0;
        o.quantity = 1;
        o.damage = 0;
    }else{
        o = blankObject();
    }
    return o;
}
