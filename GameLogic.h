#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include <allegro.h>

#include "SoundEffects.h"
#include "Music.h"
//#include "Images.h"
#include "Player.h"
#include "BreakableObject.h"
#include "EnemyController.h"
#include "GameScreen.h"
#include "HelpScreen.h"
#include "StartScreen.h"
#include "GameOverScreen.h"

//PURPOSE - Controls the whole game logic
class GameLogic {
	public:
		//PURPOSE:	Set all the default values for the game
		//INPUT:	NONE
		//OUTPUT:	NONE
		GameLogic();
		//PURPOSE:	Release all the pointers for game objects
		//INPUT:	NONE
		//OUTPUT:	NONE
		~GameLogic();
		//PURPOSE:	Updates all the game object and calls the user input method
		//				and collsion methods
		//INPUT:	NONE
		//OUTPUT:	NONE
		void update();
		//PURPOSE:	Draws all the game object on to the screen 
		//INPUT:	NONE
		//OUTPUT:	NONE
		void draw();
		
	private:
		//PURPOSE:	The bitmap the hold the game screen displayed to the user
		BITMAP *mBuffer;
		//PURPOSE:	Pointer to the object that loads all the game images
		//Images *mImages;
		//PURPOSE:	Pointer to the game data
		DATAFILE *mData; 
		//PURPOSE:	Pointer to the object that loads all the game soundeffects
		SoundEffects *mSoundEffects;
		//PURPOSE:	Pointer to the object that loads all the game music
		Music *mMusic;
		//PURPOSE:	Pointer to the player object	
		Player *mPlayer;
		//PURPOSE:	Pointer to breakable objects array
		BreakableObject **mBreakableObj;
		//PURPOSE:	Pointer to the enemy controller object
		EnemyController *mEnemys;
		//PURPOSE:	Pointer to the game screen object
		GameScreen *mGameScreen;
		//PURPOSE:	Pointer to the help screen object
		HelpScreen *mHelpScreen;
		//PURPOSE:	Pointer to the start screen object
		StartScreen *mStartScreen;
		//PURPOSE:	Pointer to the gameover screen object
		GameOverScreen *mGameOverScreen;
		
		//PURPOSE:	Does the corresponding actions for the user inputs for the player object
		//INPUT:	NONE
		//OUTPUT:	NONE
		void playerShipInputs();
		//PURPOSE:	Does the corresponding actions for the user inputs
		//INPUT:	NONE
		//OUTPUT:	NONE
		void userInputs();
		//PURPOSE:	Spawns ship upgrades at random
		//INPUT:	NONE
		//OUTPUT:	NONE
		void spawnShipUpgrades();
		//PURPOSE:	Checks if a ship upgrade was hit by the players bullets 
		//INPUT:	NONE
		//OUTPUT:	NONE
		void checkShipUpgradesHit();
		//PURPOSE:	Checks if a enemy was hit by the players bullets 
		//INPUT:	NONE
		//OUTPUT:	NONE
		void checkPlayerBulletHitEnemy();
		//PURPOSE:	Checks if a enemy or enemy bullet hit the player
		//INPUT:	NONE
		//OUTPUT:	NONE
		void checkEnemyBulletOrEnemyHitPlayer();
		//PURPOSE:	Checks if a the special weapon explosion happened and wipes other all the 
		//				enemies if it did
		//INPUT:	NONE
		//OUTPUT:	NONE
		void checkPlayerSpecialWeapon();
};

#endif
