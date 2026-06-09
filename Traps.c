#include "Traps.h"


trap** create_trapvector (trap *trap_vector[], int *trap_count, ALLEGRO_BITMAP *spikesSprite, int window_h, int floor_h) 
{
     int trap_matrix[8][28]={
        
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
    };

    int index = 0;

    for (int i = 0; i < 8; i++)
        for(int j = 0; j < 28; j++)
        {
            if (trap_matrix[i][j] == 1 || trap_matrix[i][j] == 2)
            {
               index++;
            }
        }

    trap_vector = malloc(sizeof(trap*)*index);
    
    for(int n = 0; n < index; n++)
        trap_vector[n] = malloc(sizeof(trap));

    *trap_count = index;
    index = 0;

    for (int i = 0; i < 8; i++)
        for(int j = 0; j < 28; j++)
        {  
            if (trap_matrix[i][j] == 1)
            {
                trap_vector[index]-> w = al_get_bitmap_width(spikesSprite)* 1.5;
                trap_vector[index]-> h = al_get_bitmap_height(spikesSprite) * 1.5;
                trap_vector[index]-> x = j * al_get_bitmap_width(spikesSprite) *1.5;
                trap_vector[index]-> type = 1;
                
                if (i == 6)
                    trap_vector[index]-> y = window_h - floor_h -(al_get_bitmap_height(spikesSprite));
                else
                    trap_vector[index]-> y = i * al_get_bitmap_height(spikesSprite) - 5; 

                index++;
            }
        
            /*if (trap_matrix[i][j] == 2)
            {
                trap_vector[index]-> w = floor_w * 1.5;
                trap_vector[index]-> h = floor_h * 1.5;
                trap_vector[index]-> x = j * floor_w * 1.5;
                trap_vector[index]-> type = 2;
                
                if (i == 1)
                    trap_vector[index]-> y = window_h - (floor_h);
                else
                    trap_vector[index]-> y = i * floor_h - 5; 

                
                index++;
            }*/
        }

    return(trap_vector);
}
void check_traps (trap* trap_vector[], int trap_count, player *player, int camera_xF)
{
    float min_overlap = 1e9;
    int found = 0;
    int index = 0;
        
    for(int i = 0; i < trap_count; i++)
    {  
        float playerTop = player-> y - player-> h/2;
        float playerBottom = player-> y + player-> h/2;
        float playerRight = player-> x + player-> w/2;
        float playerLeft = player-> x - player-> w/2;
        float trapRight = trap_vector[i]-> x - camera_xF + trap_vector[i]-> w;
        float trapBottom = trap_vector[i]-> y + trap_vector[i]-> h; 

        float overlap_x;
        float overlap_y;
        float overlap;
      
        if((player-> y + player-> h/2) > (trap_vector[i]-> y) 
        && (player-> y - player-> h/2) < (trap_vector[i]-> y + trap_vector[i]-> h)
        && (player-> x + player-> w/2) > (trap_vector[i]-> x - camera_xF)
        && (player-> x - player-> w/2) < (trap_vector[i]-> x - camera_xF + trap_vector[i]-> w))
        {    
            if (playerRight < trapRight)
                overlap_x = playerRight - trap_vector[i]-> x - camera_xF;
            else 
                overlap_x = trapRight + playerLeft;

            if (playerBottom < trapBottom)
                overlap_y = playerBottom - trap_vector[i]-> y;
            else 
                overlap_y = trapBottom - playerTop;

            if (overlap_x < overlap_y)
                overlap = overlap_x;
            else
                overlap = overlap_y;
                
            if (overlap < min_overlap)
            { 
                min_overlap = overlap;
                index = i;
                found = 1;
            }
        }
    }

    if (found == 1)
    {
        switch (trap_vector[index]-> type)
        {
        case 1:
            player-> life--;
            player-> vY = -7;
            break;
    
        default:
            break;
        }
    }
}

int check_trapsX(trap* trap_vector[], int trap_count, player *player, int camera_xF, int *index)
{
     float min_overlap = 1e9;
    int found = 0;
        
    for(int i = 0; i < trap_count; i++)
    {  
        float playerRight = player-> x + player-> w/2;
        float playerLeft = player-> x - player-> w/2;
        float plataformRight = trap_vector[i]-> x - camera_xF + trap_vector[i]-> w;
        
        float overlap_x;
 
        if((player-> y + player-> h/2) > (trap_vector[i]-> y - 20) 
        && (player-> y - player-> h/2) < (trap_vector[i]-> y + trap_vector[i]-> h)
        && (player-> x + player-> w/2) > (trap_vector[i]-> x - 40 -camera_xF)
        && (player-> x - player-> w/2) < (trap_vector[i]-> x - 40 - camera_xF + trap_vector[i]-> w))
        {    
          
            if (playerRight < plataformRight)
                overlap_x = playerRight - trap_vector[i]-> x - camera_xF;
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
    
    return(found);
}

int check_trapsY(player* player, trap* trap_vector[], int trap_count, int *index, int camera_xF)
{
    float min_overlap = 1e9;
    int found = 0;
        
    for(int i = 0; i < trap_count; i++)
    {  
        float playerTop = player-> y - player-> h/2;
        float playerBottom = player-> y + player-> h/2;
        float plataformBottom = trap_vector[i]-> y + trap_vector[i]-> h; 

        
        float overlap_y;
      
        if((player-> y + player-> h/2) > (trap_vector[i]-> y - 20) 
        && (player-> y - player-> h/2) < (trap_vector[i]-> y + trap_vector[i]-> h)
        && (player-> x + player-> w/2) > (trap_vector[i]-> x - 40 - camera_xF)
        && (player-> x - player-> w/2) < (trap_vector[i]-> x - 40 - camera_xF + trap_vector[i]-> w))
        {    
          
           if (playerBottom < plataformBottom)
                overlap_y = playerBottom - trap_vector[i]-> y;
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

void trap_efect (int type, player* player)
{
    switch (type)
        {
        case 1:
            player-> life--;
            player-> vY = -15;
            player-> x = player-> x -5;
            player-> is_invinceble = 1;
        break;
    
        default:
            break;
        }
}

void print_trap (trap *trap, int camera_xF, ALLEGRO_BITMAP *spikesSprite)
{
    switch (trap-> type)
    {
    case 1:
        al_draw_scaled_bitmap(spikesSprite, 0, 0, 16, 16, trap-> x-camera_xF, trap->y, 32,32 , 0);
        al_draw_scaled_bitmap(spikesSprite, 0, 0, 16, 16, trap-> x-camera_xF+32, trap->y, 32,32 , 0);
        al_draw_scaled_bitmap(spikesSprite, 0, 0, 16, 16, trap-> x-camera_xF+64, trap->y, 32,32 , 0);
        break;
    }
}

void destroy_traps (trap *trap_vector[], int trap_count)
{
    for(int n = 0; n < trap_count; n++)
        free(trap_vector[n]);

    free(trap_vector);
    
    return;
}