#ifndef PLAYER_H
#define PLAYER_H
#include "elements.h"

struct Player
{
    int pv; // == hp
    int niveau;
    int experience;
    int max;              // pvmax == hp
    Elements *inventaire; // inventaire == tab* dimension de Elements
};

typedef struct Player Player;

void startPlayer(Player *);
void addElements(Player p, Elements e);
void showInventaire(Player p);

#endif // PLAYER_H

