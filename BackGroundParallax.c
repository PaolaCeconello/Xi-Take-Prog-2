#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro5.h>														
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>

#include "Player.h"


void FloorParallax (int camera_x, int camera_count, float floor_w, float floor_h, ALLEGRO_BITMAP *plataformTexture,int window_h)
{
    int i = 0;
	int start_x = (camera_x % (int)floor_w);

	if (start_x < 0)
		start_x += floor_w;
	    
        while (i <= camera_count)
		{
			int x = -start_x + (i * floor_w);
				
			al_draw_scaled_bitmap(plataformTexture, 0, 0, floor_w, floor_h, x, (window_h - floor_h), floor_w, floor_h, 0);
			
			i++;
		}
    return;
}

void MiddleGroundParallax (player *player, int camera_x, int camera_count, float bgMiddle_w, float bgMiddle_h, float bgMiddleAjustado, ALLEGRO_BITMAP *backgroundMiddle,int window_h)
{
    int i = 0;
	int start_x = (camera_x % (int)bgMiddleAjustado);

	if (start_x < 0)
		start_x += bgMiddleAjustado;
	    
        while (i <= camera_count)
		{
			int x = -start_x + (i * bgMiddleAjustado);
				
			al_draw_scaled_bitmap(backgroundMiddle, 0, 0, bgMiddle_w, bgMiddle_h, x, 0, bgMiddleAjustado, window_h, 0);
			
			i++;
		}
    return;
}

void BackGroundParallax (int camera_x, int camera_count, float bgBack_w, float bgBack_h, float bgBackAjustado, ALLEGRO_BITMAP *backgroundBack,int window_h)
{
    int i = 0;
	int start_x = (camera_x % (int)bgBackAjustado);

	if (start_x < 0)
		start_x += bgBackAjustado;
	    
        while(i <= camera_count)
		{
			int x = -start_x + (i * bgBackAjustado);
				
			al_draw_scaled_bitmap(backgroundBack, 0, 0, bgBack_w, bgBack_h, x, 0, bgBackAjustado, window_h, 0);
			
			i++;
		}
    return;
}

void destroy_backgorund (ALLEGRO_BITMAP *plataformTexture, ALLEGRO_BITMAP *backgroundMiddle, ALLEGRO_BITMAP *backgroundBack)
{
	al_destroy_bitmap(backgroundBack);		
	al_destroy_bitmap(backgroundMiddle);
	al_destroy_bitmap(plataformTexture);

	return;
}