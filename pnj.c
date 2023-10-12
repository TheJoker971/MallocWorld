#include <stdio.h>
#include <stdlib.h>
#include "pnj.h"

void stockPnj(Pnj *p)
{

    int stock[] = {1,
                   2,
                   3,
                   4,
                   8,
                   9,
                   10,
                   11,
                   12,
                   13,
                   14,
                   15,
                   19,
                   20,
                   21,
                   22,
                   23,
                   24,
                   25,
                   26,
                   30,
                   31,
                   32,
                   33,
                   34};
    for (int i = 0; i < 25; i++)
    {
        p->stock[i] = stock[i];

        // printf("%d \n", p->stock[i]);
    }
}