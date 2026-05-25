#ifndef PLATAFORM_H
#define PLATAFORM_H


#include <allegro5/allegro5.h>														//Biblioteca base do Allegro
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>

typedef struct
{
    int x;
    int y;
    int w;
    int h;
    
} plataform;

plataform* create_plataform(float x, int y, int w, int h);
void destroy_plataform(plataform);

#endif