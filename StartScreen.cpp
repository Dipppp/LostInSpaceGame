#include "StartScreen.h"

StartScreen::StartScreen(BITMAP *Screen, BITMAP *ImagePage, SoundEffects *SoundEffect){
	mScreen = Screen;
	mImagePage = ImagePage;
	mBackgroundWidth = SCREEN_W;
	mBackgroundHeight = SCREEN_H;
	mBackgroundImage = create_bitmap(mBackgroundWidth,mBackgroundHeight);
	blit(mImagePage,mBackgroundImage,0,0,0,0,mBackgroundWidth,mBackgroundHeight);
	
	mStartButton = new Button(SoundEffect,228,202,305,72);
	mStart = false;
	mHelpButton = new Button(SoundEffect,228,311,304,73);
	mHelp = false;
	mIntro=false;
	timer = 600;
}

StartScreen::~StartScreen(){
	delete mStartButton;
}

void StartScreen::update(){
	if(!mIntro){
		blit(mImagePage,mBackgroundImage,800,0,0,0,mBackgroundWidth,mBackgroundHeight);
	}else{
		blit(mImagePage,mBackgroundImage,0,0,0,0,mBackgroundWidth,mBackgroundHeight);
	}
	timer--;
	if(timer <= 0)mIntro=true;
}

void StartScreen::draw(){
	BaseInterface::draw();
	
	//for checking if button is in right position
	//mHelpButton->draw(mScreen);
}

void StartScreen::clicked(int X, int Y){
	if(mIntro){
		if(mStartButton->clicked(X,Y))mStart = true;
		if(mHelpButton->clicked(X,Y))mHelp = true;
	}
}

bool StartScreen::getStarted(){
	return mStart;
}

bool StartScreen::getHelp(){
	if(mHelp){
		mHelp = false;
		return true;
	}
	return false;
}
