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


void soft_reset(player* player, int *camera_xM, int *camera_xB, int *camera_xF, int window_h);

#endif