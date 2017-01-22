#include "Player.h"

Player::Player(BITMAP *Screen, BITMAP *Image, BITMAP *WeaponImage, SoundEffects *SoundEffect){
	mScreen = Screen;
	mImagePage = Image;
	mSoundEffects = SoundEffect;
	
	//Player position, size, and speed 
	mX = 100;
	mY = 500;
	mWidth = 50;
	mHeight = 50;
	mXSpeed = 3;
	mYSpeed = 3;
	
	//Player animation info
	mPreviousAni = mCurrentAni = Neutral;
	mCurFrame = 0;
	mNeutralFrameMax = 2;
	mUpFrameMax = 2;
	mDownFrameMax = 2;
	mLeftFrameMax = 2;
	mRightFrameMax = 2;
	mUpRightFrameMax = 2;
	mDownRightFrameMax = 2;
	mUpLeftFrameMax = 2;
	mDownLeftFrameMax = 2;
	mDestroyedFrameMax = 2;
	mFrameCount	= 0;
	mFrameDelay = 30;
	mNeutralFrameRow = 0;
	mUpFrameRow = 1;
	mRightFrameRow = 2;
	mDownFrameRow = 3;
	mLeftFrameRow = 4;
	mUpRightFrameRow = 5;
	mDownRightFrameRow = 6;
	mUpLeftFrameRow = 7;
	mDownLeftFrameRow = 8;
	mDestroyedFrameRow = 9;
	
	mDestroyedTimer = 60;
	mFlickerTimer = 0;
	mReviveSavedTimer= 0;
	
	mCurImage = create_bitmap(mWidth,mHeight);
	blit(mImagePage,mCurImage,0,0,0,0,mWidth,mHeight);

	mWeapon = new Weapon(Screen,WeaponImage,SoundEffect);
	
}

Player::~Player(){
	delete mWeapon;
}

void Player::moveUp(){
	if(mY-mYSpeed > 0 && mCurrentAni != Destroyed){
		mCurrentAni = Up;
		GameObject::moveUp();
	}
}

void Player::moveDown(){
	if((mY+mHeight)+mYSpeed < SCREEN_H && mCurrentAni != Destroyed){
		mCurrentAni = Down;
		GameObject::moveDown();
	}
}

void Player::moveRight(){
	if((mX+mWidth)+mXSpeed < SCREEN_W && mCurrentAni != Destroyed){
		mCurrentAni = Right;
		GameObject::moveRight();
	}
}

void Player::moveLeft(){
	if(mX+mXSpeed > 0 && mCurrentAni != Destroyed){
		mCurrentAni = Left;
		GameObject::moveLeft();
	}
}

void Player::moveUpRight(){
	if(mY-mYSpeed > 0 && (mX+mWidth)+mXSpeed < SCREEN_W && mCurrentAni != Destroyed){
		mCurrentAni = UpRight;
		GameObject::moveUpRight();
	}
}

void Player::moveDownRight(){
	if((mY+mHeight)+mYSpeed < SCREEN_H && (mX+mWidth)+mXSpeed < SCREEN_W && mCurrentAni != Destroyed){
		mCurrentAni = DownRight;
		GameObject::moveDownRight();
	}
}

void Player::moveUpLeft(){
	if(mY-mYSpeed > 0 && mX+mXSpeed > 0 && mCurrentAni != Destroyed){
		mCurrentAni = UpLeft;
		GameObject::moveUpLeft();
	}
}

void Player::moveDownLeft(){
	if((mY+mHeight)+mYSpeed < SCREEN_H && mX+mXSpeed > 0 && mCurrentAni != Destroyed){
		mCurrentAni = DownLeft;
		GameObject::moveDownLeft();
	}
}

void Player::moveNeutral(){
	if(mCurrentAni != Destroyed)mCurrentAni = Neutral;
}

void Player::destroyed(){
	mCurrentAni = Destroyed;
}

void Player::fireWeapon(){
	if(mCurrentAni != Destroyed)mWeapon->shoot(mX, mY, mWidth, mHeight);
}

void Player::fireSpecialWeapon(){
	if(mCurrentAni != Destroyed ){
		mWeapon->shootSpecial(mX, mY);
	}
}

void Player::weaponUpgrade(Weapon::WeaponType Type){
	mWeapon->changeWeaponType(Type);
}

void Player::update(){
	GameObject::update();
	if(mPreviousAni == Destroyed && mCurrentAni == Destroyed && mDestroyedTimer <= 0){
		mCurrentAni = Neutral;
		mDestroyedTimer = 60;
		mReviveSavedTimer= 240;
	}
	reviveCounter();
	GameObject::animate();
	mWeapon->update();
	
}

void Player::draw(){
	GameObject::draw();
	mWeapon->draw();
}

void Player::reset(){
	mX = 100;
	mY = 500;
	mWeapon->deactive();
	mPreviousAni = mCurrentAni = Neutral;
	blit(mImagePage,mCurImage,0,0,0,0,mWidth,mHeight);
	mDestroyedTimer = 60;
	mReviveSavedTimer= 0;
}

void Player::increaseSpecialWeapon(){
	mWeapon->increaseSpecialWeapon();
}

int Player::getX(){
	if(mCurrentAni != Destroyed && mReviveSavedTimer == 0)return mX;
	return -1;
}

int Player::getY(){
	if(mCurrentAni != Destroyed && mReviveSavedTimer == 0)return mY;
	return -1;
}

int Player::getWidth(){
	if(mCurrentAni != Destroyed && mReviveSavedTimer == 0)return mWidth;
	return -1;
}

int Player::getHeight(){
	if(mCurrentAni != Destroyed && mReviveSavedTimer == 0)return mHeight;
	return -1;
}

int Player::getSpecialWeaponCharges(){
	return mWeapon->getSpecialCharge();
}

bool Player::checkHitWithBullet(int X, int Y, int Width, int Height){
	return mWeapon->checkHit(X,Y,Width,Height);
}

bool Player::specialWeaponExplode(){
	return mWeapon->getSpecialExplosion();
}

//Private Methods
void Player::reviveCounter(){
	mFlickerTimer++;
	if(mReviveSavedTimer > 0){
		mReviveSavedTimer--;
		if(mFlickerTimer > 2){
			mFlickerTimer = 0;
			clear_to_color(mCurImage, makecol(255, 0, 255));
		}
	}
	
}
