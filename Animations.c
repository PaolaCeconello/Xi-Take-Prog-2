
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

        //player-> frame_count++;

        
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
        
         if (player->current_frame >= player->max_frames) 
        {    
            player->current_frame = 0;
            player-> status = 0;
            player-> h = 48;
        }
        /*if (player-> frame_count >= player-> frame_delay)        
        {        
            player-> frame_count = 0;
            
            if (player->control-> down)
            {   
                if (player-> current_frame < 4) 
                    player-> current_frame++;
            }
            else 
                player-> current_frame++;
        }*/

       
    
    break;
    
    
    default:
        
        break;
    }
}