#ifndef PLATAFORM_H
#define PLATAFORM_H


#include <allegro5/allegro5.h>														//Biblioteca base do Allegro
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>

typedef struct
{
    float x;
    float y;
    float w;
    float h;
    int type;
    
} plataform;

plataform* create_plataform(float x, float y, float w, float h);
plataform** create_mapvector(plataform *map_vector[], int floor_w, int floor_h, int *plataform_count, int window_h);
void destroy_plataform (plataform *map_vector[], int plataform_count);

#endif