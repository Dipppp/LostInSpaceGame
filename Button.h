#ifndef BUTTON_H
#define BUTTON_H

#include <allegro.h>

#include "SoundEffects.h"
#include "CollisionDetection.h"

//PURPOSE - To create button object
class Button {
	public:
		//PURPOSE:	Sets the default value for the button
		//INPUT:	SoundEffect	- Pointer to the sound effects
		//			X			- X position for the button to take
		//			Y			- Y position for the button to take
		//			Width		- Width for the button to take
		//			Height		- Height for the button to take
		//OUTPUT:	NONE
		Button(SoundEffects *SoundEffect, int X, int Y, int Width, int Height);
		//PURPOSE:	NONE
		//INPUT:	NONE
		//OUTPUT:	NONE
		~Button();
		//PURPOSE:	Draw a rectangle for the button
		//INPUT:	Screen		- Pointer to game screen
		//OUTPUT:	NONE
		void draw(BITMAP *Screen);
		//PURPOSE:	Checks if the button was clicked
		//INPUT:	X			- The x position of the ppoint clicked
		//			Y			- The y position of the ppoint clicked
		//OUTPUT:	Return true if the buttons was clicked
		//				false if not
		bool clicked(int X, int Y);
		
	private:
		//PURPOSE:	Pointer to the sound effects
		SoundEffects *mSoundEffects;
		//PURPOSE:	Buttons x position
		int mX;
		//PURPOSE:	Buttons y position
		int mY;
		//PURPOSE:	Buttons width
		int mWidth;
		//PURPOSE:	Buttons height
		int mHeight;
		//PURPOSE:	The utility object used to check collision between objects 
		CollisionDetection mCol;
};

#endif
