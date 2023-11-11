//
// Created by Aymen on 18/10/2023.
//
#ifndef MALLOCWORLD_MONSTERS_H
#define MALLOCWORLD_MONSTERS_H
#include "player.h"

struct Monster{
    char* name;
    int pv;
    int experience;
};

typedef struct Monster Monster;

typedef struct Result
{
    Player player;
    Monster monster;
} Result;

int initMonster(int, Player p);
int combatMonstre(Monster *monster, Player *p);
int chooseArmeAfter(Player *p);
int chooseArme(Player *p);
void firstAttaque(Player *p, Monster *monster);
void attaque(Player *p, Monster *monster);
void afficherPointAttaque(Player *p, Monster *monster);
void chooseMenu();
void idArme(int);
int fuir(Player *p);
void sauvegarderHP(Player *p);
int chargerHPSauvegarde(Player *p);
void levelingHP(Player *p);
int verifyDurability(Player *p);
void levelZone();
int myLevel();
void showWeaponsInInventory(Player *p);
#endif //MALLOCWORLD_MONSTERS_H
