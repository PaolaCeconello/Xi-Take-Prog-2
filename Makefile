
	

flags = `pkg-config allegro-5 allegro_main-5 allegro_font-5 allegro_image-5 allegro_primitives-5 allegro_ttf-5 allegro_audio-5 allegro_acodec-5 --libs --cflags`

Main:a3.c Player.c Plataform.c Joystick.c BackGroundParallax.c Collision.c SoftReset.c Traps.c Animations.c Player.h Plataform.h Joystick.h BackGroundParallax.h Collision.h SoftReset.h Traps.h Animations.h
		 gcc a3.c Player.c Plataform.c Joystick.c BackGroundParallax.c Collision.c SoftReset.c Traps.c Animations.c -o jogo $(flags)

.PHONY: clean

clean:
	rm -f jogo