#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro5.h>														
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>

void MiddleGroundParallax (int camera_x, int camera_count, float bgMiddle_w, float bgMiddle_h, float bgMiddleAjustado, ALLEGRO_BITMAP *backgroundMiddle,int window_h)
{
    int i = 0;
	int start_x = -(camera_x % (int) bgMiddleAjustado);
	    
        while(i < camera_count + 1)
		{
			int x = start_x + (i * bgMiddleAjustado);
				
			al_draw_scaled_bitmap(backgroundMiddle, 0, 0, bgMiddle_w, bgMiddle_h, x, 0, bgMiddleAjustado, window_h, 0);
			
			i++;
		}
    return;
}