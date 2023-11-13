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
int compteur = 1;

void movePlayer(int*** tab, char deplacement, Player player, Npc npc){

    switch (deplacement) {
        case 'z':
            moveUp(tab, player, npc);
            drawMap(tab);
            break;

        case 'q':
            moveLeft(tab, player, npc);
            drawMap(tab);
            break;

        case 'd':
            moveRight(tab, player, npc);
            drawMap(tab);
            break;

        case 's':
            moveDown(tab, player, npc);
            drawMap(tab);
            break;

        default:
            printf("ERROR\n");
            break;
    }
}

//TOUS LES DÉPLACEMENT VERS LA GAUCHE
void moveLeft(int*** tab, Player p, Npc npc){
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (tab[zone][i][j] == 1) {
                int resultTab = tab[zone][i][j - 1];
                 if (compteur != 0 && checkCase(resultTab, p) != 0) {
                    moveLeftZone(tab, i, j, p, npc);
                } else compteur = 1;
            }
        }
    }
}

void moveLeftZone(int*** tab, int i, int j, Player p, Npc npc){
    int resultTab = tab[zone][i][j - 1];
    tab[zone][i][j] = 0;

    switch(checkMovement(resultTab, p, zone, npc)){
        case 2: 
            if (zone == 0){
            zone = 1;
            zoneTravelLeftZone1To2(tab, zone);
        } else if (zone == 1){
            compteur = 0;
            zone = 0;
            zoneTravelLeftZone1To2(tab, zone);
        }
            break;
        case 3:
            if (zone == 1) {
            zone = 2;
            zoneTravelLeftZone2To3(tab, zone);
        } else if(zone ==2){
            compteur = 0;
            zone = 1;
            zoneTravelLeftZone2To3(tab, zone);
        }
            break;

        case 1:
            tab[zone][i][j] = 1;
            break;

        default:
            if(j>0){
            tab[zone][i][j-1] = 1;
        } else if (j==0){
            tab[zone][i][j] = 1;
        }
    }

}

//TOUS LES DÉPLACEMENT VERS LA DROITE
void moveRight(int*** tab, Player p, Npc npc){
    for (int i = 0; i < height; i++) {
        for (int j = width; j >=0; j--) {
            int resultTab = tab[zone][i][j+1];
            if (tab[zone][i][j] == 1 && checkCase(resultTab, p) != 0) {
                if ( compteur != 0){
                    moveRightZone(tab, i, j, p, npc);
                } else compteur = 1;
            }
        }
    }
}

void moveRightZone(int*** tab,int i,int j, Player p, Npc npc){
    int resultTab = tab[zone][i][j+1];
    tab[zone][i][j] = 0;

    switch(checkMovement(resultTab, p, zone, npc)){
        case 2: 
            if (zone == 0){
            zone = 1;
            zoneTravelRightZone1To2(tab, zone);
        } else if (zone == 1){
            compteur = 0;
            zone = 0;
            zoneTravelRightZone1To2(tab, zone);
        }
            break;

        case 3:
            if (zone == 1){
            zone = 2;
            zoneTravelRightZone2To3(tab, zone);
        } else if (zone == 2){
            compteur = 0;
            zone = 1;
            zoneTravelRightZone2To3(tab, zone);
        }
            break;

        case 1:
            tab[zone][i][j] = 1;
            break;

        default:
            if(j<9){
            tab[zone][i][j+1] = 1;
        } else {
            tab[zone][i][j] = 1;
        }
            break;
    }    
}


//TOUS LES DÉPLACEMENT VERS LE HAUT
void moveUp(int*** tab, Player p, Npc npc){
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (tab[zone][i][j] == 1 ) {
                if ( compteur != 0) {
                    moveUpZone(tab, i, j, p, npc);
                } else compteur = 1;
            }
        }
    }
}

void moveUpZone(int*** tab,int i,int j, Player p, Npc npc){
    if( i > 1){
        int resultTab = tab[zone][i - 1][j];
        if(checkCase(resultTab, p) != 0){
            moveUpZoneInside(tab, i, j, p, npc);
        }
    } else{
        int resultTab = tab[zone][0][j];
        if(checkCase(resultTab, p) != 0){
            moveUpZoneBorder(tab, i, j, p, npc);
        }
    }
}

void moveUpZoneInside(int*** tab, int i, int j, Player p, Npc npc){
    int resultTab = tab[zone][i - 1][j];
    tab[zone][i][j] = 0;

    switch(checkMovement(resultTab, p, zone, npc)){
        case 2: 
            if (zone == 0){
            zone = 1;
            zoneTravelUpZone1To2(tab, zone);
        } else if (zone == 1){
            compteur = 0;
            zone = 0;
            zoneTravelUpZone1To2(tab, zone);
        }
            break;

        case 3:
            if (zone == 1){
            zone = 2;
            zoneTravelUpZone2To3(tab, zone);
        } else if (zone == 2){
            compteur = 1;
            zone = 0;
            zoneTravelUpZone2To3(tab, zone);
        }
            break;

        case 1:
            tab[zone][i][j] = 1;
            break;

        default:
            tab[zone][i - 1][j] = 1;
            break;
    } 
}

void moveUpZoneBorder (int*** tab, int i, int j, Player p, Npc npc){
    int resultTab = tab[zone][0][j];
    tab[zone][i][j] = 0;

    switch(checkMovement(resultTab, p, zone, npc)){
        case 2: 
            if (zone == 0){
            zone = 1;
            zoneTravelUpZone1To2(tab, zone);
        } else if (zone == 1){
            compteur = 0;
            zone = 0;
            zoneTravelUpZone1To2(tab, zone);
        }
            break;

        case 3:
            if (zone == 1){
            zone = 2;
            zoneTravelUpZone2To3(tab, zone);
        } else if (zone == 2){
            compteur = 0;
            zone = 1;
            zoneTravelUpZone2To3(tab, zone);
        }
            break;

        case 1:
            tab[zone][i][j] = 1;
            break;

        default:
            tab[zone][i][j] = 0;
            tab[zone][height - height][j] = 1;
            break;
    } 
}






// TOUS LES DÉPLACEMENTS VERS LE BAS
void moveDown(int*** tab, Player p, Npc npc){
    for (int i = height-1; i >= 0; i--) {
        for (int j = 0; j < width; j++) {
            if (tab[zone][i][j] == 1 ) {
                if ( compteur != 0){
                    moveDownZone(tab, i, j, p, npc);
                } else compteur = 1;
            }
        }
    }
}

void moveDownZone(int*** tab, int i, int j, Player p, Npc npc){
        if (i < height - 2){
            int resultTab = tab[zone][i + 1][j];
            if(checkCase(resultTab, p) != 0) {
                moveDownZoneInside(tab, i, j, p, npc);
            }
        } else {
            int resultTab = tab[zone][height - 1][j];
            if(checkCase(resultTab, p) != 0) {
                moveDownZoneBorder(tab, i, j, p, npc);
            }
        }
}

void moveDownZoneInside(int*** tab, int i, int j, Player p, Npc npc){
    int resultTab = tab[zone][i + 1][j];
    tab[zone][i][j] = 0;

    switch(checkMovement(resultTab, p, zone, npc)){
        case 2: 
            if (zone == 0) {
            zone = 1;
            zoneTravelDownZone1To2(tab, zone);
        } else if (zone == 1) {
            compteur = 0;
            zone = 0;
            zoneTravelDownZone1To2(tab, zone);
        }
            break;

        case 3:
            if (zone == 1) {
            compteur = 0;
            zone = 2;
            zoneTravelDownZone2To3(tab, zone);
        } else if (zone == 2) {
            compteur = 0;
            zone = 1;
        }
            break;

        case 1:
            tab[zone][i][j] = 1;
            break;

        default:
           tab[zone][i+1][j] = 1;
            break;
    } 
}

void moveDownZoneBorder(int*** tab, int i , int j, Player p, Npc npc){
    int resultTab = tab[zone][height - 1][j];
    tab[zone][i][j] = 0;

    switch(checkMovement(resultTab, p, zone, npc)){
        case 2: 
            if (zone == 0) {
            compteur = 0;
            zone = 1;
            zoneTravelDownZone1To2(tab, zone);
        } else if (zone == 1) {
            compteur = 0;
            zone = 0;
            zoneTravelDownZone1To2(tab, zone);
        }
            break;

        case 3:
            if (zone == 1) {
            compteur = 0;
            zone = 2;
            zoneTravelDownZone2To3(tab, zone);
        } else if (zone == 2) {
            compteur = 0;
            zone = 1;
            zoneTravelDownZone2To3(tab, zone);
        }
            break;

        case 1:
            tab[zone][i][j] = 1;
            break;

        default:
            tab[zone][height - 1][j] = 1;
            break;
    } 
}

