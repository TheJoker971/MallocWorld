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
            tab[i] = initObject(i+1,2);
        }else{
            tab[i] = blankObject();
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
                return 1;
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
                return 1;
            }
        }
    }   
    printf("Impossible your inventory is blind!\n");
    return 0;
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
            Object add = initObject(o->id,amount);
            addObject(npc.chest,&add);
        }
    }else{
        addObject(npc.chest,o);
    }
}

void withdrawInventory(Player p, Object o){
    Object* inv = p.inventory;
    for(int i =9;i>-1;i--){
        if(inv[i].id == o.id && inv[i].quantity >= o.quantity){
            inv[i].quantity -= o.quantity;
            if(inv[i].quantity == 0){
                resetObject(&inv[i]);
            }
        }
    }    
}

void craftObject(Craft* c,Player p){
    canCraft(c,p.inventory);
    int id = -1;
    do{
        printf("Please enter the id of the item you want craft : ");
        scanf("%d",&id);
    }while(id == -1 && !haveComponent(c[id-1].composent,p.inventory));
    for(int i =0;i<2;i++){
        withdrawInventory(p,c[id-1].composent[i]);
    }
    Object o;
    if(!addInventory(p.inventory,initObject(c[id-1].id,1))){
        for(int i =0;i<2;i++){
            addInventory(p.inventory,c[id-1].composent[i]);
        }
    }
}

void freePlayer(Player p){
    free(p.inventory);
}



