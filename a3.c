//Compilação: gcc a3.c Player.c Plataform.c Joystick.c BackGroundParallax.c -o jogo $(pkg-config allegro-5 allegro_main-5 allegro_font-5 allegro_image-5 allegro_primitives-5 --libs --cflags)
#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro5.h>														
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include "Player.h"
#include "Plataform.h"
#include "BackGroungParallax.h"

#define window_h 540
#define window_w 960
#define camera_speed 8


void update_loacation(player *player, int *camera_x)
{ 
	if (player->control->left){																																											//Se o botão de movimentação para esquerda do controle do primeiro jogador está ativado...
			player_move(player, 1, 0, window_w, window_h);
			player-> turning_left = 1;
			*camera_x -= camera_speed;																																				//Move o quadrado do primeiro jogador para a esquerda
			//if (collision_2D(player_1, player_2)) square_move(player_1, -1, 0, X_SCREEN, Y_SCREEN);																												//Se o movimento causou uma colisão entre quadrados, desfaça o mesmo
		}
		if (player->control->right){																																											//Se o botão de movimentação para direita do controle do primeir ojogador está ativado...
			player_move(player, 1, 1, window_w, window_h);
			player-> turning_left = 0;	
			*camera_x += camera_speed;																																				//Move o quadrado do primeiro jogador para a direta
			//if (collision_2D(player_1, player_2)) square_move(player_1, -1, 1, X_SCREEN, Y_SCREEN);																												//Se o movimento causou uma colisão entre quadrados, desfaça o mesmo
		}
		if (player->control->up) {																																											//Se o botão de movimentação para cima do controle do primeiro jogador está ativado...
			player_move(player, 1, 2, window_w, window_h);																																					//Move o quadrado do primeiro jogador para cima
			//if (collision_2D(player_1, player_2)) square_move(player_1, -1, 2, X_SCREEN, Y_SCREEN);																												//Se o movimento causou uma colisão entre quadrados, desfaça o mesmo
		}
		if (player->control->down){																																											//Se o botão de movimentação para baixo do controle do primeiro jogador está ativado...
			player_move(player, 1, 3, window_w, window_h);																																					//Move o quadrado do primeiro jogador para a baixo
			//if (collision_2D(player_1, player_2)) square_move(player_1, -1, 3, X_SCREEN, Y_SCREEN);																												//Se o movimento causou uma colisão entre quadrados, desfaça o mesmo
		}

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
	ALLEGRO_BITMAP *plataformTexture = al_load_bitmap("Layers/tilescontinue.png");
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

	float floor_w = al_get_bitmap_width(plataformTexture);
	float floor_h = al_get_bitmap_height(plataformTexture);
	//plataform *floor = create_plataform(floor_w, 700, window_w, window_h);

	int camera_x = 0;
	int camera_count = ((float)window_w/bgMiddleAjustado) +1;
	
	player *player = create_player(48, 48, 60, 300, window_w, window_h);
	
	ALLEGRO_EVENT event;															//Variável que guarda um evento capturado, sua estrutura é definida em: https://www.allegro.cc/manual/5/ALLEGRO_EVENT
	al_start_timer(timer);															//Função que inicializa o relógio do programa
	
	while(1){																		//Laço principal do programa
		al_wait_for_event(queue, &event);											//Função que captura eventos da fila, inserindo os mesmos na variável de eventos
		
		if (event.type == 30)
		{														//O evento tipo 30 indica um evento de relógio, ou seja, verificação se a tela deve ser atualizada (conceito de FPS)
			al_clear_to_color(al_map_rgb(0, 0, 0)); 
			
			update_loacation(player, &camera_x);
			
			for (float x = 0; x < window_w; x += bgBackAjustado) 
			{
    			al_draw_scaled_bitmap(backgroundBack, 0, 0, bgBack_w, bgBack_h, x, 0, bgBackAjustado, window_h, 0);							//Substitui tudo que estava desenhado na tela por um fundo preto
			}
			
			/*int i = 0;
			int start_x = -(camera_x % (int) bgMiddleAjustado);
			while(i < camera_count+1)
			{
				int x = start_x + (i * bgMiddleAjustado);
				
				al_draw_scaled_bitmap(backgroundMiddle, 0, 0, bgMiddle_w, bgMiddle_h, x, 0, bgMiddleAjustado, window_h, 0);
			
				i++;
			}*/
			
			MiddleGroundParallax(camera_x, camera_count,bgMiddle_w, bgMiddle_h, bgMiddleAjustado, backgroundMiddle, window_h);
			
			for (float x = 0; x < window_w; x += floor_w) {
    			al_draw_scaled_bitmap(plataformTexture, 0, 0, floor_w, floor_h, x, (window_h - floor_h), floor_w, floor_h, 0);							//Substitui tudo que estava desenhado na tela por um fundo preto
			}

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
	al_destroy_bitmap(backgroundBack);		
	al_destroy_bitmap(backgroundMiddle);
	al_destroy_bitmap(plataformTexture);
	destroy_player(player);
												

	return 0;
}