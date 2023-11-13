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
            //pnjMenu(p, npc);
            break;

        case 3:
            printf("\n\n\nPlante\n\n\n");
            // addInventory(Object*,Object) Object* = Player.inventory, Object = initObject(id,quantity)
            addInventory(p.inventory, initObject(7,nb));
            showInventory(p);
            break;

        case 4:
            printf("\n\n\nPierre\n\n\n");
            addInventory(p.inventory, initObject(6,nb));
            break;

        case 5:
            printf("\n\n\nSapin\n\n\n");
            addInventory(p.inventory, initObject(5,nb));
            break;

        case 6:
            printf("\n\n\nLavande\n\n\n");
            addInventory(p.inventory, initObject(18,nb));
            showInventory(p);
            break;

        case 7:
            printf("\n\n\nFer\n\n\n");
            addInventory(p.inventory, initObject(17,nb));
            showInventory(p);
            break;

        case 8:
            printf("\n\n\nHetre\n\n\n");
            addInventory(p.inventory, initObject(16,nb));
            showInventory(p);
            break;

        case 9:
            printf("\n\n\nChanvre\n\n\n");
            addInventory(p.inventory, initObject(29,nb));
            showInventory(p);
            break;

        case 10:
            printf("\n\n\nDiamant\n\n\n");
            addInventory(p.inventory, initObject(28,nb));
            showInventory(p);
            break;

        case 11:
            printf("\n\n\nChene\n\n\n");
            addInventory(p.inventory, initObject(27,nb));
            showInventory(p);
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


int checkCase(int resultTab, Player player){
    char yesNo;
    int result;

    if (resultTab >= 12 && resultTab <= 98){
        result = initMonster(resultTab, player);
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
    printf("Que veux-tu faire ?");
    switch (menuChoice) {
        case 37:
            break;
        default:
            break;
    }


// repair 
// repair(p.inventory)

//craft
// craftObject(npc.crafts, p)

}