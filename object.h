#ifndef OBJECT_H
#define OBJECT_H

typedef struct Object
{
    int id;
    int durability;
    int quantity;
    int damage;
} Object;

Object initObject(int,int);
Object blankObject();
int stackable(Object*,Object*);
int isRessource(int);
int isWeapon(int);
int isArmor(int);
int isHealth(int);
int isTools(int);
void resetObject(Object*);
Object ressource(int,int);
Object sword(int);
Object lance(int);

void resetObject(Object*);
int isPickAxe(int);
int isAxe(int);
int isBillHook(int);
Object hammer(int);
Object tool(int);
Object armor(int);
Object health(int);

#endif  //OBJECT_H