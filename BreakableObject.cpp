#include "BreakableObject.h"

BreakableObject::BreakableObject(BITMAP *Screen, BITMAP *Image, SoundEffects *SoundEffect){
	mScreen = Screen;
	mAllImagePage = Image;
	mSoundEffects = SoundEffect;
	
	//Breakable Object position, size, and speed 
	mX = 0;
	mY = 0;
	mWidth = 20;
	mHeight = 20;
	mXSpeed = 0;
	mYSpeed = 0;
	mActive = false;
	
	//Breakable Object animation info
	mPreviousAni = mCurrentAni = Neutral;
	mCurFrame = 0;
	mDownFrameMax = 2;
	mFrameCount	= 0;
	mFrameDelay = 30;
	mDownFrameRow = 0;
	
	//Gets individual breakableobject from all object image and scale image from 60 to 40 pixels
	mImagePage = create_bitmap((mWidth*mDownFrameMax),mHeight*2);
	stretch_blit(mAllImagePage,mImagePage,0,0,(mWidth+10)*mDownFrameMax,(mHeight+10)*2,0,0,mWidth*2,mHeight*2);
	//blit(mAllImagePage,mImagePage,0,0,0,0,(mWidth*mDownFrameMax),mHeight*2);
	
	mCurImage = create_bitmap(mWidth,mHeight);
	blit(mImagePage,mCurImage,0,0,0,0,mWidth,mHeight);
}

BreakableObject::~BreakableObject(){
	destroy_bitmap(mAllImagePage);
}

void BreakableObject::spawn(int X, int Y, BObjectType Type){
	mX = X;
	mY = Y;
	mXSpeed = 0;
	mYSpeed = 1;
	mType = Type;
	mActive = true;
}

void BreakableObject::hit(){
	mX = -20;
	mY = -20;
	mXSpeed = 0;
	mYSpeed = 0;
	mCurrentAni = Destroyed;
}

void BreakableObject::update(){
	GameObject::update();
	animate();
	if(mCurrentAni != Destroyed){
		movement();
	}
	
	//Out of bounds check
	if(mY > SCREEN_H)mActive = false;
	if(mPreviousAni == Destroyed && mCurrentAni == Destroyed && mDestroyedTimer <= 0)mActive = false;
}

bool BreakableObject::getActive(){
	return mActive;
}

BreakableObject::BObjectType BreakableObject::getType(){
	return mType;
}

int BreakableObject::getX(){
	return mX;
}

int BreakableObject::getY(){
	return mY;
}

int BreakableObject::getWidth(){
	return mWidth;
}

int BreakableObject::getHeight(){
	return mHeight;
}

//Private Methods
void BreakableObject::movement(){
	mCurrentAni = Down;
	GameObject::moveDown();
}

void BreakableObject::animate(){
	int y = 0;
	int tempHeight = (mHeight+10) * 2;
	if(mType == Life){
	}else if(mType == MGPowerUp){
		y = tempHeight;
	}else if(mType == LPowerUp){
		y = tempHeight * 3;
	}else if(mType == CGPowerUp){
		y = tempHeight * 2;
	}else if(mType == SPowerUp){
		y = tempHeight * 4;
	}
	//blit(mAllImagePage,mImagePage,0,y,0,0,(mWidth*mDownFrameMax),mHeight*2);
	stretch_blit(mAllImagePage,mImagePage,0,y,(mWidth+10)*mDownFrameMax,(mHeight+10)*2,0,0,mWidth*2,mHeight*2);
	
	GameObject::animate();
}
