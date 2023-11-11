//
// Created by Aymen on 04/10/2023.
//
#include <stdio.h>
#include <stdlib.h>
#include "zoneTravel.h"
#include "map.h"

void zoneTravelRightZone1To2(int*** tab, int zone){
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (tab[zone][i][j] == -2) {
                tab[zone][i][j+1] = 1;
            }
        }
    }
}

void zoneTravelRightZone2To3(int*** tab, int zone){
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (tab[zone][i][j] == -3) {
                tab[zone][i][j+1] = 1;
            }
        }
    }
}

void zoneTravelLeftZone1To2(int*** tab, int zone){
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (tab[zone][i][j] == -2) {
                tab[zone][i][j-1] = 1;
            }
        }
    }
}

void zoneTravelLeftZone2To3(int*** tab, int zone){
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (tab[zone][i][j] == -3) {
                tab[zone][i][j-1] = 1;
            }
        }
    }
}

void zoneTravelDownZone1To2(int*** tab, int zone){
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (tab[1][i][j] == -2) {
                tab[1][i+1][j] = 1;
            }
        }
    }
}

void zoneTravelDownZone2To3(int*** tab, int zone){
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (tab[2][i][j] == -3) {
                tab[2][i+1][j] = 1;
            }
        }
    }
}

void zoneTravelUpZone1To2(int*** tab, int zone){
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (tab[zone][i][j] == -2) {
                tab[zone][i-1][j] = 1;
            }
        }
    }
}

void zoneTravelUpZone2To3(int*** tab, int zone){
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (tab[zone][i][j] == -3) {
                tab[zone][i-1][j] = 1;
            }
        }
    }
}
