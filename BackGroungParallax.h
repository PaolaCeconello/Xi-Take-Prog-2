#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro5.h>														
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>

void FloorParallax (int camera_x, int camera_count, float floor_w, float floor_h, ALLEGRO_BITMAP *plataformTexture,int window_h);
void MiddleGroundParallax (int camera_x, int camera_count, float bgMiddle_w, float bgMiddle_h, float bgMiddleAjustado, ALLEGRO_BITMAP *backgroundMiddle,int window_h);
void BackGroundParallax (int camera_x, int camera_count, float bgBack_w, float bgBack_h, float bgBackAjustado, ALLEGRO_BITMAP *backgroundBack,int window_h);