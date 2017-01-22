#include <allegro.h>

#include "GameLogic.h"
#include "Images.h"

GameLogic *gameLogic;




int main(void)
{

    //initialize
    allegro_init();
    set_color_depth(24);
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, 800, 600, 0, 0);
    install_keyboard();
    install_mouse();
    install_timer();
    srand(time(NULL));
    gameLogic = new GameLogic();
    //install a digital sound driver
    if (install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT, NULL) != 0) 
    {
        allegro_message("Error initializing sound system");
        return 1;
    }
	show_mouse(screen);

	
    //game loop
    while (!key[KEY_ESC])
    {

        //lock the screen
        acquire_screen();

		
		gameLogic->draw();
		gameLogic->update();
        //unlock the screen
        release_screen();

        rest(10);
    }

	//destroy_bitmap(Buffer);

    allegro_exit();
    return 0;
}
END_OF_MAIN()
