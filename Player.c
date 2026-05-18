#include <stdlib.h>
#include "Player.h"
//#include "Animation.h"


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
  
    
    return (new_player);
}


void destroy_player(player *element)
{
    
    free(element);
    
    return;
}																												//Protótipo da função de destruição de um quadrado
