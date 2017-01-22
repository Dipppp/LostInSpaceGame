#include "GameScreen.h"

GameScreen::GameScreen(BITMAP *Screen, BITMAP *ImagePage){
	mScreen = Screen;
	mImagePage = ImagePage;
	
	mBackgroundWidth = SCREEN_W;
	mBackgroundHeight = SCREEN_H;
	
	mBackgroundImage = create_bitmap(mBackgroundWidth,mBackgroundHeight);
	blit(mImagePage,mBackgroundImage,0,0,0,0,mBackgroundWidth,mBackgroundHeight);
	
	mCurFrame = 0;
	mFrameMax = 2;
	mFrameCount = 0;
	mFrameDelay = 60;
	
	
	mNumLife = 3;
	mLifeWidth = 22;
	mLifeHeight = 25;
	mLifeImage = create_bitmap(mLifeWidth,mLifeHeight);
	blit(mImagePage,mLifeImage,0,613,0,0,mLifeWidth,mLifeHeight);
	
	mNumSWcharge = 0;
	mSWWidth = 23;
	mSWHeight = 25;
	mSWImage = create_bitmap(mSWWidth,mSWHeight);
	blit(mImagePage,mSWImage,21,613,0,0,mSWWidth,mSWHeight);
	
	mScore = 0;
	mCurrentDigitNumber = 1;
	mIndividualNumberWidth = 10;
	mIndividualNumberHeight = 13;
	mScoreImage = create_bitmap(mIndividualNumberWidth,mIndividualNumberHeight);
	
	mNumberImage = create_bitmap(mIndividualNumberWidth*10,mIndividualNumberHeight);
	blit(mImagePage,mNumberImage,0,600,0,0,mIndividualNumberWidth*10,mIndividualNumberHeight);
}

GameScreen::~GameScreen(){
	destroy_bitmap(mNumberImage);
	destroy_bitmap(mScoreImage);
	destroy_bitmap(mLifeImage);
	destroy_bitmap(mSWImage);
}

void GameScreen::update(){
	animate();
}

void GameScreen::draw(){
	BaseInterface::draw();
	
	//Draws life images
	for(int i = 0; i < mNumLife; i++){
		draw_sprite(mScreen, mLifeImage, 600+(mLifeWidth*i), 13);
	}
	//Draws SW images
	for(int i = 0; i < mNumSWcharge; i++){
		draw_sprite(mScreen, mSWImage, 600+(mSWWidth*i), 38);
	}
	drawScore();
}

void GameScreen::increaseNumberLifes(){
	if(mNumLife < 3)mNumLife++;
}

void GameScreen::decreaseNumberLifes(){
	if(mNumLife > 0)mNumLife--;
}

void GameScreen::increaseScoreBy(int Number){
	if(Number >0)mScore += Number;
}

void GameScreen::setNumSWScharge(int Number){
	mNumSWcharge = Number;
}

void GameScreen::reset(){
	mScore = 0;
	mNumLife = 3;
	mCurrentDigitNumber = 1;
	destroy_bitmap(mScoreImage);
	mScoreImage = create_bitmap(mIndividualNumberWidth,mIndividualNumberHeight);
}

bool GameScreen::gameover(){
	return mNumLife == 0;
}

int GameScreen::getScore(){
	return mScore;
}

//Private Methods
void GameScreen::drawScore(){
	int temp = mScore;
	int numDigit = 0;
	int digit = 0;
	int x, y, x2; 
	if(mScore > 0){
		while(temp !=0){
			temp /= 10;
			numDigit++;
		}
		if(mCurrentDigitNumber < numDigit){
			mCurrentDigitNumber = numDigit;
			destroy_bitmap(mScoreImage);
			mScoreImage = create_bitmap(mIndividualNumberWidth*mCurrentDigitNumber,mIndividualNumberHeight);
		}
		temp = mScore;
		while(temp !=0){
			digit = temp % 10;
			temp /= 10;
			x = mIndividualNumberWidth*digit;
			x2 = mIndividualNumberWidth*(numDigit-1);
			numDigit -= 1;
			blit(mNumberImage,mScoreImage,x,0,x2,0,mIndividualNumberWidth,mIndividualNumberHeight);
			//textprintf_ex(mScreen, font, 300, 20*numDigit, makecol(255,255,255), -1, "x2- %2d x- %2d", x2, x);	
		}
		
	}else{
		blit(mNumberImage,mScoreImage,0,0,0,0,mIndividualNumberWidth,mIndividualNumberHeight);
	}
	draw_sprite(mScreen, mScoreImage, 600, 0);
}

void GameScreen::animate(){
	int x = mBackgroundWidth;
	mFrameCount++;
	if(mFrameCount > mFrameDelay){
		mCurFrame++;
		if(mCurFrame >= mFrameMax){
			mCurFrame = 0;
		}
		x = mBackgroundWidth * mCurFrame;
		blit(mImagePage,mBackgroundImage,x,0,0,0,mBackgroundWidth,mBackgroundHeight);
		mFrameCount = 0;
	}
}
