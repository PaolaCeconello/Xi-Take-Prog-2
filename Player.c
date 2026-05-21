#include <stdlib.h>
#include "Player.h"
#include "Joystick.h"

player* create_player (unsigned short h, unsigned short w, unsigned short x, unsigned short y, unsigned short max_x, unsigned short max_y)
{
    if ((x - w/2 < 0) || (x + w/2 > max_x) || (y - h/2 < 0) || (y + h/2 > max_y)) 
        return (NULL);												//Verifica se a posição inicial é válida; caso não seja, retorna NULL
																															//Verifica se a face principal do quadrado é válida
    player *new_player = (player*) malloc(sizeof(player));																								//Aloca memória na heap para um novo quadrado
	
    if (!new_player)
        return (NULL);																														//Se a alocação não deu certo, retorna erro													
	
    new_player-> h = h;																																	//Insere a posição inicial central de X
	new_player-> w = w;																																	//Insere o total de pontos de vida de um quadrado (!)
	new_player-> x = x;																																	//Insere a posição inicial central de X
	new_player-> y = y;
    new_player-> turning_left = 0;
    new_player-> control = joystick_create();
  
    return (new_player);
}

void player_move(player *element, char steps, unsigned char trajectory, unsigned short max_x, unsigned short max_y) {									//Implementação da função "square_move"

	if (trajectory == 0)
    { 
        if ((element-> x - steps *PLAYER_STEP) - element-> w/2 >= tropicL) 
            element->x = element->x - steps*PLAYER_STEP;
    } 						//Verifica se a movimentação para a esquerda é desejada e possível; se sim, efetiva a mesma
	else if (trajectory == 1)
    { 
        if ((element->x + steps *PLAYER_STEP) + element-> w/2 <= max_x)
            element->x = element->x + steps*PLAYER_STEP;
    }			//Verifica se a movimentação para a direita é desejada e possível; se sim, efetiva a mesma
	else if (trajectory == 2)
    { 
        if ((element->y - steps *PLAYER_STEP) - element-> h/2 >= 0) 
            element->y = element->y - steps*PLAYER_STEP;
    }				//Verifica se a movimentação para cima é desejada e possível; se sim, efetiva a mesma
	else if (trajectory == 3)
    { 
        if ((element->y + steps *PLAYER_STEP) + element-> h/2 <= max_y) 
            element->y = element->y + steps*PLAYER_STEP;
    }			//Verifica se a movimentação para baixo é desejada e possível; se sim, efetiva a mesma
}

void destroy_player(player *element)
{
    joystick_destroy(element-> control);
    free(element);
    
    return;
}																												//Protótipo da função de destruição de um quadrado
