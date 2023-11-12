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
    initSauvegarderHP(&p);
    return p;
}

void initInventory(Object* tab){
    for(int i = 0;i < 10;i++){
        if(i<4){
            tab[i].id = i+1;
            tab[i].durability = 10;
            tab[i].quantity = 1;
            tab[i].degats = 10;
        }else{
            tab[i].id = 0;
            tab[i].durability = 0;
            tab[i].quantity = 0;
            tab[i].degats = 0;
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
            printf("|\t%d\t|\t%d\t|\t %02d (%02d) %d \t |\n",i+1,inv[i].id,inv[i].quantity,inv[i].durability, inv[i].degats);

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
                inv[i].degats = o.degats;
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
            Object add = initObject(o->id,amount,o->durability, o->degats);
            addObject(npc.chest,&add);
        }
    }else{
        addObject(npc.chest,o);
    }
}

void initSauvegarderHP(Player *p) {
    FILE *file = fopen("sauvegarde_hp.txt", "w"); // Ouvre le fichier en mode écriture
    if (file == NULL) {
        printf("Erreur lors de l'ouverture du fichier de sauvegarde.\n");
        return;
    }
    fprintf(file, "%d", p->hp); // Écrit les HP du joueur dans le fichier
    fclose(file); // Ferme le fichier
    printf("Les points de vie ont été sauvegardés.\n");
}

void showWeaponsInInventory(Player *p) {
    printf("Armes dans l'inventaire :\n");
    printf("---------------------------- ARMES ----------------------\n");
    for (int i = 0; i < 10; i++) {
        if (isWeapon(p->inventory[i].id)) {
            printf("| Emplacement %02d | Arme ID %02d | Degats %02d | Durabilité %02d |\n", 
                   i + 1, p->inventory[i].id, p->inventory[i].degats, p->inventory[i].durability);
        }
    }
    printf("---------------------------------------------------------\n");
}