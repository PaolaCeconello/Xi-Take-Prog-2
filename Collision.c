#include "Collision.h"


int floorCollision (player* player, plataform* floor)
{
    if((player-> y + player-> h/2) > floor-> y)
        return (1);

    return(0);
}