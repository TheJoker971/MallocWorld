//
// Created by Aymen on 29/09/2023.
//
#include "checkMovement.h"
#include <stdio.h>
#include <stdlib.h>

int checkMovement(int resultTab){
    char yesNo;
    int result = 0;

    switch (resultTab) {
        case 12:
            printf("\n\n\nVous venez de rencontrer un montre, voulez vous engager un combat ? (y/n)\n\n\n");
            break;
        case -1:
            printf("\n\n\nImpossible de franchir la case\n\n\n");
            result = 1;
            break;

        case 2:
            printf("\n\n\nHello, je suis le PNJ\n\n\n");
            break;

        case 3:
            printf("\n\n\nPlante\n\n\n");
            break;

        case 4:
            printf("\n\n\nRocher\n\n\n");
            break;

        case 5:
            printf("\n\n\nBois\n\n\n");
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
    return zone;
}
