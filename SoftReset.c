#include "SoftReset.h"

void soft_reset(player* player, int *camera_xM, int *camera_xB, int *camera_xF, int window_h)
{
    player-> x = 50;																																	//Insere a posição inicial central de X
    player-> y = window_h/2;
    player-> turning_left = 0;
    player-> touching_floor = 0;
    player-> vY = 0; 
    player-> life = 3;

    *camera_xB = 0;
    *camera_xF = 0;
    *camera_xM = 0;

    /*int index = 0;
    
    int map_matrix[8][28]={
        
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,0,0},
        {0,0,0,0,0,0,0,0,0,2,2,2,0,0,0,0,0,0,0,0,2,2,0,0,0,0,0,0},
        {0,0,0,0,0,0,2,2,2,0,0,0,0,0,0,0,2,2,2,0,0,0,0,0,0,0,2,2},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,0,0,1,1,1,1,1,1,1,0,0,1}
    };
    
    /*for (int i = 0; i < 8; i++)
        for(int j = 0; j < 28; j++)
        {
            if (map_matrix[i][j]== 1 || map_matrix[i][j] == 2)
                index++;
        }    
            
    for (int n = 0; n < index; n++)
    {
        map_vector[n] = 0;
    }
    
    index = 0;
    
    fprintf(stderr, "PASSOU 3"); 
    for (int i = 0; i < 8; i++)
        for(int j = 0; j < 28; j++)
        {
             fprintf(stderr, "PASSOU 3.1"); 
            if (map_matrix[i][j] == 1)
            {
                map_vector[index]-> w = floor_w * 1.5;
                map_vector[index]-> h = floor_h * 1.5;
                map_vector[index]-> x = j * floor_w *1.5;
                map_vector[index]-> y = window_h - (floor_h);
                
                index++;
            }
        
             fprintf(stderr, "PASSOU 3.2");  
            if (map_matrix[i][j] == 2)
            {
                map_vector[index]-> w = floor_w * 1.5;
                map_vector[index]-> h = floor_h * 1.5;
                map_vector[index]-> x = j * floor_w * 1.5;
                map_vector[index]-> y = i * floor_h - 5;
                
                index++;
            }
        }
     fprintf(stderr, "PASSOU 4");*/
    return;
}