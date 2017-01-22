#ifndef GAMESCREEN_H
#define GAMESCREEN_H

#include <allegro.h>

#include "BaseInterface.h"

//PURPOSE - To create the game screen for the game and uses the base interface class as a parent
class GameScreen : public BaseInterface {
	public:
		//PURPOSE: 	Sets the default values for the object variables
		//INPUT:	Screen 		- The pointer to game screen
		//			ImagePage 	- The pointer to bitmap of game screen images
		//OUTPUT:	NONE
		GameScreen(BITMAP *Screen, BITMAP *ImagePage);
		//PURPOSE:	Free memory of the bitmaps 
		//INPUT:	NONE
		//OUTPUT:	NONE
		~GameScreen();
		//PURPOSE:	Updates the animation
		//INPUT:	NONE
		//OUTPUT:	NONE
		void update();
		//PURPOSE:	Call parent class draw method and call draw score method and 
		//				draw life image depending on the value in mNumLife
		//INPUT:	NONE
		//OUTPUT:	NONE
		void draw();
		//PURPOSE:	Increase the value in mNumLife if it is not greater than three
		//INPUT:	NONE
		//OUTPUT:	NONE
		void increaseNumberLifes();
		//PURPOSE:	Decrease the value in mNumLife if it is not less than zero
		//INPUT:	NONE
		//OUTPUT:	NONE
		void decreaseNumberLifes();
		//PURPOSE:	Adds the value given to mScore as long as value is not negative
		//INPUT:	Number		- Value to add to mScore
		//OUTPUT:	NONE
		void increaseScoreBy(int Number);
		//PURPOSE:	Set the number of special weapon charges
		//INPUT:	Number		- Value to set
		//OUTPUT:	NONE
		void setNumSWScharge(int Number);
		//PURPOSE:	Resets game screen
		//INPUT:	NONE
		//OUTPUT:	NONE
		void reset();
		//PURPOSE:	Return if gameover
		//INPUT:	NONE
		//OUTPUT:	Return true if mNumLife equal zero
		//				false if not
		bool gameover();
		//PURPOSE:	Return's the score
		//INPUT:	NONE
		//OUTPUT:	Return mScore
		int getScore();
		
	private:
		//PURPOSE:	Holds the number images from zero to nine
		BITMAP *mNumberImage;
		//PURPOSE:	Holds the image of the current score
		BITMAP *mScoreImage;
		//PURPOSE:	Holds the image number of Lifes
		BITMAP *mLifeImage;
		//PURPOSE:	Holds the image number of special weapon
		BITMAP *mSWImage;
		//PURPOSE:	Hold the number of lifes the player has
		int mNumLife;
		//PURPOSE:	The width of the life image
		int mLifeWidth;
		//PURPOSE:	The height of the life image
		int mLifeHeight;
		//PURPOSE:	Hold the number of special weapon charges
		int mNumSWcharge;
		//PURPOSE:	The width of the life image
		int mSWWidth;
		//PURPOSE:	The height of the life image
		int mSWHeight;
		//PURPOSE:	Hold the players current score
		int mScore;
		//PURPOSE:	Hold the width of the individual number in the numbers image 
		int mIndividualNumberWidth;
		//PURPOSE:	Hold the height of the individual number in the numbers image
		int mIndividualNumberHeight;
		//PURPOSE:	Hold the number of digits in the score value
		int mCurrentDigitNumber;
		//PURPOSE:	Hold the current frame the background image is in
		int mCurFrame;
		//PURPOSE:	Hold the max number of frame for the background image
		int mFrameMax;
		//PURPOSE:	Use for the animation of the background
		int mFrameCount, mFrameDelay;
		
		//PURPOSE:	Calculate the number of digits in the score and extracts each individual digit
		//				and get the corresponding number image and combines them together in 
		//				mScoreImage to display
		//INPUT:	NONE
		//OUTPUT:	NONE
		void drawScore();
		//PURPOSE:	Animates the background image
		//INPUT:	NONE
		//OUTPUT:	NONE
		void animate();
};

#endif
