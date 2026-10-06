#include "Collision.h"

int collision_x (player* player, plataform* map_vector[], int plataform_count, int *index, int camera_xF)
{
    float min_overlap = 1e9;
    int found = 0;
        
    for(int i = 0; i < plataform_count; i++)
    {  
        float playerRight = player-> x + player-> w/2;
        float playerLeft = player-> x - player-> w/2;
        float plataformRight = map_vector[i]-> x - camera_xF + map_vector[i]-> w -40;
        
        float overlap_x;
 
        if((player-> y + player-> h/2) > (map_vector[i]-> y - 20) 
        && (player-> y - player-> h/2) < (map_vector[i]-> y + map_vector[i]-> h)
        && (player-> x + player-> w/2) > (map_vector[i]-> x - 40 - camera_xF)
        && (player-> x - player-> w/2) < (map_vector[i]-> x - 40 - camera_xF + map_vector[i]-> w))
        {    
            if (playerRight < plataformRight)
                overlap_x = playerRight - (map_vector[i]-> x - camera_xF - 40);
            else 
                overlap_x = plataformRight - playerLeft;

            if (overlap_x < min_overlap)
            { 
                min_overlap = overlap_x;
                *index = i;
                found = 1;
            }
        }
    }    
    
    return(found);
}

int collision_y(player* player, plataform* map_vector[], int plataform_count, int *index, int camera_xF)
{
    float min_overlap = 1e9;
    int found = 0;
        
    for(int i = 0; i < plataform_count; i++)
    {  
        float playerTop = player-> y - player-> h/2;
        float playerBottom = player-> y + player-> h/2;
        float plataformBottom = map_vector[i]-> y + map_vector[i]-> h; 

        float overlap_y;
      
        if((player-> y + player-> h/2) > (map_vector[i]-> y - 20) 
        && (player-> y - player-> h/2) < (map_vector[i]-> y + map_vector[i]-> h)
        && (player-> x + player-> w/2) > (map_vector[i]-> x - 40 - camera_xF)
        && (player-> x - player-> w/2) < (map_vector[i]-> x - 40 - camera_xF + map_vector[i]-> w)
        && (player-> y - player-> h/2) > 0)
        {    
          
           if (playerBottom < plataformBottom)
                overlap_y = playerBottom - map_vector[i]-> y;
            else 
                overlap_y = plataformBottom - playerTop;

            if (overlap_y < min_overlap)
            { 
                min_overlap = overlap_y;
                *index = i;
                found = 1;
            }
        }
    }    
    return(found);
}


