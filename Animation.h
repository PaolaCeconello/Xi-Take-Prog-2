#include <allegro5/allegro5.h>														//Biblioteca base do Allegro
#include <allegro5/allegro_image.h>

typedef struct {
    ALLEGRO_BITMAP *sheet;
    int frame_w;
    int frame_h;
    int max_frames;
    int atual_frame;
    int frame_count;
    int frame_delay; 
} animation;

