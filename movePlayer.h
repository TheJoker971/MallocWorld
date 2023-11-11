//
// Created by Aymen on 29/09/2023.
//

#ifndef MALLOCWORLD_MOVEPLAYER_H
#define MALLOCWORLD_MOVEPLAYER_H
#include "player.h"
void movePlayer(int*** tab, char, Player p);


void moveLeft(int***, Player p);
void moveLeftZone(int***, int, int);

void moveRight(int***, Player p);
void moveRightZone(int***,int,int);

void moveUp(int***, Player p);
void moveUpZone(int***,int,int, Player p);
void moveUpZoneInside(int***, int, int);
void moveUpZoneBorder(int***, int, int);

void moveDown(int***, Player p);
void moveDownZone(int***, int, int, Player p);
void moveDownZoneInside(int***, int, int);
void moveDownZoneBorder(int***, int, int);


#endif //MALLOCWORLD_MOVEPLAYER_H
