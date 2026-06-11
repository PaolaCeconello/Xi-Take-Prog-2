#include <stdio.h>
#include <stdlib.h>
#include "Plataform.h"

plataform* create_plataform(float x, float y, float w, float h)
{
    plataform *new_plataform = malloc(sizeof(plataform));
    
    new_plataform-> x = x;
    new_plataform-> y = y;
    new_plataform-> w = w;
    new_plataform-> h = h;

    return(new_plataform);
}

plataform** create_mapvector(plataform *map_vector[], int floor_w, int floor_h, int *plataform_count, int window_h)
{
    int map_matrix[8][56]={
        
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,2,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,0,2,2,2,0,0,0,0,0,0,0,0,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,1,0,0,1,1,1,1,1,0,0,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1}
    };
    
    int index = 0;
    
    for (int i = 0; i < 8; i++)
        for(int j = 0; j < 56; j++)
        {    
            if (map_matrix[i][j] != 0)
                index++;
        }
            
    map_vector = malloc(sizeof(plataform*)*index);
    
    for(int n = 0; n < index; n++)
        map_vector[n] = malloc(sizeof(plataform));
    
    
    *plataform_count = index;
    index = 0;
    
    for (int i = 0; i < 8; i++)
        for(int j = 0; j < 56; j++)
        {
            if (map_matrix[i][j] == 1)
            {
                map_vector[index]-> w = floor_w * 1.5;
                map_vector[index]-> h = floor_h * 1.5;
                map_vector[index]-> x = j * floor_w * 1.5;
                map_vector[index]-> y = window_h - (floor_h);
                map_vector[index]-> type = 1;
                
                
                index++;
            }
        
            if (map_matrix[i][j] == 2)
            {
                map_vector[index]-> w = floor_w * 1.5;
                map_vector[index]-> h = floor_h * 1.5;
                map_vector[index]-> x = j * floor_w * 1.5;
                map_vector[index]-> y = i * floor_h - 5;
                map_vector[index]-> type = 2;
                
                index++;
            }

        }
    
    return(map_vector);
}

void destroy_plataform (plataform *map_vector[], int plataform_count)
{
    for(int n = 0; n < plataform_count; n++)
        free(map_vector[n]);

    free(map_vector);
    
    return;
}
