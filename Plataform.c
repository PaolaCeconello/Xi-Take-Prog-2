#include <stdio.h>
#include <stdlib.h>
#include "Plataform.h"

plataform* create_plataform(float x, int y, int w, int h)
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
    

    int map_matrix[9][32]={
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,2,2,2,0,0,0,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,0,0,0,0,0,0,0,2,2,0,2,0,0},
        {0,0,0,0,0,0,2,2,2,0,0,0,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,0,0,1,1,1,1,1,1,1,0,0,1,1,0,1,1}
    };
    
    int index = 0;
    
    for (int i = 0; i < 9; i++)
        for(int j = 0; j < 32; j++)
        {
            if (map_matrix[i][j] == 1 || map_matrix[i][j] == 2)
            {
               index++;
            }
        }
    
    map_vector = malloc(sizeof(plataform*)*index);
    
    for(int n = 0; n < index; n++)
        map_vector[n] = malloc(sizeof(plataform));
    
    
    *plataform_count = index;
    index = 0;
    
    for (int i = 0; i < 9; i++)
        for(int j = 0; j < 32; j++)
        {
            if (map_matrix[i][j] == 1)
            {
                map_vector[index]-> w = floor_w;
                map_vector[index]-> h = floor_h;
                map_vector[index]-> x = j * floor_w ;
                map_vector[index]-> y = window_h - floor_h;
                
                index++;
            }
        
             if (map_matrix[i][j] == 2)
            {
                map_vector[index]-> w = floor_w;
                map_vector[index]-> h = floor_h;
                map_vector[index]-> x = j * floor_w;
                map_vector[index]-> y = i * floor_h - 120;
                
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
