#ifndef TRAPS_H
#define TRAPS_H


#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>	
#include "Traps.h"
#include "Player.h"


typedef struct 
{
    float x;
    float y;
    float w;
    float h;
    int type;
}trap;


trap** create_trapvector (trap *trap_vector[], int *trap_count, ALLEGRO_BITMAP *spikesSprite, int window_h, int floor_h); 
void check_traps (trap* trap_vector[], int trap_count, player *player, int camera_xF);
int check_trapsX(trap* trap_vector[], int trap_count, player *player, int camera_xF, int *index);
int check_trapsY(player* player, trap* trap_vector[], int trap_count, int *index, int camera_xF);
void trap_efect (int type, player* player);
void print_trap (trap *trap, int camera_xF, ALLEGRO_BITMAP *spikesSprite);
void destroy_traps (trap *trap_vector[], int trap_count);
#endif