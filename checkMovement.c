//
// Created by Aymen on 29/09/2023.
//
#include "checkMovement.h"
#include <stdio.h>
#include <stdlib.h>

void checkMovement(int resultTab){
    char yesNo;

    switch (resultTab) {
        case 12:
            printf("\n\n\nVous venez de rencontrer un montre, voulez vous engager un combat ? (y/n)\n\n\n");
            break;
        case -1:
            printf("\n\n\nImpossible de franchir la case\n\n\n");
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
    }

}
