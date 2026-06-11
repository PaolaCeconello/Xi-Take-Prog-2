
#include "Animations.h"

void player_animation (player* player)
{
    switch (player-> status)
    {
    case 0:
        player-> max_frames = 9;

        player-> frame_count++;

        if (player-> frame_count >= player-> frame_delay)
        {
            player-> current_frame++;
            player-> frame_count = 0;
        }
        
        if (player->current_frame >= player->max_frames) 
            player->current_frame = 0;

    break;
       
    case 1:
        player-> max_frames = 9;

        player-> frame_count++;

        if (player-> frame_count >= player-> frame_delay)
        {
            player-> current_frame++;
            player-> frame_count = 0;
        }
        
        if (player->current_frame >= player->max_frames) 
            player->current_frame = 0;
            
    break;
    
    case 2:
    
        player-> max_frames = 9;

        if (player->control-> down)
        {   
            player-> current_frame = 4;
            player-> frame_count = 0;
        }
        else 
        {
            player-> frame_count++;

            if (player-> frame_count >= player-> frame_delay)
            {
                player-> frame_count = 0;
                player-> current_frame++;
            }
        }
        
        if (player-> current_frame >= player-> max_frames) 
        {    
            player-> current_frame = 0;
            player-> status = 0;
            player-> h = 48;
        }
        
        break;
    
    case 3:
        
        player-> max_frames = 9;

        player-> frame_count++;

        if (player-> frame_count >= player-> frame_delay)
        {
            player-> current_frame++;
            player-> frame_count = 0;
        }
        
        if (player->current_frame >= player->max_frames) 
            player->current_frame = 0;

     case 4:
        
        player-> max_frames = 9;

        player-> frame_count++;

        if (player-> frame_count >= player-> frame_delay)
        {
            player-> current_frame++;
            player-> frame_count = 0;
        }
        
        if (player->current_frame >= player->max_frames) 
            player->current_frame = 0;

    break;
    
    default:
        
        break;
    }
}

void fire_animation (trap* trap)
{
    
    if (trap-> is_on == 0 && trap-> cooldown == 0)
    {    
        trap-> is_on = 1;
        trap-> current_frame = 0;
    }
    else 
    if (trap-> is_on == 0 && trap->cooldown > 0)
    {
        trap-> current_frame = 13;
        trap-> frame_count = 0;
        trap-> cooldown--;
    }
    else
    {
        trap-> frame_count++;

        if (trap-> frame_count >= trap-> frame_delay)
        {
            trap-> current_frame++;
            trap-> frame_count = 0;
            trap-> is_on = 1;
        }
    }    
    
    if (trap-> current_frame >= trap-> max_frames) 
    {    
        trap-> current_frame = 0;
        trap-> is_on = 0;
        trap-> cooldown = 90;
    }

    return;
}

void slime_animation (trap *trap, plataform *map_vector[], int plataform_count, int camera_xF)
{
    trap->frame_count++;

    if (trap->frame_count >= trap->frame_delay)
    {
        trap->current_frame++;
        trap->frame_count = 0;

        if (trap->turning_left == 0 && trap->x + 7 >= trap-> limitR)
            trap->turning_left = 1;
        else if (trap->turning_left == 1 && trap->x - 7 <= trap-> limitL)
            trap->turning_left = 0;
        
        if (trap->turning_left == 0)
            trap->x += 7;
        else
            trap->x -= 7;
    }

    if (trap->current_frame >= trap->max_frames)
        trap->current_frame = 0;
}

void drop_plataform_animation (trap *trap, player *player)
{
    trap-> y += 15;
}
    
