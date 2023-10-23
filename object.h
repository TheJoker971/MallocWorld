#ifndef OBJECT_H
#define OBJECT_H

typedef struct Object
{
    int id;
    int durability;
    int quantity;
} Object;

Object initObject(int,int,int);
Object blankObject();
int stackable(Object*,Object*);
int isWeapon(int);
int isCraft(int);
int isArmor(int);
Object sword(int);
Object plant(int,int);
Object lance(int);
void resetObject(Object*);

#endif  //OBJECT_H