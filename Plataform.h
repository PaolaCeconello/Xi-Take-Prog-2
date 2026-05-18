#include <allegro5/allegro5.h>														//Biblioteca base do Allegro
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>

typedef struct
{
    float plataform_w;
    int x;
    int x_max;
    int y_max;
    
} plataform;

plataform* create_plataform(float w, int x, int x_max, int y_max);
void destroy_plataform(plataform);
