//
// Created by Aymen on 29/09/2023.
//

#ifndef MALLOCWORLD_CHECKMOVEMENT_H
#define MALLOCWORLD_CHECKMOVEMENT_H
#include "player.h"
int checkMovement(int, Player, int, Npc npc);
int checkCase(int, Player);
int portailOpenClose1(int);
int portailOpenClose2(int result);
void pnjMenu(Player p, Npc npc);
void craft(Player *p, int zone);
int chooseTool(Player *p);
int verifyDurabilityTool(Player *p);
#endif //MALLOCWORLD_CHECKMOVEMENT_H
