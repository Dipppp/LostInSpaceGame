#ifndef IMAGES_H
#define IMAGES_H

#include <allegro.h>


//PURPOSE - The Class is for loading all the images the game uses and puts them
//				in bitmap pointers
class Images {
	public:
		//PURPOSE:	Loads all the game image to there respective bitmaps
		//INPUT:	Data			- The pointer to game data
		//OUTPUT:	NONE
		Images();
		//PURPOSE:	Release all the bitmaps
		//INPUT:	NONE
		//OUTPUT:	NONE
		~Images();
		//PURPOSE:	Returns the bitmap pointer to the player's images
		//INPUT:	NONE
		//OUTPUT:	Return mPlayerImg
		BITMAP *getPlayerImage();
		//PURPOSE:	Returns the bitmap pointer to the player's weapon's images
		//INPUT:	NONE
		//OUTPUT:	Return mPlayerWeaponImg
		BITMAP *getPlayerWeaponImage();
		//PURPOSE:	Returns the bitmap pointer to the all enemy types images
		//INPUT:	NONE
		//OUTPUT:	Return mEnemyImg
		BITMAP *getEnemyImage();
		//PURPOSE:	Returns the bitmap pointer to the enemy's weapon's images
		//INPUT:	NONE
		//OUTPUT:	Return mPlayerWeaponImg
		BITMAP *getEnemyWeaponImage();
		//PURPOSE:	Returns the bitmap pointer to the all breakable objects images
		//INPUT:	NONE
		//OUTPUT:	Return mAllBreakableObjImg
		BITMAP *getAllBreakableObjImage();
		//PURPOSE:	Returns the bitmap pointer to the game screen's images
		//INPUT:	NONE
		//OUTPUT:	Return mGameScreenImg
		BITMAP *getGameScreenImages();
		//PURPOSE:	Returns the bitmap pointer to the start screen's images
		//INPUT:	NONE
		//OUTPUT:	Return mStartScreenImg
		BITMAP *getStartScreenImage();
		//PURPOSE:	Returns the bitmap pointer to the help screen's images
		//INPUT:	NONE
		//OUTPUT:	Return mHelpScreenImg
		BITMAP *getHelpScreenImage();
		//PURPOSE:	Returns the bitmap pointer to the gameover screen's images
		//INPUT:	NONE
		//OUTPUT:	Return mGameOverScreenImg
		BITMAP *getGameOverScreenImage();
	private:
		//PURPOSE:	Pointer the to the player's loaded images
		BITMAP *mPlayerImg;
		//PURPOSE:	Pointer the to the player's weapons loaded images
		BITMAP *mPlayerWeaponImg;
		//PURPOSE:	Pointer the to the enemies loaded images
		BITMAP *mEnemyImg;
		//PURPOSE:	Pointer the to the enemy's weapons loaded images
		BITMAP *mEnemyWeaponImg;
		//PURPOSE:	Pointer the to the breakable objects loaded images
		BITMAP *mAllBreakableObjImg;
		//PURPOSE:	Pointer the to the game screen loaded images
		BITMAP *mGameScreenImgs;
		//PURPOSE:	Pointer the to the start screen loaded images
		BITMAP *mStartScreenImg;
		//PURPOSE:	Pointer the to the help screen loaded images
		BITMAP *mHelpScreenImg;
		//PURPOSE:	Pointer the to the gameover screen loaded images
		BITMAP *mGameOverScreenImg;
};

#endif
