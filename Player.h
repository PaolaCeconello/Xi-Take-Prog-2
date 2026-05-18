
//#include "Animation.h"

#include <allegro5/allegro5.h>														//Biblioteca base do Allegro
#include <allegro5/allegro_image.h>
#define SQUARE_STEP 10																																//Tamanho, em pixels, de um passo do quadrado

typedef struct {
    ALLEGRO_BITMAP *sheet;
    int frame_w;
    int frame_h;
    int max_frames;
    int atual_frame;
    int frame_count;
    int frame_delay; 
} animation;


typedef struct 
{																																	//Definição da estrutura de um quadrado
    unsigned short h;
    unsigned short w;
    unsigned short x;																																//Posição X do centro do quadrado
	unsigned short y;
    int turning_left;
    animation idle;																																//Posição Y do centro do quadrado
																																		//Elemento para realizar disparos no jogo
} player;																																			//Definição do nome da estrutura

player* create_player(unsigned short h, unsigned short w, unsigned short x, unsigned short y, unsigned short max_x, unsigned short max_y);		//Protótipo da função de criação de um quadrado
//void move_player(player *element, char steps, unsigned char trajectory, unsigned short max_x, unsigned short max_y);								//Protótipo da função de movimentação de um quadrado
void draw_player(player* player);
void destroy_player(player *element);																												//Protótipo da função de destruição de um quadrado
