#ifndef ANIMATIONS_H
#define ANIMATIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>	
#include "Player.h"
#include "Traps.h"
#include "Plataform.h"
#include "Collision.h"

void player_animation (player* player);
void fire_animation (trap* trap);
void slime_animation (trap *trap, plataform *map_vector[], int plataform_count, int camera_xF);
void drop_plataform_animation (trap *trap, player*player);

#endif