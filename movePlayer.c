//
// Created by Aymen on 29/09/2023.
//
#include <stdio.h>
#include <stdlib.h>
#include "movePlayer.h"
#include "map.h"
#include "checkMovement.h"
#include "zoneTravel.h"

int zone = 0;

void movePlayer(int*** tab, char deplacement){

    switch (deplacement) {
        case 'z':
            moveUp(tab);
            drawMap(tab);
            break;

        case 'q':
            moveLeft(tab);
            drawMap(tab);
            break;

        case 'd':
            moveRight(tab);
            drawMap(tab);
            break;

        case 's':
            moveDown(tab);
            drawMap(tab);
            break;

        default:
            printf("ERROR\n");
            break;
    }
}

void moveUp(int*** tab){
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (tab[zone][i][j] == 1) {
                moveUpZone(tab, i, j);
            }
        }
    }
}

void moveDown(int*** tab){
    for (int i = 9; i >= 0; i--) {
        for (int j = 0; j < 10; j++) {
            if (tab[zone][i][j] == 1) {
                moveDownZone(tab, i, j);
            }
        }
    }
}

void moveLeft(int*** tab){
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (tab[zone][i][j] == 1) {
                moveLeftZone(tab, i, j);
            }
        }
    }
}

void moveRight(int*** tab){
    for (int i = 0; i <10; i++) {
        for (int j = 10; j >=0; j--) {
            if (tab[zone][i][j] == 1) {
                moveRightZone(tab, i, j);
            }
        }
    }
}

void moveRightZone(int*** tab,int i,int j){
    int resultTab = tab[zone][i][j+1];
    tab[zone][i][j] = 0;
    if(checkMovement(resultTab) == 2){
        zoneTravelRight(tab);
        zone = 1;
    } else{
        if(j<9){
            tab[zone][i][j+1] = 1;
        } else {
            tab[zone][i][j] = 1;
        }
    }
}


void moveLeftZone(int*** tab, int i, int j){
    int resultTab = tab[zone][i][j - 1];
    tab[zone][i][j] = 0;
    if(checkMovement(resultTab) == 2){
        zoneTravelLeft(tab);
        zone = 1;
    } else{
        printf("ELSE\n");
        if(j>0){
            tab[zone][i][j-1] = 1;
        } else if (j==0){
            tab[zone][i][j] = 1;
        }
    }
}

void moveUpZone(int*** tab,int i,int j){
    int resultTab = tab[0][i - 1][j];
    tab[zone][i][j] = 0;
    if(checkMovement(resultTab) == 2){
        zoneTravelUp(tab);
        zone = 1;
    } else {
        printf("ELSE\n");
        if(i != 0){
            tab[zone][i - 1][j] = 1;
        } else {
            tab[zone][0][j] = 1;
        }
    }
}

void moveDownZone(int*** tab, int i, int j){
    int resultTab = tab[zone][i + 1][j];
    tab[zone][i][j] = 0;
    if(checkMovement(resultTab) == 2){
        zone = 1;
        printf("ZONE : %d\n", zone);
        //tab[1][6][2] = 1;
        tab[1][1][2] = 1;
        drawMap(tab);
    }
    else {
        printf("ZONE__: %d\n", zone);
        if(i<9){
            tab[zone][i+1][j] = 1;
        } else {
            tab[zone][i][j] = 1;
        }
    }
}
