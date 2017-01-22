#ifndef STARTSCREEN_H
#define STARTSCREEN_H

#include <allegro.h>

#include "BaseInterface.h"
#include "SoundEffects.h"

//PURPOSE - To create the start screen for the game and uses the base interface class as a parent
class StartScreen : public BaseInterface {
	public:
		//PURPOSE: 	Sets the default values for the object variables
		//INPUT:	Screen 		- The pointer to game screen
		//			ImagePage 		- The pointer to bitmap of start screen images
		//			SoundEffect	- The pointer to the sound effects
		//OUTPUT:	NONE
		StartScreen(BITMAP *Screen, BITMAP *ImagePage,SoundEffects *SoundEffect);
		//PURPOSE:	Free memory of the buttons
		//INPUT:	NONE
		//OUTPUT:	NONE
		~StartScreen();
		//PURPOSE:	Switch between intro and start screen
		//INPUT:	NONE
		//OUTPUT:	NONE
		void update();
		//PURPOSE:	Calls parent class draw method
		//INPUT:	NONE
		//OUTPUT:	NONE
		void draw();
		//PURPOSE:	Check if any of the buttons on the page were clicked and does 
		//				coreposding action for that button
		//INPUT:	X			- The x position of the point clicked
		//			Y			- The y position of the point clicked
		//OUTPUT:	NONE
		void clicked(int X, int Y);
		//PURPOSE:	Returns whether the games start was actived
		//INPUT:	NONE
		//OUTPUT:	Return mStart
		bool getStarted();
		//PURPOSE:	Returns whether the help button was actived
		//INPUT:	NONE
		//OUTPUT:	Return mHelp
		bool getHelp();
		
	private:
		//PURPOSE:	Pointer to the start button
		Button *mHelpButton;
		//PURPOSE:	Pointer to the start button
		Button *mStartButton;
		//PURPOSE:	Holds whether the start button was clicked
		bool mStart;
		//PURPOSE:	Holds whether the help button was clicked
		bool mHelp;
		//PURPOSE:	Holds whether the intro has passed
		bool mIntro;
		//PURPOSE:	Time before start screen is up
		int timer;
		
};

#endif
