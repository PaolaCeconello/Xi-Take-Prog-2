#include <stdio.h>
#include <stdlib.h>
#include "Plataform.h"

plataform* create_plataform(float w, int x, int x_max, int y_max)
{
    plataform *new_plataform = malloc(sizeof(plataform));
    
    new_plataform-> plataform_w = w;
    new_plataform-> x = x;
    new_plataform-> x_max = x_max;
    new_plataform-> y_max = y_max;

    return(new_plataform);
}