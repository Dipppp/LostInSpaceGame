#ifndef BASEINTERFACE_H
#define BASEINTERFACE_H

#include <allegro.h>

#include "SoundEffects.h"
#include "Button.h"

//PURPOSE - The base class for all the games screens
class BaseInterface {
	public:
		//PURPOSE:	NONE
		//INPUT:	NONE
		//OUTPUT:	NONE
		BaseInterface();
		//PURPOSE:	Free the background image from memory
		//INPUT:	NONE
		//OUTPUT:	NONE
		~BaseInterface();
		//PURPOSE:	Draws the background image
		//INPUT:	NONE
		//OUTPUT:	NONE
		void draw();
		
	protected:
		//PURPOSE:	The pointer to the bitmap that is the game screen and what everything is drawn on 
		BITMAP *mScreen;
		//PURPOSE:	The pointer to background image bitmap
		BITMAP *mBackgroundImage;
		//PURPOSE:	The pointer to all the images a screen uses
		BITMAP *mImagePage;
		//PURPOSE:	The width of the background image
		int mBackgroundWidth;
		//PURPOSE:	The height of the background image
		int mBackgroundHeight;
};

#endif
