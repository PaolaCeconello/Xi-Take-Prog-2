
#ifndef PLAYER_H
#define PLAYER_H

#include <allegro5/allegro5.h>														//Biblioteca base do Allegro
#include <allegro5/allegro_image.h>
#include "Joystick.h"

#define PLAYER_STEP 12
#define PLAYER_JUMP 28
#define tropicR window_w/2
#define tropicL 960/10																															//Tamanho, em pixels, de um passo do quadrado

typedef struct 
{																																	//Definição da estrutura de um quadrado
    unsigned short h;
    unsigned short w;
    unsigned short x;																																//Posição X do centro do quadrado
	unsigned short y;
    int turning_left;
    int touching_floor;
    int vY;
    int life;
    int life_cooldown;
    int is_invinceble;
    int status;
    float current_frame;
    int max_frames;
    int frame_count;
    int frame_delay;
    
    joystick *control;
} player;																																			//Definição do nome da estrutura

player* create_player(unsigned short h, unsigned short w, unsigned short x, unsigned short y, unsigned short max_x, unsigned short max_y);		//Protótipo da função de criação de um quadrado
void player_move(player *element, char steps, unsigned char trajectory, unsigned short max_x, unsigned short max_y);					                                  //Protótipo da função de movimentação de um quadrado
void draw_player(player* player);
void destroy_player(player *element);																												//Protótipo da função de destruição de um quadrado

#endif