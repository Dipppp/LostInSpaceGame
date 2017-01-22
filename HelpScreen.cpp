#include "HelpScreen.h"

HelpScreen::HelpScreen(BITMAP *Screen, BITMAP *ImagePage, SoundEffects *SoundEffect){
	mScreen = Screen;
	mImagePage = ImagePage;
	mActive = false;
	mBackgroundWidth = SCREEN_W;
	mBackgroundHeight = SCREEN_H;
	mPage = 0;
	mBackgroundImage = create_bitmap(mBackgroundWidth,mBackgroundHeight);
	blit(mImagePage,mBackgroundImage,0,0,0,0,mBackgroundWidth,mBackgroundHeight);
	
	mNextButton = new Button(SoundEffect,635,528,165,72);
	mPreviousButton = new Button(SoundEffect,0,528,165,72);
	
}

HelpScreen::~HelpScreen(){
	delete mNextButton;
	delete mPreviousButton;
}

void HelpScreen::mainHelpSwitch(){
	mActive = true;
	mMainHelp = true;
	mPage = 0;
	blit(mImagePage,mBackgroundImage,0,0,0,0,mBackgroundWidth,mBackgroundHeight);
	rest(300);
}
void HelpScreen::quickHelpSwitch(){
	if(mActive)mActive = false;
	else mActive = true;
	blit(mImagePage,mBackgroundImage,3200,0,0,0,mBackgroundWidth,mBackgroundHeight);
	rest(300);
}

void HelpScreen::clicked(int X, int Y){
	if(mMainHelp){
		if(mNextButton->clicked(X,Y)){
			mPage++;
			if (mPage>3){
				mActive = false;
				mMainHelp = false;
				return;
			}
		}
		if(mPreviousButton->clicked(X,Y)){
			mPage--;
			if(mPage<0){
				mActive = false;
				mMainHelp = false;
				return;
			}
		}
	
		blit(mImagePage,mBackgroundImage,(mBackgroundWidth*mPage),0,0,0,mBackgroundWidth,mBackgroundHeight);
		rest(300);
	}
}

void HelpScreen::drawButton(BITMAP *Screen){
	mNextButton->draw(Screen);
	mPreviousButton->draw(Screen);
}
		
bool HelpScreen::getActive(){
	return mActive;
}
