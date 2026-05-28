//Compilação: gcc a3.c Player.c Plataform.c Joystick.c BackGroundParallax.c -o jogo $(pkg-config allegro-5 allegro_main-5 allegro_font-5 allegro_image-5 allegro_primitives-5 --libs --cflags)
#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro5.h>														
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include "Player.h"
#include "Plataform.h"
#include "BackGroundParallax.h"
#include "Collision.h"

#define window_h 540
#define window_w 960
#define floor_w 69  
#define floor_h 64 
#define camera_speedF 12
#define camera_speedM 10
#define camera_speedB 4
#define gravity 2
#define max_fall 16

void update_loacation(player *player, plataform *map_vector[], int plataform_count, int *camera_xM, int *camera_xB, int *camera_xF, int *lastCollision)
{ 
	
	*lastCollision = player-> touching_floor;
	player-> touching_floor = 0;
	int index;
	
	player-> vY += gravity;

	if (player-> control-> left)
	{																																											//Se o botão de movimentação para esquerda do controle do primeiro jogador está ativado...
		player_move(player, 1, 0, window_w, window_h);
		player-> turning_left = 1;
				
		if (player-> x >= tropicL && player-> x < tropicR)
		{
			*camera_xM -= camera_speedM;
			*camera_xB -= camera_speedB;
			*camera_xF -= camera_speedF;
		}
	}	
	if (player->control->right)
	{																																											//Se o botão de movimentação para direita do controle do primeir ojogador está ativado...
		player_move(player, 1, 1, tropicR, window_h);
		player-> turning_left = 0;
			
		if (player-> x > tropicL && player-> x <= tropicR)
		{	
			*camera_xM += camera_speedM;
			*camera_xB += camera_speedB;
			*camera_xF += camera_speedF;																																				//Move o quadrado do primeiro jogador para a direta
		}
	}
	
	if (player-> control-> up && *lastCollision == 1)
	{																																											//Se o botão de movimentação para cima do controle do primeiro jogador está ativado...
		player_move(player, 1, 2, window_w, window_h);																																					//Move o quadrado do primeiro jogador para cima
		player-> touching_floor = 0;
	}
	
	if (player-> vY > max_fall)
		player-> vY = max_fall;
		
	player-> y += player-> vY;
		
	
	if (collision(player, map_vector, plataform_count, &index) == 1) 
	{
		player-> y = map_vector[index]-> y - map_vector[index]-> w/2 - (player-> h/2);
		player-> touching_floor = 1;
		player-> vY = 0;
	}			
				
			/*if (player->control->down){																																											//Se o botão de movimentação para baixo do controle do primeiro jogador está ativado...
			player_move(player, 1, 3, window_w, window_h);																																					//Move o quadrado do primeiro jogador para a baixo
			player-> vY = -jump_force;
			//if (collision_2D(player_1, player_2)) square_move(player_1, -1, 3, X_SCREEN, Y_SCREEN);																												//Se o movimento causou uma colisão entre quadrados, desfaça o mesmo
		}*/
	return;
}

int main(){
	
	al_init();																		//Faz a preparação de requisitos da biblioteca Allegro
	al_install_keyboard();
	al_init_image_addon();															//Habilita a entrada via teclado (eventos de teclado), no programa

	ALLEGRO_TIMER* timer = al_create_timer(1.0 / 30.0);								//Cria o relógio do jogo; isso indica quantas atualizações serão realizadas por segundo (30, neste caso)
	ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();							//Cria a fila de eventos; todos os eventos (programação orientada a eventos) 
	ALLEGRO_FONT* font = al_create_builtin_font();									//Carrega uma fonte padrão para escrever na tela (é bitmap, mas também suporta adicionar fontes ttf)
	
	ALLEGRO_DISPLAY* disp = al_create_display(window_w, window_h);
	ALLEGRO_BITMAP *backgroundBack = al_load_bitmap("Layers/back.png");
	ALLEGRO_BITMAP *backgroundMiddle = al_load_bitmap("Layers/middle.png");	
	ALLEGRO_BITMAP *plataformTexture = al_load_bitmap("Layers/tiles.png");
	ALLEGRO_BITMAP *playerSprite = al_load_bitmap("playerAnimation/cute_mushroom_idle.png");						//Cria uma janela para o programa, define a largura (x) e a altura (y) da tela em píxeis (320x320, neste caso)

	al_register_event_source(queue, al_get_keyboard_event_source());				//Indica que eventos de teclado serão inseridos na nossa fila de eventos
	al_register_event_source(queue, al_get_display_event_source(disp));				//Indica que eventos de tela serão inseridos na nossa fila de eventos
	al_register_event_source(queue, al_get_timer_event_source(timer));				//Indica que eventos de relógio serão inseridos na nossa fila de eventos

	float bgBack_h = al_get_bitmap_height(backgroundBack);
	float bgBack_w = al_get_bitmap_width(backgroundBack);
	float bgMiddle_h = al_get_bitmap_height(backgroundMiddle);
	float bgMiddle_w = al_get_bitmap_width (backgroundMiddle);
	
	float escalaBack = (float)window_h / bgBack_h;
	float escalaMiddle = (float)window_h / bgMiddle_h;

	float bgBackAjustado = bgBack_w * escalaBack;
	float bgMiddleAjustado = bgMiddle_w * escalaMiddle;

	//float floor_w = al_get_bitmap_width(plataformTexture);
	//float floor_h = al_get_bitmap_height(plataformTexture);
	
	int camera_xM, camera_xB, camera_xF = 0;
	
	int camera_countF = ((float)window_w/ floor_w) +1;
	int camera_countM = ((float)window_w/bgMiddleAjustado) +1;
	int camera_countB = ((float)window_w/bgBackAjustado) +1;

	int lastCollision = 0;
	int plataform_count;
	
	player *player = create_player(48, 48, 50, window_h/2, window_w, window_h);
	plataform *floor = create_plataform(0, (window_h - floor_h - player->h/2), window_w, floor_h);
	plataform **map_vector = create_mapvector(map_vector, floor_w, floor_h, &plataform_count, window_h);

	
	ALLEGRO_EVENT event;															//Variável que guarda um evento capturado, sua estrutura é definida em: https://www.allegro.cc/manual/5/ALLEGRO_EVENT
	al_start_timer(timer);															//Função que inicializa o relógio do programa
	
	while(1){																		//Laço principal do programa
		al_wait_for_event(queue, &event);											//Função que captura eventos da fila, inserindo os mesmos na variável de eventos
		
		if (event.type == 30)
		{														//O evento tipo 30 indica um evento de relógio, ou seja, verificação se a tela deve ser atualizada (conceito de FPS)
			al_clear_to_color(al_map_rgb(0, 0, 0)); 
			
			update_loacation(player,map_vector,plataform_count, &camera_xM, &camera_xB, &camera_xF, &lastCollision);

			BackGroundParallax(camera_xB, camera_countB, bgBack_w, bgBack_h, bgBackAjustado, backgroundBack, window_h);
			MiddleGroundParallax(camera_xM, camera_countM,bgMiddle_w, bgMiddle_h, bgMiddleAjustado, backgroundMiddle, window_h);
			//FloorParallax (camera_xF, camera_countF, floor_w, floor_h, plataformTexture,window_h, map_vector, 3);

			for(int i = 0; i < plataform_count; i++)
				al_draw_scaled_bitmap(plataformTexture, 16, 11, 64, 69, map_vector[i]->x-camera_xF, map_vector[i]->y, floor_w*1.5, floor_h*1.5, 0);
			
			
			int ALLEGRO_FLIP_HORIZONTAL = player-> turning_left;
			al_draw_scaled_bitmap(playerSprite, 0, 0, 48, 48,player-> x-player-> w/2, player-> y-player-> h/2,96,96, ALLEGRO_FLIP_HORIZONTAL);
			
			al_flip_display();														//Insere as modificações realizadas nos buffers de tela
		
		}	
			
		else if ((event.type == 10) || (event.type == 12))
		{																																				//Verifica se o evento é de botão do teclado abaixado ou levantado
			if (event.keyboard.keycode == 1) joystick_left(player-> control);																															//Indica o evento correspondente no controle do primeiro jogador (botão de movimentação à esquerda)
			else if (event.keyboard.keycode == 4) joystick_right(player-> control);																													//Indica o evento correspondente no controle do primeiro jogador (botão de movimentação à direita)
			else if (event.keyboard.keycode == 23) joystick_up(player-> control);																														//Indica o evento correspondente no controle do primeiro jogador (botão de movimentação para cima)
			else if (event.keyboard.keycode == 19) joystick_down(player-> control);																													//Indica o evento correspondente no controle do primeiro jogador (botão de movimentação para baixo)
		}
			
		else if (event.type == 42) break;											//Evento de clique no "X" de fechamento da tela. Encerra o programa graciosamente.
	
					
		
	}

	al_destroy_font(font);															//Destrutor da fonte padrão
	al_destroy_display(disp);														//Destrutor da tela
	al_destroy_timer(timer);														//Destrutor do relógio
	al_destroy_event_queue(queue);
	
	destroy_plataform(map_vector, plataform_count);
	destroy_backgorund (plataformTexture, backgroundMiddle, backgroundBack);
	destroy_player(player);
												

	return 0;
}