#ifndef COLLISION_H
#define COLLISION_H

#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro5.h>														

#include "Player.h"
#include "Plataform.h"
#include "Traps.h"

int collision (player* player, plataform* map_vector[], int plataform_count, int *index, int camera_xF, int *axis);

int collision_x (player* player, plataform* map_vector[], int plataform_count, int *index, int camera_xF);

int collision_y(player* player, plataform* map_vector[], int plataform_count, int *index, int camera_xF);

int collision_top (plataform *map_vector[], player *player, int plataform_count, int camera_xF);

#endif