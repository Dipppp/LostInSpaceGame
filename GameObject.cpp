#include "GameObject.h"

GameObject::GameObject(){
	
	//Default setting
	mX = 0;
	mY = 0;
	mWidth = 0;
	mHeight = 0;
	mXSpeed = 0;
	mYSpeed = 0;
	
	mPreviousAni = mCurrentAni = Neutral;
	mCurFrame = 0;
	mNeutralFrameMax = 0;
	mUpFrameMax = 0;
	mDownFrameMax = 0;
	mLeftFrameMax = 0;
	mRightFrameMax = 0;
	mUpRightFrameMax = 0;
	mDownRightFrameMax = 0;
	mUpLeftFrameMax = 0;
	mDownLeftFrameMax = 0;
	mDestroyedFrameMax = 0;
	mFrameCount	= 0;
	mFrameDelay = 30;
	
	mDownFrameRow = 0;
	mNeutralFrameRow = 0;
	mUpFrameRow = 0;
	mRightFrameRow = 0;
	mDownFrameRow = 0;
	mLeftFrameRow = 0;
	mUpRightFrameRow = 0;
	mDownRightFrameRow = 0;
	mUpLeftFrameRow = 0;
	mDownLeftFrameRow = 0;
	mDestroyedFrameRow = 0;
	
	mDestroyedTimer=60;
}

GameObject::~GameObject(){
	destroy_bitmap(mCurImage);
}

void GameObject::draw(){
	//rectfill(screen, mX, mY, mX+mWidth, mY+mHeight, makecol(255,0,0));
	draw_sprite(mScreen, mCurImage, mX, mY);
}

//Protected Method
void GameObject::update(){
	//Starts counting down Destroy timer
	if(mPreviousAni == Destroyed && mCurrentAni == Destroyed && mDestroyedTimer > 0)mDestroyedTimer--;
}

void GameObject::moveUp(){
	mY -= mYSpeed;
}

void GameObject::moveDown(){
	mY += mYSpeed;
}

void GameObject::moveRight(){
	mX += mXSpeed;
}

void GameObject::moveLeft(){
	mX -= mXSpeed;
}

void GameObject::moveUpRight(){
	mY -= mYSpeed;
	mX += mXSpeed;
}

void GameObject::moveDownRight(){
	mY += mYSpeed;
	mX += mXSpeed;
}

void GameObject::moveUpLeft(){
	mY -= mYSpeed;
	mX -= mXSpeed;
}

void GameObject::moveDownLeft(){
	mY += mYSpeed;
	mX -= mXSpeed;
}

void GameObject::animate(){
	int x = 0;
	int y = 0;
	mFrameCount++;
	if(mFrameCount > mFrameDelay || mCurrentAni != mPreviousAni){
		if(mCurrentAni == Neutral){
			if(mPreviousAni == Neutral){
				mCurFrame++;
				if(mCurFrame >= mNeutralFrameMax){
					mCurFrame = 0;
				}
			}else{
				mCurFrame = 0;
			}
			x = mCurFrame * mWidth;
			y = mHeight * mNeutralFrameRow;
		}else if(mCurrentAni == Up){
			if(mPreviousAni == Up){
				mCurFrame++;
				if(mCurFrame >= mUpFrameMax){
					mCurFrame = 0;
				}
			}else{
				mCurFrame = 0;
			}
			x = mCurFrame * mWidth;
			y = mHeight * mUpFrameRow;
		}else if(mCurrentAni == Right){
			if(mPreviousAni == Right){
				mCurFrame++;
				if(mCurFrame >= mRightFrameMax){
					mCurFrame = 0;
				}
			}else{
				mCurFrame = 0;
			}
			x = mCurFrame * mWidth;
			y = mHeight * mRightFrameRow;
		}else if(mCurrentAni == Down){
			if(mPreviousAni == Down){
				mCurFrame++;
				if(mCurFrame >= mDownFrameMax){
					mCurFrame = 0;
				}
			}else{
				mCurFrame = 0;
			}
			x = mCurFrame * mWidth;
			y = mHeight * mDownFrameRow;
		}else if(mCurrentAni == Left){
			if(mPreviousAni == Left){
				mCurFrame++;
				if(mCurFrame >= mLeftFrameMax){
					mCurFrame = 0;
				}
			}else{
				mCurFrame = 0;
			}
			x = mCurFrame * mWidth;
			y = mHeight * mLeftFrameRow;
		}else if(mCurrentAni == UpRight){
			if(mPreviousAni == UpRight){
				mCurFrame++;
				if(mCurFrame >= mUpRightFrameMax){
					mCurFrame = 0;
				}
			}else{
				mCurFrame = 0;
			}
			x = mCurFrame * mWidth;
			y = mHeight * mUpRightFrameRow;
		}else if(mCurrentAni == DownRight){
			if(mPreviousAni == DownRight){
				mCurFrame++;
				if(mCurFrame >= mDownRightFrameMax){
					mCurFrame = 0;
				}
			}else{
				mCurFrame = 0;
			}
			x = mCurFrame * mWidth;
			y = mHeight * mDownRightFrameRow;
		}else if(mCurrentAni == UpLeft){
			if(mPreviousAni == UpLeft){
				mCurFrame++;
				if(mCurFrame >= mUpLeftFrameMax){
					mCurFrame = 0;
				}
			}else{
				mCurFrame = 0;
			}
			x = mCurFrame * mWidth;
			y = mHeight * mUpLeftFrameRow;
		}else if(mCurrentAni == DownLeft){
			if(mPreviousAni == DownLeft){
				mCurFrame++;
				if(mCurFrame >= mDownLeftFrameMax){
					mCurFrame = 0;
				}
			}else{
				mCurFrame = 0;
			}
			x = mCurFrame * mWidth;
			y = mHeight * mDownLeftFrameRow;
		}else if(mCurrentAni == Destroyed){
			if(mPreviousAni == Destroyed){
				mCurFrame++;
				if(mCurFrame >= mDestroyedFrameMax){
					mCurFrame = 1;
				}
			}else{
				mCurFrame = 0;
				mSoundEffects->playSoundEffect(SoundEffects::Destroyed);
			}
			x = mCurFrame * mWidth;
			y = mHeight * mDestroyedFrameRow;
		}
		blit(mImagePage,mCurImage,x,y,0,0,mWidth,mHeight);
		mPreviousAni = mCurrentAni;
		mFrameCount = 0;	
	}
}


