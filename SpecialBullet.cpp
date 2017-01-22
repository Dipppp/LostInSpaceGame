#include "SpecialBullet.h"

SpecialBullet::SpecialBullet(BITMAP *Screen, BITMAP *Image):Bullet(Screen,Image){
	blit(mImagePage,mCurImage,0,30,0,0,mWidth,mHeight);
}

SpecialBullet::~SpecialBullet(){
}

void SpecialBullet::update(){
	if(mX > (SCREEN_W/2)-3 && mX < (SCREEN_W/2)+3){
		mXSpeed = 0;
	}
	if(mY > (SCREEN_H/2)-3 && mY < (SCREEN_H/2)+3){
		mYSpeed = 0;
	}
	
	if(mX > (SCREEN_W/2)){
		if(mY > (SCREEN_H/2)){
			Bullet::moveUpLeft();
		}else if(mY < (SCREEN_H/2)){
			Bullet::moveDownLeft();
		}else{
			Bullet::moveLeft();
		}
	}else if(mX < (SCREEN_W/2)){
		if(mY > (SCREEN_H/2)){
			Bullet::moveUpRight();
		}else if(mY < (SCREEN_H/2)){
			Bullet::moveDownRight();
		}else{
			Bullet::moveRight();
		}
	}else{
		if(mY > (SCREEN_H/2)){
			Bullet::moveUp();
		}else if(mY < (SCREEN_H/2)){
			Bullet::moveDown();
		}
	}
	
	if((mX > (SCREEN_W/2)-3 && mX < (SCREEN_W/2)+3) && (mY > (SCREEN_H/2)-3 && mY < (SCREEN_H/2)+3)) {
		mExplode = true;
	}
}

void SpecialBullet::draw(){
	Bullet::draw();
}

void SpecialBullet::fired(int StartX, int StartY){
	mX = StartX;
	mY = StartY;
	mActive = true;
	mExplode = false;
	mXSpeed=3;
	mYSpeed=3;
	
	mFrameCount	= mFrameDelay;
	mCurFrame = mFrameMax;
}

bool SpecialBullet::getExplode(){
	if(mExplode){
		mExplode = false;
		mActive = false;
		return true;
	}
	return false;
}

bool SpecialBullet::getActive(){
	return Bullet::getActive();
}
