#include "Button.h"

Button::Button(SoundEffects *SoundEffect, int X, int Y, int Width, int Height){
	mSoundEffects = SoundEffect;
	mX = X;
	mY = Y;
	mWidth = Width;
	mHeight = Height;
}

Button::~Button(){
}

void Button::draw(BITMAP *Screen){
	rectfill(Screen, mX, mY, mX+mWidth, mY+mHeight, makecol(0,255,0));
}

bool Button::clicked(int X, int Y){
	if(mCol.pointToBox(X,Y,mX,mY,mWidth,mHeight)){
		mSoundEffects->playSoundEffect(SoundEffects::Click);
		return true;
	}
	return false;
}
