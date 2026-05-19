//Compilação: gcc a3.c Player.c Plataform.c -o jogo $(pkg-config allegro-5 allegro_main-5 allegro_font-5 allegro_image-5 allegro_primitives-5 --libs --cflags)
#include <allegro5/allegro5.h>														//Biblioteca base do Allegro
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include "Player.h"
#include "Plataform.h"

#define window_h 540 //Biblioteca de fontes do Allegro
#define window_w 960

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
	ALLEGRO_BITMAP *plataformTexture = al_load_bitmap("Layers/tiles.png");						//Cria uma janela para o programa, define a largura (x) e a altura (y) da tela em píxeis (320x320, neste caso)

	al_register_event_source(queue, al_get_keyboard_event_source());				//Indica que eventos de teclado serão inseridos na nossa fila de eventos
	al_register_event_source(queue, al_get_display_event_source(disp));				//Indica que eventos de tela serão inseridos na nossa fila de eventos
	al_register_event_source(queue, al_get_timer_event_source(timer));				//Indica que eventos de relógio serão inseridos na nossa fila de eventos

	float bgBack_h = al_get_bitmap_height(backgroundBack);
	float bgBack_w = al_get_bitmap_width(backgroundBack);
	float bgMiddle_h = al_get_bitmap_height(backgroundMiddle);
	float bgMiddle_w = al_get_bitmap_width (backgroundMiddle);
	float escalaBack = (float)window_h / bgBack_h;
	float escalaMiddle = (float)window_h / bgMiddle_h;

	float bgBackregular = bgBack_w * escalaBack;
	float bgMiddleregular = bgMiddle_w * escalaMiddle;

	float floor_w = al_get_bitmap_width(plataformTexture);
	float floor_h = al_get_bitmap_height(plataformTexture);
	plataform *floor = create_plataform(floor_w, 700, window_w, window_h);

	float escalaFloor = (float)window_h/ floor_h;
	float floorregular = floor_w * escalaFloor; 
	
	ALLEGRO_EVENT event;															//Variável que guarda um evento capturado, sua estrutura é definida em: https://www.allegro.cc/manual/5/ALLEGRO_EVENT
	al_start_timer(timer);															//Função que inicializa o relógio do programa
	while(1){																		//Laço principal do programa
		al_wait_for_event(queue, &event);											//Função que captura eventos da fila, inserindo os mesmos na variável de eventos
		
		if (event.type == 30){														//O evento tipo 30 indica um evento de relógio, ou seja, verificação se a tela deve ser atualizada (conceito de FPS)
			al_clear_to_color(al_map_rgb(0, 0, 0)); // Clear screen first

			for (float x = 0; x < window_w; x += bgBackregular) {
    			al_draw_scaled_bitmap(backgroundBack, 0, 0, bgBack_w, bgBack_h, x, 0, bgBackregular, window_h, 0);							//Substitui tudo que estava desenhado na tela por um fundo preto
			}
			
			for (float x = 0; x < window_w; x += bgMiddleregular) {
    			al_draw_scaled_bitmap(backgroundMiddle, 0, 0, bgMiddle_w, bgMiddle_h, x, 0, bgMiddleregular, window_h, 0);							//Substitui tudo que estava desenhado na tela por um fundo preto
			}
			
			/*for (float x = 0; x < window_w; x += floorregular) {
    			al_draw_scaled_bitmap(plataformTexture, 0, 0, floor_w, floor_h, x, (window_h-floorregular), floor_h* escalaFloor,floor_w* escalaFloor, 0);							//Substitui tudo que estava desenhado na tela por um fundo preto
			}*/

			float novo_floor_w = 250.0; 
			float novo_floor_h = 250.0; 

			for (float x = 0; x < 960; x += novo_floor_w) {
    		al_draw_scaled_bitmap(plataformTexture, 0, 0, 96, 96, x, (540 - novo_floor_h), novo_floor_w, novo_floor_h, 0);                            
			}	
			
			al_flip_display();														//Insere as modificações realizadas nos buffers de tela
		}
		else if (event.type == 42) break;											//Evento de clique no "X" de fechamento da tela. Encerra o programa graciosamente.
	}

	al_destroy_font(font);															//Destrutor da fonte padrão
	al_destroy_display(disp);														//Destrutor da tela
	al_destroy_timer(timer);														//Destrutor do relógio
	al_destroy_event_queue(queue);
	al_destroy_bitmap(backgroundBack);		
	al_destroy_bitmap(backgroundMiddle);
												//Destrutor da fila

	return 0;
}