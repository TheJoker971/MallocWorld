//
// Created by Aymen on 18/10/2023.
//
#include <stdio.h>
#include <stdlib.h>
#include "monsters.h"

void initMonster(int id) {
    if (id >= 12 && id < 20) {
        Monster demon;
        demon.name = "Cyclope";
        demon.pv = 100;
        demon.experience = 5;
        printf("LE monstre s'appelle : %s\n", demon.name);
        if (combatMonstre(demon) == 0) {
            printf("Le monstre est mort\n");
        }
    } else if (id >= 20 && id < 40){
        Monster demon;
        demon.name = "Monstre de feu";
        demon.pv = 150;
        demon.experience = 10;
        printf("LE monstre s'appelle : %s", demon.name);
    } else if (id >= 40 && id < 60){
        Monster demon;
        demon.name = "Monstre d'eau";
        demon.pv = 200;
        demon.experience = 15;
        printf("LE monstre s'appelle : %s", demon.name);
    } else if (id >= 60 && id < 99){
        Monster demon;
        demon.name = "Monstre de terre";
        demon.pv = 250;
        demon.experience = 20;
        printf("LE monstre s'appelle : %s", demon.name);
    }
}

int combatMonstre(Monster monster) {
    char yesNo;
    while (monster.pv != 0){
        printf("Veux tu lui mettre encore un coup ? (y/n)\n");
        scanf("%c", &yesNo);
        if (yesNo == 'y') {
            monster.pv = monster.pv - 10;
        } else {
            continue;
        }
        printf("Il lui reste %d point de vie\n", monster.pv);
        getchar();
    }
    return monster.pv;
}
