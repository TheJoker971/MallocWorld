//
// Created by Aymen on 18/10/2023.
//
#ifndef MALLOCWORLD_MONSTERS_H
#define MALLOCWORLD_MONSTERS_H

struct Monster{
    char* name;
    int pv;
    int experience;
};

typedef struct Monster Monster;

void initMonster(int);
int combatMonstre(Monster);
#endif //MALLOCWORLD_MONSTERS_H
