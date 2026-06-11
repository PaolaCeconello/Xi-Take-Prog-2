#include "Collision.h"

int collision (player* player, plataform* map_vector[], int plataform_count, int *index, int camera_xF, int *axis)
{
    float min_overlap = 1e9;
    int found = 0;
        
    for(int i = 0; i < plataform_count; i++)
    {  
        float playerTop = player-> y - player-> h/2;
        float playerBottom = player-> y + player-> h/2;
        float playerRight = player-> x + player-> w/2;
        float playerLeft = player-> x - player-> w/2;
        float plataformRight = map_vector[i]-> x - camera_xF + map_vector[i]-> w;
        float plataformBottom = map_vector[i]-> y + map_vector[i]-> h; 

        float overlap_x;
        float overlap_y;
        float overlap;
      
        
        if((player-> y + player-> h/2) > (map_vector[i]-> y) 
        && (player-> y - player-> h/2) < (map_vector[i]-> y + map_vector[i]-> h)
        && (player-> x + player-> w/2) > (map_vector[i]-> x - camera_xF)
        && (player-> x - player-> w/2) < (map_vector[i]-> x - camera_xF + map_vector[i]-> w))
        {    
          
            if (playerRight < plataformRight)
                overlap_x = playerRight - map_vector[i]-> x - camera_xF;
            else 
                overlap_x = plataformRight + playerLeft;

            if (playerBottom < plataformBottom)
                overlap_y = playerBottom - map_vector[i]-> y;
            else 
                overlap_y = plataformBottom - playerTop;

            if (overlap_x < overlap_y)
            {    
                overlap = overlap_x;
                *axis = 1;
            }
            
            else
                overlap = overlap_y;
                
            if (overlap < min_overlap)
            { 
                min_overlap = overlap;
                *index = i;
                found = 1;
            }
        
            //*index = i;
            //found = 1;
        }
    }    
        //if((player-> y + player-> h/2) > map_vector[i]-> y + map_vector[i]-> h/2)
        //return (1);
    return(found);
}

int collision_x (player* player, plataform* map_vector[], int plataform_count, int *index, int camera_xF)
{
    float min_overlap = 1e9;
    int found = 0;
        
    for(int i = 0; i < plataform_count; i++)
    {  
        float playerRight = player-> x + player-> w/2;
        float playerLeft = player-> x - player-> w/2;
        float plataformRight = map_vector[i]-> x - camera_xF + map_vector[i]-> w;
        
        float overlap_x;
 
        if((player-> y + player-> h/2) > (map_vector[i]-> y - 20) 
        && (player-> y - player-> h/2) < (map_vector[i]-> y + map_vector[i]-> h)
        && (player-> x + player-> w/2) > (map_vector[i]-> x - 40 -camera_xF)
        && (player-> x - player-> w/2) < (map_vector[i]-> x - 40 - camera_xF + map_vector[i]-> w))
        {    
          
            if (playerRight < plataformRight)
                overlap_x = playerRight - (map_vector[i]-> x - camera_xF);
            else 
                overlap_x = plataformRight + playerLeft;

            if (overlap_x < min_overlap)
            { 
                min_overlap = overlap_x;
                *index = i;
                found = 1;
            }
        }
    }    
        //if((player-> y + player-> h/2) > map_vector[i]-> y + map_vector[i]-> h/2)
        //return (1);
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
        //if((player-> y + player-> h/2) > map_vector[i]-> y + map_vector[i]-> h/2)
        //return (1);
    return(found);
}

int collision_slimeX(trap *trap, plataform *map_vector[], int plataform_count, int camera_xF)
{
    /*float min_overlap = 1e9;
    int found = 0;     
    
    for(int i = 0; i < plataform_count; i++)
    {  
        float slimeRight = trap-> x + trap-> w/2;
        float slimeLeft = trap-> x - trap-> w/2;
        float plataformRight = map_vector[i]-> x - camera_xF + map_vector[i]-> w;
        
        float overlap_x;
 
        if((trap-> x + trap-> w/2 + 7) > (map_vector[i]-> x - camera_xF)
        && (trap-> x - trap-> w/2 + 7) < (map_vector[i]-> x + map_vector[i]-> w - camera_xF)
        && (trap-> y + trap-> h/2) > (map_vector[i]-> y))
        {    
            if (slimeRight < plataformRight)
                overlap_x = slimeRight - (map_vector[i]-> x - camera_xF);
            else 
                overlap_x = plataformRight + slimeLeft;

            if (overlap_x < min_overlap)
            { 
                min_overlap = overlap_x;
                found = 1;
            }
        }*/

    int found = 0;     
    
    float sensor_x;
        
    if (trap->turning_left == 0)
        sensor_x = trap->x + trap->w + 7;  // right edge + a little ahead
    else
        sensor_x = trap->x - 7;            // left edge - a little ahead

    float sensor_y = trap->y + trap->h + 5; // bottom edge + a little below

    for(int i = 0; i < plataform_count; i++)
    {  
        float platLeft  = map_vector[i]->x;
        float platRight = map_vector[i]->x + map_vector[i]->w;
        float platTop   = map_vector[i]->y;
        float platBot   = map_vector[i]->y + map_vector[i]->h;

        if (sensor_x > platLeft && sensor_x < platRight &&  sensor_y > platTop &&  sensor_y < platBot)
            found = 1;
    }     
    
    return(found);
}

int collision_slimeY(trap *trap, plataform *map_vector[], int plataform_count, int camera_xF)
{
    float min_overlap = 1e9;
    int found = 0;
        
    for(int i = 0; i < plataform_count; i++)
    {  
        float slimeTop = trap-> y - trap-> h/2;
        float slimeBottom = trap-> y + trap-> h/2;
        float plataformBottom = map_vector[i]-> y + map_vector[i]-> h; 

        float overlap_y;
      
        if((trap-> y + trap-> h/2) > (map_vector[i]-> y - 5) 
        && (trap-> y - trap-> h/2) < (map_vector[i]-> y + map_vector[i]-> h)
        && (trap-> x + trap-> w/2) > (map_vector[i]-> x - 40 - camera_xF)
        && (trap-> x - trap-> w/2) < (map_vector[i]-> x - 40 - camera_xF + map_vector[i]-> w)
        && (trap-> y - trap-> h/2) > 0)
        {    
          
           if (slimeBottom < plataformBottom)
                overlap_y = slimeBottom - map_vector[i]-> y;
            else 
                overlap_y = plataformBottom - slimeTop;

            if (overlap_y < min_overlap)
            { 
                min_overlap = overlap_y;
                found = 1;
            }
        }
    }    
        //if((player-> y + player-> h/2) > map_vector[i]-> y + map_vector[i]-> h/2)
        //return (1);
    return(found);
}