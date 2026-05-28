#include "Collision.h"


int collision (player* player, plataform* map_vector[], int plataform_count, int *index)
{
   for(int i = 0; i < plataform_count; i++)
    {  
        if((player-> y + player-> h/2) > (map_vector[i]-> y - map_vector[i]-> w/2) 
        && (player-> x + player-> w/2) > (map_vector[i]-> x + map_vector[i]-> w))
        {    
           *index = i;
            return (1);
        }
        
        if((player-> x + player-> w/2) > (map_vector[i]-> x + map_vector[i]-> h) 
        && (player-> y + player-> h/2) > (map_vector[i]-> y - map_vector[i]-> w/2)) 
        //&& player-> y + player-> h/2 > map_vector[i]-> y + map_vector[i]-> h/2)
        {    
           *index = i;
            return (-1);
        }
    
    
    
    }    
        //if((player-> y + player-> h/2) > map_vector[i]-> y + map_vector[i]-> h/2)
        //return (1);
    return(0);
}