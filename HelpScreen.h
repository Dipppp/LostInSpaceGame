#ifndef HELPSCREEN_H
#define HELPSCREEN_H

#include <allegro.h>

#include "BaseInterface.h"
#include "SoundEffects.h"

//PURPOSE - To create the help screen for the game and uses the base interface class as a parent
class HelpScreen : public BaseInterface {
	public:
		//PURPOSE: 	Sets the default values for the object variables
		//INPUT:	Screen 		- The pointer to game screen
		//			ImagePage 	- The pointer to bitmap of help screen images
		//			SoundEffect	- The pointer to the sound effects
		//OUTPUT:	NONE
		HelpScreen(BITMAP *Screen, BITMAP *ImagePage, SoundEffects *SoundEffect);
		//PURPOSE:	Free memory of buttons
		//INPUT:	NONE
		//OUTPUT:	NONE
		~HelpScreen();
		//PURPOSE:	Switch the help screen to active for the main help page
		//INPUT:	NONE
		//OUTPUT:	NONE
		void mainHelpSwitch();
		//PURPOSE:	Switch the help screen to active for the quick help page
		//INPUT:	NONE
		//OUTPUT:	NONE
		void quickHelpSwitch();
		//PURPOSE:	Check if any of the buttons on the page were clicked and does 
		//				coreposding action for that button
		//INPUT:	X			- The x position of the point clicked
		//			Y			- The y position of the point clicked
		//OUTPUT:	NONE
		void clicked(int X, int Y);
		//PURPOSE:	Used to check if button is in the right spot
		//INPUT:	NONE
		//OUTPUT:	NONE
		void drawButton(BITMAP *Screen);
		//PURPOSE:	Check if help screen is active
		//INPUT:	NONE
		//OUTPUT:	Returns mActive
		bool getActive();
	private:
		//PURPOSE:	Holds whether help screen is active
		bool mActive;
		//PURPOSE:	Holds whether main help screen is active
		bool mMainHelp;
		//PURPOSE:	Pointer to the next button
		Button *mNextButton;
		//PURPOSE:	Pointer to the previous button
		Button *mPreviousButton;
		//PURPOSE:	Current page help screen is on
		int mPage;
};

#endif
