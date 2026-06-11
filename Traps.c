#include "Traps.h"
#include "Animations.h"
#include "Collision.h"


trap** create_trapvector (trap *trap_vector[], int *trap_count, ALLEGRO_BITMAP *spikesSprite, ALLEGRO_BITMAP *ladderSprite, int window_h, int floor_h) 
{
     int trap_matrix[8][56]={
        
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,1,1,0,0,0,0,0,2,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,5,5,5,5,5,5}
    };

    int index = 0;

    for (int i = 0; i < 8; i++)
        for(int j = 0; j < 56; j++)
        {
            if (trap_matrix[i][j] != 0)
                index++;
        }    
            
            
    trap_vector = malloc(sizeof(trap*)*index);
    
    for(int n = 0; n < index; n++)
        trap_vector[n] = malloc(sizeof(trap));

    *trap_count = index;
    index = 0;

    for (int i = 0; i < 8; i++)
        for(int j = 0; j < 56; j++)
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
        
            if (trap_matrix[i][j] == 2)
            {
                trap_vector[index]-> w = al_get_bitmap_width(ladderSprite) *1.5;
                trap_vector[index]-> h = al_get_bitmap_height(ladderSprite) *1.5;
                trap_vector[index]-> x = j * al_get_bitmap_width(ladderSprite) *1.5;
                trap_vector[index]-> type = 2;
                
                if (i == 6)
                    trap_vector[index]-> y = window_h - floor_h -(al_get_bitmap_height(ladderSprite)*1.5);
                else
                    trap_vector[index]-> y = i * al_get_bitmap_height(ladderSprite) *1.5;
                index++;
            }
        
            if (trap_matrix[i][j] == 3)
            {
                trap_vector[index]-> w = 90;
                trap_vector[index]-> h = 180;
                trap_vector[index]-> x = j * 90;
                trap_vector[index]-> max_frames = 14;
                trap_vector[index]-> frame_count = 0;
                trap_vector[index]-> current_frame = 0;
                trap_vector[index]-> frame_delay = 5;
                trap_vector[index]-> is_on = 1;
                trap_vector[index]-> cooldown = 90;
                
                trap_vector[index]-> type = 3;

                if (i == 6)
                    trap_vector[index]-> y = window_h - floor_h - (148);
                else
                    trap_vector[index]-> y = i * 180 - (148);
                index++;
            }
        
            if (trap_matrix[i][j] == 4)
            {
                trap_vector[index]-> w = 32 *3;
                trap_vector[index]-> h = 32 * 3;
                trap_vector[index]-> x = j * 32 *3;
                trap_vector[index]-> max_frames = 4;
                trap_vector[index]-> frame_count = 0;
                trap_vector[index]-> current_frame = 0;
                trap_vector[index]-> frame_delay = 5;
                trap_vector[index]-> is_on = 1;
                trap_vector[index]-> cooldown = 90;
                trap_vector[index]-> turning_left = 0;
                trap_vector[index]-> limitL = trap_vector[index]-> x - 60;
                trap_vector[index]-> limitR = trap_vector[index]-> x + 60;
                
                trap_vector[index]-> type = 4;

                if (i == 6)
                    trap_vector[index]-> y = window_h - floor_h - (32*3) + 40;
                else
                    trap_vector[index]-> y = i * 32*3 + 40;
                index++;
            }
        
            if (trap_matrix[i][j] == 5)
            {
                trap_vector[index]-> w = 64;
                trap_vector[index]-> h = 64;
                trap_vector[index]-> x = j * 64 + 740;
                trap_vector[index]-> y = window_h - (floor_h);
                trap_vector[index]-> status = 0;
                trap_vector[index]-> original_y = trap_vector[index]-> y;
                trap_vector[index]-> current_frame = 0;
                trap_vector[index]-> frame_delay = 0;
                trap_vector[index]-> cooldown = 5;
                

                trap_vector[index]-> type = 5; 

                index++;
            }
        
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
                overlap_x = playerRight - (trap_vector[i]-> x - camera_xF);
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
                overlap_x = playerRight -(trap_vector[i]-> x - camera_xF);
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

void trap_efect (trap* trap, player* player)
{
    switch (trap-> type)
        {
        case 1:
            player-> life--;
            player-> vY = -15;
            player-> x = player-> x -5;
            player-> is_invinceble = 1;
            
        break;
    
        case 2:
           
        if (player-> control-> up)   
        {  
            player-> status = 4;
            player-> touching_floor = 1;
            player-> vY = 0;
            //player-> x = (trap-> x - 350);

            player-> y = player-> y - PLAYER_STEP;
        }
       
        break;
        
        case 3:
            
        if (trap-> is_on == 1)    
        {    
            player-> life--;
            player-> vY = -15;
            player-> x = player-> x -5;
            player-> is_invinceble = 1;
        }
            
        break;
        
        case 4:
        {
            player-> life--;
            player-> vY = -15;
            player-> x = player-> x -5;
            player-> is_invinceble = 1;
        }

        break;
        
        case 5:
        {
            if (trap-> status == 0 && player-> touching_floor)
                trap-> cooldown--;
            
    
            if (trap-> cooldown == 0)
                trap-> status = 1;

            /*if(trap-> status == 1)
            {
                if (trap-> y >= 620)
                {    
                    trap-> status = 2;
                    trap-> cooldown = 10;
                }
            }
            
            if (trap-> status == 2)
            {
                trap-> cooldown--;
                if (trap->cooldown == 0)
                {    
                    trap-> status == 0;
                    trap-> y = trap-> original_y;
                    trap-> cooldown = 4;
                }
            }*/
    }
    
    break;

        
        
        default:
            break;
        }
}

void print_trap (trap *trap, int camera_xF, ALLEGRO_BITMAP *spikesSprite, ALLEGRO_BITMAP *ladderSprite, ALLEGRO_BITMAP *fireSprite, ALLEGRO_BITMAP *slimeSprite, ALLEGRO_BITMAP *dropPlataformSprite, plataform *map_vector[], int plataform_count, player *player)
{
    switch (trap-> type)
    {
    case 1:
        al_draw_scaled_bitmap(spikesSprite, 0, 0, 16, 16, trap-> x-camera_xF, trap->y, 32,32 , 0);
        al_draw_scaled_bitmap(spikesSprite, 0, 0, 16, 16, trap-> x-camera_xF+32, trap->y, 32,32 , 0);
        al_draw_scaled_bitmap(spikesSprite, 0, 0, 16, 16, trap-> x-camera_xF+64, trap->y, 32,32 , 0);
        break;
    
    case 2: 
        al_draw_scaled_bitmap(ladderSprite, 0, 0, 48, 48, trap-> x-camera_xF, trap->y + 2, 48*1.5 ,48*1.5, 0);
        break;
    
    case 3:
        fire_animation(trap);
        
        int source_xfire = trap-> current_frame * 45;
        
        al_draw_scaled_bitmap(fireSprite, source_xfire, 0, 45, 90,trap-> x- camera_xF, trap-> y,90,180,0);
	
        break;
    
    case 4:
        slime_animation(trap,map_vector,plataform_count,camera_xF);

        int source_xslime = trap-> current_frame * 32;

        int ALLEGRO_FLIP_HORIZONTAL = trap-> turning_left;
        
        al_draw_scaled_bitmap(slimeSprite, source_xslime, 32, 32,32, trap-> x- camera_xF, trap-> y, 32*3,32*3,ALLEGRO_FLIP_HORIZONTAL);
    
    break;

    case 5: 
      
    if (trap-> status != 1)
        al_draw_scaled_bitmap(dropPlataformSprite, 0, 0, 64, 64, trap->x - camera_xF, trap->y,64, 64, 0);
    else 
        {
            trap-> y += 15;
            al_draw_scaled_bitmap(dropPlataformSprite, 0, 0, 64, 64, trap->x - camera_xF, trap->y,64, 64, 0);

            if (trap-> y >= 560)
                {    
                    trap-> status = 2;
                    trap-> cooldown = 30;
                }
        }
    
    
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