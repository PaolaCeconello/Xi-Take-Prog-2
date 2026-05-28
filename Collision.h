#ifndef COLLISION_H
#define COLLISION_H

#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro5.h>														

#include "Player.h"
#include "Plataform.h"

int collision (player* player, plataform* map_vector[], int plataform_count, int *index);

#endif