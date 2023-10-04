#include <stdio.h>
#include <stdlib.h>
#include "player.h"

void startPlayer(Player *p) // initialisation du player par défaut
{
    p->pv = 100;
    p->niveau = 1;
    p->experience = 1; // 375 xp pour passer un niveau
    p->max = 100;      // nombre de coeur
    p->inventaire = malloc(sizeof(Elements) * 10);

    for (int i = 0; i < 4; i++)
    {
        Elements e;
        e.elements = i + 1;
        e.capacity = 1;
        e.maxCapacity = 1;
        e.type = ARMES;
        p->inventaire[i] = e;

        // printf("%d \n", p->inventaire[i].numElements);
    }
    Elements e;
    e.elements = 5;
    e.capacity = 5;
    e.maxCapacity = 20;
    e.type = CRAFTS;
    p->inventaire[4] = e;
}

void addElements(Player p, Elements e)
{
    for (int i = 0; i < 5; i++)
    {
        if (e.elements == p.inventaire[i].elements && p.inventaire[i].capacity != p.inventaire[i].maxCapacity)
        {
            p.inventaire[i].capacity += e.capacity;
        }
        printf("%d\n", p.inventaire[i].capacity);
    }
}

void showInventaire(Player p)
{
    for (int i = 0; i < 10; i++)
    {
        printf("%d\n", p.inventaire[i].type);
    }
}