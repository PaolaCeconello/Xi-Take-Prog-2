
//#include "Animation.h"

#include <allegro5/allegro5.h>														//Biblioteca base do Allegro
#include <allegro5/allegro_image.h>
#define SQUARE_STEP 10																																//Tamanho, em pixels, de um passo do quadrado

typedef struct 
{																																	//Definição da estrutura de um quadrado
    unsigned short h;
    unsigned short w;
    unsigned short x;																																//Posição X do centro do quadrado
	unsigned short y;
    int turning_left;
} player;																																			//Definição do nome da estrutura

player* create_player(unsigned short h, unsigned short w, unsigned short x, unsigned short y, unsigned short max_x, unsigned short max_y);		//Protótipo da função de criação de um quadrado
							                                  //Protótipo da função de movimentação de um quadrado
void draw_player(player* player);
void destroy_player(player *element);																												//Protótipo da função de destruição de um quadrado
