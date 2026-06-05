
	

flags = `pkg-config allegro-5 allegro_main-5 allegro_font-5 allegro_image-5 allegro_primitives-5 allegro_ttf-5 --libs --cflags`

Main:a3.c Player.c Plataform.c Joystick.c BackGroundParallax.c Collision.c SoftReset.c Player.h Plataform.h Joystick.h BackGroundParallax.h Collision.h SoftReset.h
		 gcc a3.c Player.c Plataform.c Joystick.c BackGroundParallax.c Collision.c SoftReset.c -o jogo $(flags)
 