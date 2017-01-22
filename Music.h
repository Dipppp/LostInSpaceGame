#ifndef MUSIC_H
#define MUSIC_H

#include <allegro.h>
#include "defines.h"


//PURPOSE - The Class is for loading and playing the game's music
class Music {
	public:
		//PURPOSE:	Loads all the game music
		//INPUT:	Data			- The pointer to game data
		//OUTPUT:	NONE
		Music(DATAFILE *Data);
		//PURPOSE:	Release all the music
		//INPUT:	NONE
		//OUTPUT:	NONE
		~Music();
		//PURPOSE:	
		//INPUT:	NONE
		//OUTPUT:	NONE
		void play();
		//PURPOSE:	
		//INPUT:	NONE
		//OUTPUT:	NONE
		void musicToggle();
	private:
		MIDI **mMusic;
		bool mPaused;
};

#endif
