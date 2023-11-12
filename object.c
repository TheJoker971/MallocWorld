#include "object.h"
#include <stdio.h>
#include <stdlib.h>

int stackable(Object* o,Object* ob){
    if(o->id == ob->id){
        if(isCraft(o->id)){
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
    return o;
}

Object initObject(int id,int q, int d, int g){
    Object o;
    o.id = id;
    if(isCraft(o.id)){
        o.durability = 0;
        o.quantity = q;
        o.degats = 0;
        return o;
    }else{
        o.durability = d;
        o.quantity = 1;
        o.degats = g;
        return o;
    }
}

 int isWeapon(int id){
     int ids[] = {1,2,3,4,8,9,10,19,20,21,30,31,32};
     for(int i =0;i<13;i++){
         if(id == ids[i]){
             return 1;
         }
     }
    return 0;
 }

int isCraft(int id){
    int ids[] = {5,6,7,16,17,18,27,28,29};
    for(int i =0;i<13;i++){
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
}

int isPickAxe(int id){
    int ids[]= {2,12,23};
    for(int i = 0;i<3;i++){
        if(id == ids[i]){
            return 1;
        }
    }
    return 0;
}

int isBillHook(int id){
    int ids[]= {3,13,24};
    for(int i = 0;i<3;i++){
        if(id == ids[i]){
            return 1;
        }
    }
    return 0;
}

int isAxe(int id){
    int ids[]= {4,14,25};
    for(int i = 0;i<3;i++){
        if(id == ids[i]){
            return 1;
        }
    }
    return 0;
}