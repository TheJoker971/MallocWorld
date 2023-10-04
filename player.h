#ifndef PLAYER_H
#define PLAYER_H

struct Player{
    int pv;
    int maxPv;
    int exp;
    int* inventaire;
};
typedef struct Player Player;

Player initPlayer();
void showInventaire(Player);

#endif  // PLAYER_H