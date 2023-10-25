#include "player.h"
#include <stdio.h>
#include <stdlib.h>

Player initPlayer(){
    Player p;
    p.hp = 100;
    p.maxHp = 100;
    p.xp = 1;
    p.inventory = malloc(sizeof(Object)*10);
    initInventory(p.inventory);
    return p;
}

void initInventory(Object* tab){
    for(int i = 0;i < 10;i++){
        if(i<4){
            tab[i].id = i+1;
            tab[i].durability = 10;
            tab[i].quantity = 1;
        }else{
            tab[i].id = 0;
            tab[i].durability = 0;
            tab[i].quantity = 0;
            // tab[i] = NULL;
        }
    }
}

void showInventory(Player p){
    Object* inv = p.inventory;
    printf("------------------\tINVENTORY\t------------------\n");
    printf("|\tID\t|\tObject\t|\tQuantity\t |\n");
    printf("----------------------------------------------------------\n");
    for(int i = 0;i<10;i++){
        if(inv[i].id != 0){
            printf("|\t%d\t|\t%d\t|\t %02d (%02d) \t |\n",i+1,inv[i].id,inv[i].quantity,inv[i].durability);
            
        }else{
            printf("|\t%d\t|\t/\t|\t empty    \t |\n",i+1);
        }
        
    }
    printf("----------------------------------------------------------\n");
}

int addInventory(Object* inv,Object o){
    for(int i = 0;i<10;i++){
        if(stackable(&inv[i],&o)){
            if(inv[i].quantity + o.quantity <= 20){
                inv[i].quantity += o.quantity;
                break;
            }else if(inv[i].quantity + o.quantity < 40){
                o.quantity = (inv[i].quantity + o.quantity) % 20;
                inv[i].quantity = 20;
                continue;
            }
        }else{
            if(inv[i].id == 0){
                inv[i].id = o.id;
                inv[i].quantity = o.quantity;
                inv[i].durability = o.durability;
                break;
            }else{
                if (inv[9].quantity == 20)
                {
                    printf("\t-----\tInventory blind\t----- \n");
                    return 0;
                } 
            }
        }
    }   
    return 1;
}

void withdrawOfChest(Player p,Npc npc){
    Object o = withdrawObject(npc.chest);
    if(o.id != 0){
        addInventory(p.inventory,o);
    }
}


void storeInChest(Player p, Npc npc){
    showInventory(p);
    Object* o = NULL;
    int pos;
    while(pos ==0 || pos >10){
        printf("Veuillez saisir la position de l'objet a stocker : ");
        scanf("%d",&pos);
        o = &p.inventory[pos-1];
        getchar();
    }
    int amount = 0;
    if(o->quantity != 1){
        while(amount == 0 || amount > o->quantity){
            printf("Veuillez saisir la quantitee de l'objet a stocker : ");
            scanf("%d",&amount);
            getchar();
        }
        if(o->quantity - amount == 0){
            addObject(npc.chest,o);
        }else{
            o->quantity -= amount;
            Object add = initObject(o->id,amount,o->durability);
            addObject(npc.chest,&add);
        }
    }else{
        addObject(npc.chest,o);
    }
}


