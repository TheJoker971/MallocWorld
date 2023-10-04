//
// Created by Aymen on 04/10/2023.
//
#include <stdio.h>
#include <stdlib.h>
#include "zoneTravel.h"
#include "map.h"

void zoneTravel(int*** tab){
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (tab[1][i][j] == -2) {
                tab[1][i][j+1] = 1;
            }
        }
    }
}
