#ifndef SOFTRESET_H
#define SOFTRESET_H

#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>	
#include "Player.h"
#include "Plataform.h"
#include "BackGroundParallax.h"
#include "Collision.h"
#include "Traps.h"


void soft_reset(player* player, int *camera_xM, int *camera_xB, int *camera_xF, int window_h, trap *trap_vector[], int trap_count, int *plus_life);

void reset_drop_plataforms (trap* trap_vector[], int trap_count, player *player);

#endif