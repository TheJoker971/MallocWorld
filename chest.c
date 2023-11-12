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
    c->object = initObject(o->id,o->quantity);
    c->next = NULL;
    resetObject(o);
    return c;
}


void addObject(Chest* chest,Object* o){
    Chest* c = chest; 
    if(c->object.id == 0){
        c->object = initObject(o->id,o->quantity);
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

Chest* getObject(Chest* chest,int id){
    Chest* c = chest;
    int i = 1;
    while(c != NULL){
        if(i == id && c->object.id != 0){
            return c;
        }
        i++;
        c = c->next;
    }
    return NULL;

}

void deleteChain(Chest* c, int id){
    Chest* now = getObject(c,id);
    if(id != 1){
        Chest* last = getObject(c,id-1);
        last->next = now->next;
        free(now);
    }else{
        if(now->next->object.id <32 && now->next->object.id > 0 ){
            now->object = now->next->object;
        }
        if(now->next != NULL){
            now->next = now->next->next;
        }
    }
}

Object withdrawObject(Chest* c){
    Chest* chain = NULL;
    Object ob;
    int id = 0;
    do{
        printf("Enter position of the Object you would like withdraw of the chest : \n");
        scanf("%d",&id);
        chain = getObject(c,id);
    }while(chain == NULL);
    if(chain->object.quantity == 1){
        ob = initObject(chain->object.id,chain->object.quantity);
        deleteChain(c,id);
    }else{
        int amount = 0;
        do{
            printf("Enter position of the Object you would like withdraw of the chest : \n");
            scanf("%d",&amount);
        }while(amount == 0 && amount >chain->object.quantity);
        if(chain->object.quantity - amount > 0){
            chain->object.quantity -= amount;
            ob = initObject(chain->object.id,amount);
        }else{
            ob = initObject(chain->object.id,chain->object.quantity);
            deleteChain(c,id);
        }
    }
    return ob;
}

void showChest(Chest* chest){
    Chest* c = chest;
    printf("--------------------\t CHEST\t--------------------\n");
    printf("|\tID\t|\tObject\t|\tQuantity\t |\n");
    printf("----------------------------------------------------------\n");
    int i = 1;
    do{
        if(c->object.id != 0){
            printf("|\t%d\t|\t%d\t|\t %02d (%02d) \t |\n",i,c->object.id,c->object.quantity,c->object.durability);
        }
        else if(c->object.id == 0 && c->next == NULL){
            printf("|\t \t|\t \t|\t          \t |\n",i+1);
        }
        i++;
        c = c->next;
    }while(c != NULL);
    printf("----------------------------------------------------------\n");
}

void freeChest(Chest* chest){
    Chest* current = chest;
    while(current != NULL){
        Chest* next = current->next;
        free(current);
        current = next;
    }
}