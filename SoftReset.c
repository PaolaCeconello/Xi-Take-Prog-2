#include "SoftReset.h"

void soft_reset(player* player, int *camera_xM, int *camera_xB, int *camera_xF, int window_h, trap *trap_vector[], int trap_count, int *plus_life)
{
    player-> x = 50;																																	//Insere a posição inicial central de X
    player-> y = window_h/2;
    player-> turning_left = 0;
    player-> touching_floor = 0;
    player-> vY = 0; 
    player-> life = 3;
    player-> status = 0;
    player-> is_invinceble = 0;

    *camera_xB = 0;
    *camera_xF = 0;
    *camera_xM = 0;

    *plus_life = 0;

    for (int i = 0; i < trap_count; i++)
        if (trap_vector[i]-> type == 5)
        {
            trap_vector[i]-> cooldown = 5;
            trap_vector[i]-> status = 0;
            trap_vector[i]-> y = trap_vector[i]-> original_y;
        }
    return;
}

void reset_drop_plataforms (trap* trap_vector[], int trap_count, player *player)
{
    for (int i = 0; i < trap_count; i++)
    {
        if (trap_vector[i]-> type == 5 && trap_vector[i]-> status == 2)
        {
            trap_vector[i]-> cooldown--;
            if (trap_vector[i]->cooldown == 0)
            {    
                trap_vector[i]-> status = 0;
                trap_vector[i]-> y = trap_vector[i]-> original_y;
                trap_vector[i]-> cooldown = 5;
                player-> touching_floor = 1;
            }
        }
    }
}