//
// Created by Aymen on 29/09/2023.
//

#ifndef MALLOCWORLD_MOVEPLAYER_H
#define MALLOCWORLD_MOVEPLAYER_H
void movePlayer(int*** tab, char);



void moveLeft(int***);
void moveLeftZone(int***, int, int);

void moveRight(int***);
void moveRightZone(int***,int,int);

void moveUp(int***);
void moveUpZone(int***,int,int);
void moveUpZoneInside(int***, int, int);
void moveUpZoneBorder(int***, int, int);

void moveDown(int***);
void moveDownZone(int***, int, int);
void moveDownZoneInside(int***, int, int);
void moveDownZoneBorder(int***, int, int);


#endif //MALLOCWORLD_MOVEPLAYER_H
