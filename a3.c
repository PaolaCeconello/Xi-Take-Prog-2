//Compilação: gcc a3.c Player.c Plataform.c Joystick.c BackGroundParallax.c -o jogo $(pkg-config allegro-5 allegro_main-5 allegro_font-5 allegro_image-5 allegro_primitives-5 --libs --cflags)
#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro5.h>														
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include "Player.h"
#include "Plataform.h"
#include "BackGroundParallax.h"
#include "Collision.h"
#include "SoftReset.h"
#include "Traps.h"
#include "Animations.h"

#define window_h 540
#define window_w 960
#define floor_w 64  
#define floor_h 64 
#define camera_speedF 12
#define camera_speedM 10
#define camera_speedB 4
#define gravity 2
#define max_fall 16
#define frame 48

void update_location(player *player, plataform *map_vector[], int plataform_count, int *camera_xM, int *camera_xB, int *camera_xF, int *lastCollision, trap *trap_vector[], int trap_count)
{ 
	*lastCollision = player-> touching_floor;
	player-> touching_floor = 0;
	int indexCollision;
	int indexTraps;
	
	if (player-> status == 1)
		player-> status = 0;
	
	if (player-> control-> left)
	{																																											//Se o botão de movimentação para esquerda do controle do primeiro jogador está ativado...
		player_move(player, 1, 0, window_w, window_h);
		player-> turning_left = 1;
		player-> status = 1;
				
		if (player-> x >= tropicL && player-> x < tropicR)
		{
			*camera_xM -= camera_speedM;
			*camera_xB -= camera_speedB;
			*camera_xF -= camera_speedF;
		}
	
		
		if (collision_x(player, map_vector, plataform_count, &indexCollision, *camera_xF) == 1)
			player-> x = map_vector[indexCollision]-> x - 40 - *camera_xF + map_vector[indexCollision]-> w + player-> w/2;

		if (check_trapsX(trap_vector,trap_count,player,*camera_xF, &indexTraps) == 1  && player-> is_invinceble == 0)
			trap_efect(trap_vector[indexTraps], player);
			
			
		else if (player-> is_invinceble == 1)
				player-> life_cooldown--;
		if (player-> life_cooldown == 0)
		{	
			player-> status = 0;
			player-> is_invinceble = 0;
			player-> life_cooldown = 60;
		}
	}	
	
	if (player->control->right)
	{																																											//Se o botão de movimentação para direita do controle do primeir ojogador está ativado...
		player_move(player, 1, 1, tropicR, window_h);
		player-> turning_left = 0;
		player-> status = 1;
			
		if (player-> x > tropicL && player-> x <= tropicR)
		{	
			*camera_xM += camera_speedM;
			*camera_xB += camera_speedB;
			*camera_xF += camera_speedF;																																				//Move o quadrado do primeiro jogador para a direta
		}
	
		
		if (collision_x(player, map_vector, plataform_count, &indexCollision, *camera_xF) == 1)
			player-> x = map_vector[indexCollision]-> x - 40 - *camera_xF - player-> w/2;

		if (check_trapsX(trap_vector,trap_count,player,*camera_xF, &indexTraps) == 1 && player-> is_invinceble == 0)
			trap_efect(trap_vector[indexTraps], player);
		
				
			
		else if (player-> is_invinceble == 1)
		{		
			player-> life_cooldown--;
			player-> status = 3;
		}
		if (player-> life_cooldown == 0)
		{	
			player-> status = 0;
			player-> is_invinceble = 0;
			player-> life_cooldown = 60;
		}
		
	}
	
	if (player->control-> down)
	{																																											//Se o botão de movimentação para baixo do controle do primeiro jogador está ativado...
		player_move(player, 1, 3, window_w, window_h);
		
		player-> status = 2;
		player-> h = 28;
		
		if (collision_x(player, map_vector, plataform_count, &indexCollision, *camera_xF) == 1)
			player-> x = map_vector[indexCollision]-> x - 40 - *camera_xF - player-> w/2;

		if (check_trapsX(trap_vector,trap_count,player,*camera_xF, &indexTraps) == 1 && player-> is_invinceble == 0)
			trap_efect(trap_vector[indexTraps], player);	
		
			
		else if (player-> is_invinceble == 1)
		{		
			player-> life_cooldown--;
			player-> status = 3;
		}
		
		if (player-> life_cooldown == 0)
		{	
			player-> status = 0;
			player-> is_invinceble = 0;
			player-> life_cooldown = 60;
		}
	}	
	else if (player->status == 2 && player->current_frame > 0 && collision_top(map_vector, player,plataform_count, *camera_xF) == 0) 
    {	
		player->status = 2; 
		player->h = 48;
	}
    																																				//Move o quadrado do primeiro jogador para a baixo
	if (player-> control-> up && *lastCollision == 1 && player-> status != 4)
	{																																											//Se o botão de movimentação para cima do controle do primeiro jogador está ativado...
		player_move(player, 1, 2, window_w, window_h);																																					//Move o quadrado do primeiro jogador para cima
		player-> touching_floor = 0;
	}
	
	player-> vY += gravity;

	if (player-> vY > max_fall)
		player-> vY = max_fall;
		
	player-> y += player-> vY;
	
	
	if (collision_y(player, map_vector, plataform_count, &indexCollision, *camera_xF) == 1) 
	{
		if (player-> vY >= 0)
			{
				player-> y = map_vector[indexCollision]-> y - player-> h/2 - 20;
				player-> touching_floor = 1;
			}
			else  
				player-> y = map_vector[indexCollision]-> y + map_vector[indexCollision]-> h + player-> h/2;
		
		player-> vY = 0;
	}			
				
	if (player-> y - player-> h/2 < 0)
	{
		player-> y = player-> h/2;
		player-> vY = 0;
	}
	
	
	if (check_trapsY(player, trap_vector, trap_count, &indexTraps, *camera_xF) == 1 && player-> is_invinceble == 0)	
	{	
		if (trap_vector[indexTraps]-> type == 5 && trap_vector[indexTraps]-> status == 0)
		{
			{
				if (player-> vY >= 0)
				{
					player-> y = trap_vector[indexTraps]-> y - player-> h/2 - 20;
					player-> touching_floor = 1;
				}
				else  
					player-> y = trap_vector[indexTraps]-> y + map_vector[indexTraps]-> h + player-> h/2;
		
				player-> vY = 0;
			}			
				
			if (player-> y - player-> h/2 < 0)
			{
				player-> y = player-> h/2;
				player-> vY = 0;
			}
		}
		
		trap_efect(trap_vector[indexTraps], player);	
	}
			
		else if (player-> is_invinceble == 1)
		{		
			player-> life_cooldown--;
			player-> status = 3;
		}
		
		if (player-> life_cooldown == 0)
		{	
			player-> status = 0;
			player-> is_invinceble = 0;
			player-> life_cooldown = 60;
		}
	
	return;
}

void update_game_state(int *gameState, ALLEGRO_BITMAP* menu, ALLEGRO_BITMAP* gameover)
{
   switch (*gameState)
    {
    case 67:
        break;
    
    case 1:
        al_draw_scaled_bitmap(gameover, 0, 0, 480, 320, 0,0 ,window_w,window_h, 0);  
		break;
	
	case 59:
        al_draw_scaled_bitmap(menu, 0, 0, 960, 540, 0,0 ,window_w,window_h, 0);
		break;

	case 2: 
		break;
    }
}

int main(){
	
	al_init();																		
	al_install_keyboard();
	al_init_image_addon();
	al_init_primitives_addon(); 
	al_init_font_addon(); 
   	al_init_ttf_addon();  															

	ALLEGRO_TIMER* timer = al_create_timer(1.0 / 30.0);								
	ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();							
								
	ALLEGRO_DISPLAY* disp = al_create_display(window_w, window_h);
	ALLEGRO_BITMAP *backgroundBack = al_load_bitmap("Layers/back.png");
	ALLEGRO_BITMAP *backgroundMiddle = al_load_bitmap("Layers/middle.png");	
	ALLEGRO_BITMAP *plataformTexture = al_load_bitmap("Layers/tiles.png");
	ALLEGRO_BITMAP *playerSprite = al_load_bitmap("playerAnimation/pixil-frame-0(14).png");
	ALLEGRO_BITMAP *lifeSprite = al_load_bitmap("hearts/heart_spritesheet_32x32.png");
	ALLEGRO_BITMAP *orange = al_load_bitmap ("hearts/fruit_orange_slice.png");
	ALLEGRO_BITMAP *chest = al_load_bitmap ("hearts/Icons_14.png");

	ALLEGRO_BITMAP *spikesSprite = al_load_bitmap("traps/16-bit-spike-Sheet.png");
	ALLEGRO_BITMAP *ladderSprite = al_load_bitmap("traps/pixil-frame-0(13).png");
	ALLEGRO_BITMAP *fireSprite = al_load_bitmap("traps/pixil-frame-0(15).png");
	ALLEGRO_BITMAP *slimeSprite = al_load_bitmap ("traps/slime_blob_spritesheet.png");
	ALLEGRO_BITMAP *dropPlataformSprite = al_load_bitmap ("traps/pixil-frame-0(17).png");
	

	ALLEGRO_BITMAP *menu = al_load_bitmap("Telas/xitake_menu(2).png");
	ALLEGRO_BITMAP *gameover = al_load_bitmap ("Telas/xitake_gameover(2).png");

	
	al_register_event_source(queue, al_get_keyboard_event_source());				
	al_register_event_source(queue, al_get_display_event_source(disp));				
	al_register_event_source(queue, al_get_timer_event_source(timer));				

	float bgBack_h = al_get_bitmap_height(backgroundBack);
	float bgBack_w = al_get_bitmap_width(backgroundBack);
	float bgMiddle_h = al_get_bitmap_height(backgroundMiddle);
	float bgMiddle_w = al_get_bitmap_width (backgroundMiddle);
	
	float escalaBack = (float)window_h / bgBack_h;
	float escalaMiddle = (float)window_h / bgMiddle_h;

	float bgBackAjustado = bgBack_w * escalaBack;
	float bgMiddleAjustado = bgMiddle_w * escalaMiddle;

	int camera_xM, camera_xB, camera_xF = 0;
	
	int camera_countF = ((float)window_w/ floor_w) +1;
	int camera_countM = ((float)window_w/bgMiddleAjustado) +1;
	int camera_countB = ((float)window_w/bgBackAjustado) +1;

	int lastCollision = 0;
	int plataform_count;
	int trap_count;
	int plus_life = 0;

	int source_x;
	int source_y;
	
	int gameState = 59;
	
	player *player = create_player(48, 48, 120, window_h/2, window_w, window_h);
	plataform **map_vector = create_mapvector(map_vector, floor_w, floor_h, &plataform_count, window_h);
	trap **trap_vector = create_trapvector(trap_vector, &trap_count,spikesSprite, ladderSprite, window_h ,floor_h);

	
	ALLEGRO_EVENT event;															
	al_start_timer(timer);															
	
	while(1){																		
		al_wait_for_event(queue, &event);											
		
		if (event.type == 30)
		{														
			al_clear_to_color(al_map_rgb(0, 0, 0)); 
			
			if (gameState == 67)
			{
				update_location(player,map_vector,plataform_count, &camera_xM, &camera_xB, &camera_xF, &lastCollision, trap_vector, trap_count);

				BackGroundParallax(camera_xB, camera_countB, bgBack_w, bgBack_h, bgBackAjustado, backgroundBack, window_h);
				MiddleGroundParallax(camera_xM, camera_countM,bgMiddle_w, bgMiddle_h, bgMiddleAjustado, backgroundMiddle, window_h);
				//FloorParallax (camera_xF, camera_countF, floor_w, floor_h, plataformTexture,window_h, map_vector, 3);

				for(int i = 0; i < plataform_count; i++)
				{	
					if (map_vector[i]-> type == 2)
						al_draw_scaled_bitmap(plataformTexture, 16, 11, 64, 64, map_vector[i]->x-camera_xF, map_vector[i]->y, floor_w*1.5, floor_h*1.5, 0);
					
					if (map_vector[i]-> type == 1)
						al_draw_scaled_bitmap(plataformTexture, 93, 11, 64, 64, map_vector[i]->x-camera_xF, map_vector[i]->y, floor_w*1.6, floor_h*1.6, 0);
				}
				
				reset_drop_plataforms (trap_vector,trap_count,player);
				
				for (int i = 0; i< trap_count; i++)
					print_trap(trap_vector[i], camera_xF, spikesSprite, ladderSprite, fireSprite, slimeSprite,dropPlataformSprite, map_vector, plataform_count,player);
				
				if (plus_life == 0)
					al_draw_scaled_bitmap(orange, 0, 0, 16, 16, 3333 - camera_xF, 420, 16*2, 16*2,0);
				
				if ((player-> y + player-> h/2) > (420) 
        		&& (player-> y - player-> h/2) < (420 + 32)
        		&& (player-> x + player-> w/2) > (3333 - camera_xF)
        		&& (player-> x - player-> w/2) < (3333- camera_xF + 32) && plus_life == 0)
				{
					plus_life = 1;
					player-> life += 1;
				}
				
				for(int i = 1; i <= player-> life; i++)
					al_draw_scaled_bitmap(lifeSprite, 0, 0, 32, 32, 35*i ,35,32,32,0);
				
				al_draw_scaled_bitmap(chest, 0, 0, 32, 32, 5000 - camera_xF, 420, 32*2, 32*2,0);
				
				if ((player-> y + player-> h/2) > (420) 
        		&& (player-> y - player-> h/2) < (420 + 32)
        		&& (player-> x + player-> w/2) > (5000 - camera_xF)
        		&& (player-> x - player-> w/2) < (5000- camera_xF + 32) && plus_life == 0)
				{
					gameState = 2;
				}
				
				
				player_animation (player);
				
				source_x = player-> current_frame * frame;
				source_y = player-> status * frame;
				
				int ALLEGRO_FLIP_HORIZONTAL = player-> turning_left;
				al_draw_scaled_bitmap(playerSprite, source_x, source_y, 48, 48,player-> x-player-> w/2, player-> y-player-> h/2,96,96, ALLEGRO_FLIP_HORIZONTAL);
			}
			
			if (player-> y - player-> h/2 > window_h || player-> life <= 0)
			{	
				gameState = 1;
				soft_reset(player, &camera_xM, &camera_xB,&camera_xF, window_h, trap_vector, trap_count, &plus_life);
			}
			
			update_game_state(&gameState, menu, gameover);
			al_flip_display();														
		
		}	
			
		else if ((event.type == 10) || (event.type == 12))
		{																																				
			if (event.keyboard.keycode == 1) joystick_left(player-> control);																															
			else if (event.keyboard.keycode == 4) joystick_right(player-> control);																													
			else if (event.keyboard.keycode == 23) joystick_up(player-> control);																
						else if (event.keyboard.keycode == 19) joystick_down(player-> control);
			else if (event.keyboard.keycode == 67) gameState = 67;
			else if (event.keyboard.keycode == 59) gameState = 59;																													//Indica o evento correspondente no controle do primeiro jogador (botão de movimentação para baixo)
		}
			
		else if (event.type == 42) break;											
	}

															
	al_destroy_display(disp);														
	al_destroy_timer(timer);														
	al_destroy_event_queue(queue);
	al_shutdown_primitives_addon();
	
	destroy_traps (trap_vector,trap_count);
	destroy_plataform(map_vector, plataform_count);
	destroy_backgorund (plataformTexture, backgroundMiddle, backgroundBack);
	destroy_player(player);
												

	return 0;
}