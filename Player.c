#include <stdlib.h>
#include "Player.h"
#include "Joystick.h"

player* create_player (unsigned short h, unsigned short w, unsigned short x, unsigned short y, unsigned short max_x, unsigned short max_y)
{
    if ((x - w/2 < 0) || (x + w/2 > max_x) || (y - h/2 < 0) || (y + h/2 > max_y)) 
        return (NULL);												
																															
    player *new_player = (player*) malloc(sizeof(player));																								
	
    if (!new_player)
        return (NULL);																																											
	
    new_player-> h = h;																																	
	new_player-> w = w;																																	
	new_player-> x = x;																																	
	new_player-> y = y;
    new_player-> turning_left = 0;
    new_player-> touching_floor = 0;
    new_player-> vY = 0;
    new_player-> life = 200000000;
    new_player-> life_cooldown = 60;
    new_player-> is_invinceble = 0;
    new_player-> status = 0;
    new_player-> current_frame = 0.f;
    new_player-> frame_delay = 5;
    new_player-> frame_count = 0;
    
    new_player-> control = joystick_create();
  
    return (new_player);
}

void player_move(player *element, char steps, unsigned char trajectory, unsigned short max_x, unsigned short max_y) {									

	if (trajectory == 0)
    { 
        if ((element-> x - steps *PLAYER_STEP) - element-> w/2 >= tropicL) 
            element->x = element->x - steps*PLAYER_STEP;
    } 						
	else if (trajectory == 1)
    { 
        if ((element->x + steps *PLAYER_STEP) + element-> w/2 <= max_x)
            element->x = element->x + steps*PLAYER_STEP;
    }			
	else if (trajectory == 2)
    { 
        if ((element-> y - PLAYER_JUMP) - element-> h/2 >= 0) 
        {
            element-> vY = -PLAYER_JUMP;
        }

    }				
	else if (trajectory == 3)
    { 
      
    }			
}

void destroy_player(player *element)
{
    joystick_destroy(element-> control);
    free(element);
    
    return;
}																												
