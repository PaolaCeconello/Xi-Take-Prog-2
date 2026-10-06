#ifndef TRAPS_H
#define TRAPS_H

#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>	
#include "Player.h"
#include "Plataform.h"

typedef struct 
{
    float x;
    float y;
    float w;
    float h;
    int type;
    int max_frames;
    int frame_count;
    int current_frame;
    int frame_delay;
    int is_on;
    int cooldown;
    int turning_left;
    int limitR;
    int limitL;
    int status;
    float original_y;
}trap;


trap** create_trapvector (trap *trap_vector[], int *trap_count, ALLEGRO_BITMAP *spikesSprite, ALLEGRO_BITMAP *ladderSprite, int window_h, int floor_h); 

int check_trapsX(trap* trap_vector[], int trap_count, player *player, int camera_xF, int *index);

int check_trapsY(player* player, trap* trap_vector[], int trap_count, int *index, int camera_xF);

void trap_efect (trap* trap, player* player);

void print_trap (trap *trap, int camera_xF, ALLEGRO_BITMAP *spikesSprite, ALLEGRO_BITMAP *ladderSprite, ALLEGRO_BITMAP *fireSprite, ALLEGRO_BITMAP *slimeSprite, ALLEGRO_BITMAP *dropPlataformSprite, plataform *map_vector[], int plataform_count, player*player);

void destroy_traps (trap *trap_vector[], int trap_count);

#endif