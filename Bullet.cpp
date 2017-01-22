#include "Bullet.h"

Bullet::Bullet(BITMAP *Screen, BITMAP *Image){
	mScreen = Screen;
	mImagePage = Image;
	
	
	//Bullet position, size, speed, and active
	mX = -10;
	mY = -10;
	mWidth = 10;
	mHeight = 10;
	mXSpeed = 0;
	mYSpeed = 0;
	mActive = false;
	mType = MachineGunBullet;
	
	mCurImage = create_bitmap(mWidth,mHeight);
	blit(mImagePage,mCurImage,0,0,0,0,mWidth,mHeight);
	
	//Bullet animation info
	mCurFrame = 0;
	mFrameMax = 4;
	mFrameCount	= 0;
	mFrameDelay = 10;
	

	
}

Bullet::~Bullet(){
}

void Bullet::fired(int StartX, int StartY, int SpeedX, int SpeedY, BulletType Type){
	mX = StartX;
	mY = StartY;
	mXSpeed = SpeedX;
	mYSpeed = SpeedY;
	mActive = true;
	mType = Type;
	
	mFrameCount	= mFrameDelay;
	mCurFrame = mFrameMax;
}

void Bullet::hit(){
	mX = 0;
	mY = 0;
	mXSpeed = 0;
	mYSpeed = 0;
	mActive = false;
}

void Bullet::update(){
	animate();
	GameObject::moveUp();
	if(mYSpeed<0){
		mYSpeed *= -1;
		GameObject::moveLeft();
		mYSpeed *= -1;
	}else{
		GameObject::moveRight();
	}
	
	//Bullet off screen checks
	if(mX + mWidth < 0)hit();
	if(mX > SCREEN_W)hit();
	if(mY + mHeight < 0)hit();
	if(mY > SCREEN_H)hit();
}

bool Bullet::getActive(){
	return mActive;
}

int Bullet::getX(){
	return mX;
}

int Bullet::getY(){
	return mY;
}

int Bullet::getWidth(){
	return mWidth;
}

int Bullet::getHeight(){
	return mHeight;
}

//Private Method
void Bullet::animate(){
	int x = 0;
	int y = 0;
	mFrameCount++;
	if(mFrameCount > mFrameDelay){
		mCurFrame++;
		if(mCurFrame >= mFrameMax){
			mCurFrame = 0;
		}
		if(mType == MachineGunBullet){
			x = mCurFrame * mWidth;
			y = 0;
		}else if(mType == LaserBeam){
			x = mCurFrame * mWidth;
			y = mHeight;
		}else if(mType == CornerGunBullet){
			x = mCurFrame * mWidth;
			y = mHeight*2;
		}
		blit(mImagePage,mCurImage,x,y,0,0,mWidth,mHeight);
		mFrameCount = 0;
	}
}
