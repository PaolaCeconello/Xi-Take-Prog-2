
	

flags = `pkg-config allegro-5 allegro_main-5 allegro_font-5 allegro_image-5 allegro_primitives-5 --libs --cflags`

Main:a3.c Player.c Plataform.c Joystick.c BackGroundParallax.c Collision.c Player.h Plataform.h Joystick.h BackGroundParallax.h Collision.h
		 gcc a3.c Player.c Plataform.c Joystick.c BackGroundParallax.c Collision.c -o jogo $(flags)
 