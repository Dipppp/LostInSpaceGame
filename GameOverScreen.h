#ifndef GAMEOVERSCREEN_H
#define GAMEOVERSCREEN_H

#include <allegro.h>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

#include "BaseInterface.h"
#include "SoundEffects.h"

using namespace std;

//PURPOSE - To create the gameover screen for the game and uses the base interface class as a parent
class GameOverScreen : public BaseInterface {
	public:
		//PURPOSE: 	Sets the default values for the object variables
		//INPUT:	Screen 		- The pointer to game screen
		//			ImagePage 	- The pointer to bitmap of help screen images
		//			SoundEffect	- The pointer to the sound effects
		//OUTPUT:	NONE
		GameOverScreen(BITMAP *Screen, BITMAP *ImagePage, SoundEffects *SoundEffect);
		//PURPOSE:	Free memorys of the pointers
		//INPUT:	NONE
		//OUTPUT:	NONE
		~GameOverScreen();
		void gameoverSwitch(int Score);
		void update();
		void draw();
		void displayHighScore();
		//PURPOSE:	Check if any of the buttons on the page were clicked and does 
		//				coreposding action for that button
		//INPUT:	X			- The x position of the point clicked
		//			Y			- The y position of the point clicked
		//OUTPUT:	NONE
		void clicked(int X, int Y);	
		void unSetPlayAgain();
		bool getPlayAgain();	
		
	private:
		BITMAP *mAllLetters;
		BITMAP *mAllNumbers;
		BITMAP **mHighScores;
		BITMAP *mInputBox;
		BITMAP *mNameBox;
		string *mName;
		string *mScore;
		string mTempName;
		int mPositionToReplace;
		int mLetterAndNumWidth;
		int mLetterAndNumHeight;
		int mHighScoreWidth;
		int mHighScoreHeight;	
		bool mNameEnter;	
		bool mPlayAgain;	
		Button *mEnterButton;
		Button *mPlayAgainButton;
		
		void loadFromFileHighScores();
		void saveToFileHighScores();
		void loadLetterToBitmap(string Text, BITMAP *image);
		void loadNumberToBitmap(string Text, BITMAP *image, int BitmapStartX);
		string inputText(string CurrentString);
};

#endif
