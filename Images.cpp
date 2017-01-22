#include "Images.h"

Images::Images(){
	mPlayerImg = load_bitmap("Images/Player.bmp", NULL);
	mPlayerWeaponImg = load_bitmap("Images/PlayerBullet.bmp", NULL);
	mEnemyImg = load_bitmap("Images/Enemys.bmp", NULL);
	mEnemyWeaponImg = load_bitmap("Images/EnemyBullet.bmp", NULL);
	mAllBreakableObjImg = load_bitmap("Images/AllBreakableObj.bmp", NULL);
	mGameScreenImgs = load_bitmap("Images/GameScreenImages.bmp", NULL);
	mStartScreenImg = load_bitmap("Images/StartScreen.bmp", NULL);
	mHelpScreenImg = load_bitmap("Images/HelpScreenImages.bmp", NULL);
	mGameOverScreenImg = load_bitmap("Images/GameOverScreenImages.bmp", NULL);
}

Images::~Images(){
	destroy_bitmap(mPlayerImg);
	destroy_bitmap(mPlayerWeaponImg);
	destroy_bitmap(mEnemyImg);
	destroy_bitmap(mEnemyWeaponImg);
	destroy_bitmap(mAllBreakableObjImg);
	destroy_bitmap(mGameScreenImgs);
	destroy_bitmap(mStartScreenImg);
	destroy_bitmap(mHelpScreenImg);
	destroy_bitmap(mGameOverScreenImg);
}

BITMAP *Images::getPlayerImage(){
	return mPlayerImg;
}

BITMAP *Images::getPlayerWeaponImage(){
	return mPlayerWeaponImg;
}

BITMAP *Images::getEnemyImage(){
	return mEnemyImg;
}

BITMAP *Images::getEnemyWeaponImage(){
	return mEnemyWeaponImg;
}

BITMAP *Images::getAllBreakableObjImage(){
	return mAllBreakableObjImg;
}

BITMAP *Images::getGameScreenImages(){
	return mGameScreenImgs;
}

BITMAP *Images::getStartScreenImage(){
	return mStartScreenImg;
}

BITMAP *Images::getHelpScreenImage(){
	return mHelpScreenImg;
}

BITMAP *Images::getGameOverScreenImage(){
	return mGameOverScreenImg;
}
