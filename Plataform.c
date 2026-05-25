#include <stdio.h>
#include <stdlib.h>
#include "Plataform.h"

plataform* create_plataform(float x, int y, int w, int h)
{
    plataform *new_plataform = malloc(sizeof(plataform));
    
    new_plataform-> x = x;
    new_plataform-> y = y;
    new_plataform-> w = h;
    new_plataform-> h = h;

    return(new_plataform);
}