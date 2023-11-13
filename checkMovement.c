//
// Created by Aymen on 29/09/2023.
//
#include "checkMovement.h"
#include <stdio.h>
#include <time.h>
#include "movePlayer.h"
#include <stdlib.h>
#include "monsters.h"
#include "player.h"
#include "npc.h"

int degat;
int outil = 0;

int checkMovement(int resultTab, Player p, int zone, Npc npc){
    char yesNo;
    int result = 0;
    srand((unsigned int)time(NULL));
    int nb = rand() % 5;

    switch (resultTab) {
        case -1:
            printf("\n\n\nImpossible de franchir la case\n\n\n");
            result = 1;
            break;

        case 2:
            printf("\n\n\nHello, je suis le PNJ\n\n\n");
            pnjMenu(p, npc);
            break;

        case 3:
            printf("\n\n\nPlante\n\n\n");
            chooseTool(&p);
            if(isBillHook(p.inventory[outil].id) == 1){
                craft(&p, zone);
                addInventory(p.inventory, initObject(7,nb));
            } else {
                printf("Vous ne pouvez pas recolter avec cette outil\n");
                result = 1;
            }
            showInventory(p);
            break;

        case 4:
            printf("\n\n\nPierre\n\n\n");
            chooseTool(&p);
            if(isPickAxe(p.inventory[outil].id) == 1){
                craft(&p, zone);
                addInventory(p.inventory, initObject(6,nb));
            } else {
                printf("Vous ne pouvez pas recolter avec cette outil\n");
                result = 1;
            }
            showInventory(p);
            break;

        case 5:
            printf("\n\n\nSapin\n\n\n");
            chooseTool(&p);
            if(isAxe(p.inventory[outil].id) == 1){
                craft(&p, zone);
                addInventory(p.inventory, initObject(5,nb));
            } else {
                printf("Vous ne pouvez pas recolter avec cette outil\n");
                result = 1;
            }
            showInventory(p);
            //addInventory(p.inventory, initObject(5,nb));
            break;

        case 6:
            printf("\n\n\nLavande\n\n\n");
            chooseTool(&p);
            if(outil == 11 || outil == 22){
                if(isBillHook(p.inventory[outil].id) == 1){
                craft(&p, zone);
                addInventory(p.inventory, initObject(18,nb));
                } else {
                printf("Vous ne pouvez pas recolter avec cette outil\n");
                result = 1;
                }
                showInventory(p);
            }
            //addInventory(p.inventory, initObject(18,nb));
            break;

        case 7:
            printf("\n\n\nFer\n\n\n");
            chooseTool(&p);
            if(outil == 12 || outil == 23){
                if(isPickAxe(p.inventory[outil].id) == 1){
                craft(&p, zone);
                addInventory(p.inventory, initObject(17,nb));
                } else {
                printf("Vous ne pouvez pas recolter avec cette outil\n");
                result = 1;
                }
                showInventory(p);
            }
            //addInventory(p.inventory, initObject(17,nb));
            break;

        case 8:
            printf("\n\n\nHetre\n\n\n");
            chooseTool(&p);
            if(outil == 13 || outil == 24){
                if(isAxe(p.inventory[outil].id) == 1){
                craft(&p, zone);
                addInventory(p.inventory, initObject(16,nb));
                } else {
                printf("Vous ne pouvez pas recolter avec cette outil\n");
                result = 1;
                }
                showInventory(p);
            }
            // addInventory(p.inventory, initObject(16,nb));
            break;

        case 9:
            printf("\n\n\nChanvre\n\n\n");
            chooseTool(&p);
            if(outil == 22){
                if(isBillHook(p.inventory[outil].id) == 1){
                craft(&p, zone);
                addInventory(p.inventory, initObject(29,nb));
                } else {
                printf("Vous ne pouvez pas recolter avec cette outil\n");
                result = 1;
                }
                showInventory(p);
            }
            
            // addInventory(p.inventory, initObject(29,nb));
            break;

        case 10:
            printf("\n\n\nDiamant\n\n\n");
            chooseTool(&p);
            if(outil == 23){
                if(isPickAxe(p.inventory[outil].id) == 1){
                craft(&p, zone);
                addInventory(p.inventory, initObject(28,nb));
                } else {
                printf("Vous ne pouvez pas recolter avec cette outil\n");
                result = 1;
                }
                showInventory(p);
            }
            // addInventory(p.inventory, initObject(28,nb));
            break;

        case 11:
            printf("\n\n\nChene\n\n\n");
            chooseTool(&p);
            if(outil == 24){
                if(isAxe(p.inventory[outil].id) == 1){
                craft(&p, zone);
                addInventory(p.inventory, initObject(27,nb));
                } else {
                printf("Vous ne pouvez pas recolter avec cette outil\n");
                result = 1;
                }
                showInventory(p);
            }
            // addInventory(p.inventory, initObject(27,nb));
            break;

        case -2:
            printf("\n\n\nPORTAIL ZONE 2\n\n\n");
            result = 2;
            break;

        case -3:
            printf("\n\n\nPORTAIL ZONE 3\n\n\n");
            result = 3;
            break;

        default:
            printf("\n ERREUR \n");
            break;
    }
    return result;
}


int checkCase(int resultTab, Player player, int zone){
    char yesNo;
    int result;

    if (resultTab >= 12 && resultTab <= 98){
        result = initMonster(resultTab, player, zone);
    } else if ( resultTab == -1) {
        result = 0;
    } else if ( resultTab == -2) {
        result = portailOpenClose1(result);
    } else if ( resultTab == -3) {
        result = portailOpenClose2(result);
    } else {
        result = 1;
    }
    /*switch (resultTab) {
        case 37:
            while (yesNo != 'y' && yesNo != 'n') {
                printf("Vous venez de rencontrer un montre, voulez vous le tuer ? (y/n)\n");
                scanf(" %c", &yesNo);

                if (yesNo == 'y') {
                    printf("Monstre tué");
                    result = 1;
                } else if (yesNo == 'n'){
                    printf("Monstre non tué");
                    result = 0;
                } else {
                    printf("Entrée non valide. Veuillez réessayer.\n");
                }
            }
            break;

        case 51:
            initMonster(resultTab, player);
            break;

        case 17:
            initMonster(resultTab, player);
            break;

        case -1:
            result = 0;
            break;

        default:
            result = 1;
            break;
    }*/

    return result;
}

int portailOpenClose1(int result){
    if(myLevel() >= 3){
            result = 1;
        } else {
            result = 0;
        }
        return result;
}

int portailOpenClose2(int result){
    if(myLevel() >= 7){
            result = 1;
        } else {
            result = 0;
        }
        return result;
}

void pnjMenu(Player p, Npc npc){
    int menuChoice;
    printf("Que veux-tu faire ?\n(1)Reparer\n(2)Crafter\n");
    scanf("%d", &menuChoice);
    getchar();

    /*if(menuChoice == 1){
        repair(p.inventory);
    } else if(menuChoice == 2){
        craftObject(npc.crafts, p);
    }*/


    switch (menuChoice) {
        case 1:
            repair(p.inventory);
            break;

        case 2:
            craftObject(npc.crafts, p);
            break;

        default:
            printf("Erreur\n");
            break;
    }
// repair 
// repair(p.inventory)

//craft
// craftObject(npc.crafts, p)

}

void craft(Player *p, int zone){
    if (p->inventory[outil].durability > 0 && zone == 0){
        printf("Tu recolte !\n");
        p->inventory[outil].durability = p->inventory[outil].durability - (1);
    } else if (p->inventory[outil].durability > 0 && zone == 1){
        printf("Tu recolte !\n");
        p->inventory[outil].durability = p->inventory[outil].durability - (2);
    } else if (p->inventory[outil].durability > 0 && zone == 2){
        printf("Tu recolte !\n");
        p->inventory[outil].durability = p->inventory[outil].durability - (4);
    } else if (p->inventory[outil].durability <= 0){
        printf("\nVotre outil est cassé\n");
        chooseTool(p);
        //chooseArmeAfter(p);
    }
}

int chooseTool(Player *p){
    if(verifyDurability(p) == 1){
        printf("Vous n'avez plus aucun outil\n");
        return 1;
    }
    verifyDurabilityTool(p);
    showToolsInInventory(p);
    //showInventory(*p);

    int isValidInput;
    do {
        printf("Quelle outil veux-tu ? (Entrez un nombre) :\n");
        isValidInput = scanf("%d", &outil);

        // Vider le buffer d'entrée si l'utilisateur n'a pas entré un nombre
        if (!isValidInput) {
            printf("Erreur de saisie. Veuillez entrer un nombre.\n");
            while (getchar() != '\n'); 
            continue;
        }

        outil -= 1;

        // Vérifier si l'entrée correspond à un outil valide
        if (outil < 0 || !isTools(p->inventory[outil].id)) {
            printf("Ce n'est pas un outil valide. Veuillez ressaisir.\n");
            isValidInput = 0; // Réinitialiser la validité de l'entrée
        }
    } while (!isValidInput);

    // Mettre à jour les dégâts et la durabilité de l'arme choisie
    degat = p->inventory[outil].damage;
    printf("--------------------\n");
    printf("| %d de degats     |\n", degat);
    printf("| %d de durabilité |\n", p->inventory[outil].durability);
    printf("--------------------\n\n");

    return 0;
}

int verifyDurabilityTool(Player *p){
    for(int i = 0; i<10; i++){
        if(isTools(p->inventory[i].id)){
            if(p->inventory[i].durability > 0){
                return 0;
            } 
        }
    }
    return 1;
}