#include "EBullet.h"
EBullet::EBullet(BITMAP *Screen, BITMAP *Image):Bullet(Screen,Image){
}

EBullet::~EBullet(){
}

void EBullet::update(int X, int Y){
	animate();
	if(mY <  Y){
		if (mX< X){
			mCurrentAni = DownRight;
			Bullet::moveDownRight();
		}else if(mX>X){
			mCurrentAni = DownLeft;
			Bullet::moveDownLeft();
		}else{
			mCurrentAni = Down;
			Bullet::moveDown();
		}
	}else{
		mCurrentAni = Down;
		Bullet::moveDown();
	}
	
	//Bullet off screen checks
	if(mX + mWidth < 0)hit();
	if(mX > SCREEN_W)hit();
	if(mY + mHeight < 0)hit();
	if(mY > SCREEN_H)hit();
}

void EBullet::fired(int StartX, int StartY, int SpeedX, int SpeedY){
	Bullet::fired(StartX, StartY, SpeedX, SpeedY, Bullet::NonStandardType);
}

//Private Method
void EBullet::animate(){
	int x = 0;
	int y = 0;
	mFrameCount++;
	if(mFrameCount > mFrameDelay){
		mCurFrame++;
		if(mCurFrame >= mFrameMax){
			mCurFrame = 0;
		}
		x = mCurFrame * mWidth;
		y = mHeight*3;
		BITMAP *temp;
		temp = create_bitmap(mWidth,mHeight);
		blit(mImagePage,temp,x,y,0,0,mWidth,mHeight);
		clear_to_color(mCurImage, makecol(255, 0, 255));
		if(mCurrentAni == DownRight)rotate_sprite(mCurImage,temp,0,0,itofix(224));
		else if(mCurrentAni == DownLeft)rotate_sprite(mCurImage,temp,0,0,itofix(32));
		else blit(mImagePage,mCurImage,x,y,0,0,mWidth,mHeight);
		
		mFrameCount = 0;
	}
}

