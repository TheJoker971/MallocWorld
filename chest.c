#include "chest.h"
#include <stdio.h>
#include <stdlib.h>

Chest* initChest(){
    Chest* chest = malloc(sizeof(Chest));
    chest->object = blankObject();
    chest->next = NULL;
    return chest;
}

Chest* newObject(Object* o){
    Chest* c = malloc(sizeof(Chest));
    c->object = initObject(o->id,o->quantity,o->durability);
    c->next = NULL;
    resetObject(o);
    return c;
}


void addObject(Chest* chest,Object* o){
    Chest* c = chest; 
    if(c->object.id == 0){
        c->object = initObject(o->id,o->quantity,o->durability);
        resetObject(o);
    }else{
        while(c != NULL){
            if(stackable(&c->object,o) && c->object.quantity < 20){
                if(c->object.quantity + o->quantity <= 20){
                    c->object.quantity += o->quantity;
                    resetObject(o);
                }else{
                    o->quantity = (o->quantity + c->object.quantity) % 20;
                    c->object.quantity = 20;
                    if(c->next == NULL){
                        c->next = newObject(o);
                    }
                }
            }else{
                if(c->next == NULL && o->id != 0){
                    c->next = newObject(o);
                }
            }
            c = c->next;
        }
    }
}

Object* getObject(Chest* chest,int id){
    Chest* c = chest;
    int i = 1;
    if(id == 1){
        return &c->object;
    }else{
        while(c != NULL){
            if(i == id && c->object.id != 0){
                return &c->object;
            }
            i++;
            c = c->next;
            
        }
    }

}

void showChest(Chest* chest){
    Chest* c = chest;
    printf("---------------\t CHEST\t---------------\n");
    printf("|\tID\t|\t quantity\t|\n");
    printf("-----------------------------------------\n");
    do{
        if(c->object.id != 0){
            printf("|\t%02d\t|\t%02d (%02d) \t|\n",c->object.id,c->object.quantity,c->object.durability);
        }
        else if(c->object.id == 0 && c->next == NULL){
            printf("|\t  \t|\t        \t|\n");
        }
        
        c = c->next;
    }while(c != NULL);
    printf("-----------------------------------------\n");
}