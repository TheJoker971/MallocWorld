#include "player.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


Player initPlayer(){
    Player p;
    p.hp = 100;
    p.level = 1;
    p.maxHp = 100;
    p.xp = 1;
    p.xpNext = p.xp * 10;
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
                inv[i] = o;
                
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

void savePlayer(Player p,Chest* chest){
    char name[10];
    char path[]="./saves/";
    printf("Entrer le nom de la sauvegarde : ");
    scanf("%s",name);
    strcat(name,".txt"),strcat(path,name);
    FILE* f = fopen(path,"w+");
    fprintf(f,"=== PLAYER ===\n");
    fprintf(f,"{%d}\n",p.level);
    fprintf(f,"{%d}/{%d}\n",p.xp,p.xpNext);
    fprintf(f,"-- INVENTORY --\n");
    for(int i = 0;i<10;i++){
        Object o = p.inventory[i];
        fprintf(f,"{%d}@{%d}@{%d}\n",o.quantity,o.id,o.durability);
    }
    fprintf(f,"-- STORAGE --\n");
    Chest* current = chest;
    while(current != NULL){
        Object o = current->object;
        if(o.id != 0){
            fprintf(f,"{%d}@{%d}\n",o.quantity,o.id);
        }
        current = current->next;
    }
    fclose(f);
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
                   i + 1, p->inventory[i].id, p->inventory[i].damage, p->inventory[i].durability);
        }
    }
    printf("---------------------------------------------------------\n");
}

void showToolsInInventory(Player *p) {
    printf("Outils dans l'inventaire :\n");
    printf("---------------------------- OUTILS ----------------------\n");
    for (int i = 0; i < 10; i++) {
        if (isTools(p->inventory[i].id)) {
            printf("| Emplacement %02d | Outil ID %02d | Degats %02d | Durabilité %02d |\n", 
                   i + 1, p->inventory[i].id, p->inventory[i].damage, p->inventory[i].durability);
        }
    }
    printf("---------------------------------------------------------\n");
}

void showPotionInInventory(Player *p){
    printf("Potions dans l'inventaire :\n");
    printf("---------------------------- POTIONS -------------\n");
    for (int i = 0; i < 10; i++) {
        if (isHealth(p->inventory[i].id)) {
            printf("| Emplacement %02d | Potion ID %02d | Quantité %02d |\n", 
                   i + 1, p->inventory[i].id, p->inventory[i].quantity);
        }
    }
    printf("--------------------------------------------------\n");
}