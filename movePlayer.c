//
// Created by Aymen on 29/09/2023.
//
#include <stdio.h>
#include <stdlib.h>
#include "movePlayer.h"
#include "map.h"
#include "checkMovement.h"
void movePlayer(int** tab, char deplacement){


    switch (deplacement) {
        case 'z':
            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 10; j++) {
                    if (tab[i][j] == 1) {
                        int resultTab = tab[i - 1][j];
                        checkMovement(resultTab);
                        tab[i][j] = 0;
                        if(i > 0){
                            tab[i - 1][j] = 1;
                        } else{
                            tab[i][j] = 1;
                        }
                    }
                }
            }
            draw(tab);
            break;

        case 'q':
            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 10; j++) {
                    if (tab[i][j] == 1) {
                        int resultTab = tab[i][j - 1];
                        checkMovement(resultTab);
                        tab[i][j] = 0;
                        if(j>0){
                            tab[i][j-1] = 1;
                        } else if (j==0){
                            tab[i][j] = 1;
                        }
                    }
                }
            }
            draw(tab);
            break;

        case 'd':
            for (int i = 0; i <10; i++) {
                for (int j = 10; j >=0; j--) {

                    if (tab[i][j] == 1) {
                        int resultTab = tab[i][j+1];
                        checkMovement(resultTab);
                        tab[i][j] = 0;
                        if(j<9){
                            tab[i][j+1] = 1;
                        } else {
                            tab[i][j] = 1;
                        }
                    }
                }
            }
            draw(tab);
            break;

        case 's':
            for (int i = 9; i >= 0; i--) {
                for (int j = 0; j < 10; j++) {
                    if (tab[i][j] == 1) {
                        int resultTab = tab[i + 1][j];
                        checkMovement(resultTab);
                        tab[i][j] = 0;
                        if(i<9){
                            tab[i+1][j] = 1;
                        } else{
                            tab[i][j] = 1;
                        }
                    }
                }

            }
            draw(tab);
            break;

        default:
            printf("ERROR\n");
            break;
    }
}
