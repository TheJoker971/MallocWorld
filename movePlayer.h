//
// Created by Aymen on 29/09/2023.
//

#ifndef MALLOCWORLD_MOVEPLAYER_H
#define MALLOCWORLD_MOVEPLAYER_H
#include "player.h"
void movePlayer(int*** tab, char, Player p, Npc npc);


void moveLeft(int***, Player p, Npc npc);
void moveLeftZone(int***, int, int, Player p, Npc npc);

void moveRight(int***, Player p, Npc npc);
void moveRightZone(int***,int,int, Player p, Npc npc);

void moveUp(int***, Player p, Npc npc);
void moveUpZone(int***,int,int, Player p, Npc npc);
void moveUpZoneInside(int***, int, int, Player p, Npc npc);
void moveUpZoneBorder(int***, int, int, Player p, Npc npc);

void moveDown(int***, Player p, Npc npc);
void moveDownZone(int***, int, int, Player p, Npc npc);
void moveDownZoneInside(int***, int, int, Player p, Npc npc);
void moveDownZoneBorder(int***, int, int, Player p, Npc npc);

#endif //MALLOCWORLD_MOVEPLAYER_H
