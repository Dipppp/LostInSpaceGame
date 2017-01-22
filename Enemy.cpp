#include "Enemy.h"

Enemy::Enemy(BITMAP *Screen, BITMAP *Image, BITMAP *WeaponImage, SoundEffects *SoundEffect){
	mScreen = Screen;
	mAllImages = Image;
	mSoundEffects = SoundEffect;
	
	mWeapon = new EWeapon(Screen,WeaponImage,SoundEffect);
	mWeapon->changeReloadMax(120);
	
	//Enemy position, size, and speed 
	mX = -50;
	mY = -50;
	mWidth = 50;
	mHeight = 50;
	mXSpeed = 1;
	mYSpeed = 1;
	mActive = false;
	
	mDifficultyMeter = 0;
	
	//Player animation info
	mPreviousAni = mCurrentAni = Down;
	mCurFrame = 0;
	mNeutralFrameMax = 0;
	mUpFrameMax = 0;
	mDownFrameMax = 2;
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
	mLeftFrameRow = 0;
	mUpRightFrameRow = 0;
	mDownRightFrameRow = 0;
	mUpLeftFrameRow = 0;
	mDownLeftFrameRow = 0;
	mDestroyedFrameRow = 0;
	
	mAllEnemyWidth = 100;
	mTypeAsteroidHeight = 50;
	mTypeSnakeHeight = 200;
	mTypeStepHeight = 200;
	mTypeReverseStepHeight = 250;
	mTypeZigZagHeight = 150;
	mTypeAsteroidMiniHeight = 25;
	mTypeKamikazeRunnerHeight = 150;
	
	mImagePage = create_bitmap(mAllEnemyWidth,mTypeAsteroidHeight);
	blit(mAllImages,mImagePage,0,0,0,0,mAllEnemyWidth,mTypeAsteroidHeight);
	
	mCurImage = create_bitmap(mWidth,mHeight);
	blit(mImagePage,mCurImage,0,0,0,0,mWidth,mHeight);
}

Enemy::~Enemy(){
	destroy_bitmap(mImagePage);
	delete mWeapon;
}

void Enemy::spawn(int X, int Y, EnemyType Type){
	mX = X;
	mY = Y;
	mType = Type;
	if(X<SCREEN_W/2){
		mRightDirection = true;
	}else{
		mRightDirection = false;
	}
	mActive = true;
	mDownDirection = 0;
	mRightorLeftDir = 0;
	mUpDir = 0;
	mDestroyedTimer = 60;
	mPreviousAni = mCurrentAni = Down;
	mWidth = 50;
	mHeight = 50;
	
	switch(Type){
		case Asteroid:
			mXSpeed = 0+mDifficultyMeter;
			mYSpeed = 1+mDifficultyMeter;
			
			mCurFrame = 0;
			mDownFrameMax = 2;
			mDownFrameRow = 0;
			mDestroyedFrameMax = 0;
			mDestroyedFrameRow = 0;
			
			destroy_bitmap(mImagePage);
			mImagePage = create_bitmap(mAllEnemyWidth,mTypeAsteroidHeight);
			clear_to_color(mImagePage, makecol(255, 0, 255));
			blit(mAllImages,mImagePage,0,0,0,0,mAllEnemyWidth,mTypeAsteroidHeight);
			blit(mImagePage,mCurImage,0,0,0,0,mWidth,mHeight);
			break;
		case Snake:
			mXSpeed = 3+mDifficultyMeter;
			mYSpeed = 2+mDifficultyMeter;
			
			mWeapon->setWeaponType(EWeapon::CornerGun);
			
			mCurFrame = 0;
			mDownFrameMax = 2;
			mLeftFrameMax = 2;
			mRightFrameMax = 2;
			mDestroyedFrameMax = 2;
	
			mDownFrameRow = 0;
			mRightFrameRow = 1;
			mLeftFrameRow = 2;
			mDestroyedFrameRow = 3;
			
			destroy_bitmap(mImagePage);
			mImagePage = create_bitmap(mAllEnemyWidth,mTypeSnakeHeight);
			clear_to_color(mImagePage, makecol(255, 0, 255));
			blit(mAllImages,mImagePage,0,mTypeAsteroidHeight,0,0,mAllEnemyWidth,mTypeSnakeHeight);
			blit(mImagePage,mCurImage,0,0,0,0,mWidth,mHeight);
			break;
		case Step:
			mXSpeed = 1+mDifficultyMeter;
			mYSpeed = 1+mDifficultyMeter;
			
			mWeapon->setWeaponType(EWeapon::Missile);
			
			mCurFrame = 0;
			mDownFrameMax = 2;
			mLeftFrameMax = 2;
			mRightFrameMax = 2;
			mDestroyedFrameMax = 2;
			
			mDownFrameRow = 0;
			mRightFrameRow = 1;
			mLeftFrameRow = 2;
			mDestroyedFrameRow = 3;
			
			destroy_bitmap(mImagePage);
			mImagePage = create_bitmap(mAllEnemyWidth,mTypeStepHeight);
			clear_to_color(mImagePage, makecol(255, 0, 255));
			blit(mAllImages,mImagePage,0,mTypeAsteroidHeight+mTypeSnakeHeight,0,0,mAllEnemyWidth,mTypeStepHeight);
			blit(mImagePage,mCurImage,0,0,0,0,mWidth,mHeight);
			break;
		case ReverseStep:
			mXSpeed = 2+mDifficultyMeter;
			mYSpeed = 1+mDifficultyMeter;
			
			mWeapon->setWeaponType(EWeapon::MachineGun);
			
			mCurFrame = 0;
			mUpFrameMax = 2;
			mDownFrameMax = 2;
			mLeftFrameMax = 2;
			mRightFrameMax = 2;
			mDestroyedFrameMax = 2;
			
			mUpFrameRow = 3; 
			mDownFrameRow = 0;
			mRightFrameRow = 1;
			mLeftFrameRow = 2;
			mDestroyedFrameRow = 4;
			
			destroy_bitmap(mImagePage);
			mImagePage = create_bitmap(mAllEnemyWidth,mTypeReverseStepHeight);
			clear_to_color(mImagePage, makecol(255, 0, 255));
			blit(mAllImages,mImagePage,0,mTypeAsteroidHeight+mTypeSnakeHeight+mTypeStepHeight,0,0,mAllEnemyWidth,mTypeReverseStepHeight);
			blit(mImagePage,mCurImage,0,0,0,0,mWidth,mHeight);
			break;
		case ZigZag:
			mXSpeed = 1+mDifficultyMeter;
			mYSpeed = 1+mDifficultyMeter;
			
			mWeapon->setWeaponType(EWeapon::MachineGun);
			
			mCurFrame = 0;
			mDownRightFrameMax = 2;
			mDownLeftFrameMax = 2;
			mDestroyedFrameMax = 2;
			
			mDownRightFrameRow = 0;
			mDownLeftFrameRow = 1;
			mDestroyedFrameRow = 2;
			
			destroy_bitmap(mImagePage);
			mImagePage = create_bitmap(mAllEnemyWidth,mTypeZigZagHeight);
			clear_to_color(mImagePage, makecol(255, 0, 255));
			BITMAP *temp;
			temp = create_bitmap(mWidth,mHeight);
			//Rotating all image to correct position
			blit(mAllImages,temp,0,mTypeAsteroidHeight+mTypeSnakeHeight+mTypeStepHeight+mTypeReverseStepHeight,0,0,mWidth,mHeight);
			rotate_sprite(mImagePage,temp,0,0,itofix(224));
			rotate_sprite(mImagePage,temp,0,mHeight,itofix(32));
			blit(mAllImages,temp,mWidth,mTypeAsteroidHeight+mTypeSnakeHeight+mTypeStepHeight+mTypeReverseStepHeight,0,0,mWidth,mHeight);
			rotate_sprite(mImagePage,temp,mWidth,0,itofix(224));
			rotate_sprite(mImagePage,temp,mWidth,mHeight,itofix(32));
			blit(mAllImages,mImagePage,0,mTypeAsteroidHeight+mTypeSnakeHeight+mTypeStepHeight+mTypeReverseStepHeight+mTypeZigZagHeight-(mHeight*2),0,mHeight*2,mAllEnemyWidth,mHeight);
			destroy_bitmap(temp);
			break;
		case AsteroidMini:
			mXSpeed = 1+mDifficultyMeter;
			mYSpeed = 2+mDifficultyMeter;
			
			mCurFrame = 0;
			mDownRightFrameMax = 2;
			mDownLeftFrameMax = 2;
			mDestroyedFrameMax = 0;
			
			mDownRightFrameRow = 0;
			mDownLeftFrameRow = 0;
			mDestroyedFrameRow = 0;
			
			mWidth = 25;
			mHeight = 25;
			
			destroy_bitmap(mImagePage);
			mImagePage = create_bitmap(mAllEnemyWidth/2,mTypeAsteroidMiniHeight);
			clear_to_color(mImagePage, makecol(255, 0, 255));
			clear_to_color(mCurImage, makecol(255, 0, 255));
			stretch_blit(mAllImages,mImagePage,0,0,mAllEnemyWidth,mTypeAsteroidHeight,0,0,mAllEnemyWidth/2,mTypeAsteroidMiniHeight);
			blit(mImagePage,mCurImage,0,0,0,0,mWidth,mHeight);
			break;
		case KamikazeRunner:
			mXSpeed = 1+mDifficultyMeter;
			mYSpeed = 1+mDifficultyMeter;
			
			mCurFrame = 0;
			mDownRightFrameMax = 2;
			mDownLeftFrameMax = 2;
			mUpRightFrameMax = 2;
			mUpLeftFrameMax = 2;
			mRightFrameMax = 2;
			mLeftFrameMax = 2;
			mUpFrameMax = 2;
			mDownFrameMax = 2;
			mDestroyedFrameMax = 2;
			
			mDownRightFrameRow = 0;
			mDownLeftFrameRow = 0;
			mUpRightFrameRow = 0;
			mUpLeftFrameRow = 0;
			mRightFrameRow = 0;
			mLeftFrameRow = 0;
			mDownFrameRow = 0;
			mUpFrameRow = 0;
			mDestroyedFrameRow = 2;
			
			destroy_bitmap(mImagePage);
			mImagePage = create_bitmap(mAllEnemyWidth,mTypeKamikazeRunnerHeight);
			clear_to_color(mImagePage, makecol(255, 0, 255));
			clear_to_color(mCurImage, makecol(255, 0, 255));
			blit(mAllImages,mImagePage,0,800,0,0,mAllEnemyWidth,mTypeKamikazeRunnerHeight);
			blit(mImagePage,mCurImage,0,0,0,0,mWidth,mHeight);
			break;
		default:
			mXSpeed = 1+mDifficultyMeter;
			mYSpeed = 1+mDifficultyMeter;
	}
}

void Enemy::asteroidMiniLeftDir(){
	mRightDirection= false;
}

void Enemy::hit(){
	mXSpeed = 0;
	mYSpeed = 0;
	if(mType == AsteroidMini || mType == Asteroid)mActive = false;
	else mCurrentAni = Destroyed;
}

void Enemy::fireWeapon(int X, int Y, int Width){
	if(mType != Asteroid && mType != AsteroidMini && mCurrentAni != Destroyed && mType != KamikazeRunner){
		if(Y > mY){
			if(X < (mX+(mWidth/2)) && X+Width > (mX+(mWidth/2))){
				mWeapon->shoot(mX,mY,mWidth,mHeight);
			}
		}
	}
}

void Enemy::update(int X, int Y){
	GameObject::update();
	GameObject::animate();
	if(mCurrentAni != Destroyed){
		movement(X,Y);
	}
	mWeapon->update( X, Y);
	//Out of bounds check
	if(mY > SCREEN_H)mActive = false;
	
	//Checks if there are any live bullets left if not sets the enemy to no longer being active
	if(mPreviousAni == Destroyed && mCurrentAni == Destroyed && mDestroyedTimer <= 0 && !mWeapon->getActive())mActive = false;
	//If are active bullets still left clear the enemy picture and keeps the object to let the bullets play out
	else if(mPreviousAni == Destroyed && mCurrentAni == Destroyed && mDestroyedTimer <= 0)clear_to_color(mCurImage, makecol(255, 0, 255));
}

void Enemy::draw(){
	GameObject::draw();
	mWeapon->draw();
}

void Enemy::deactive(){
	mWeapon->deactive();
	mCurrentAni = Destroyed;
	mXSpeed = 0;
	mYSpeed = 0;
	mDifficultyMeter = 0;
	mActive = false;
}

void Enemy::setDifficulty(int DifficutlyLevel){
	mDifficultyMeter = DifficutlyLevel;
}

bool Enemy::getActive(){
	return mActive;
}

bool Enemy::checkHit(int X, int Y, int Width, int Height){
	if(mWeapon->checkHit(X,Y,Width,Height))return true;
	if (mCol.boxToBox(X, Y, Width, Height, mX, mY, mWidth, mHeight) && mCurrentAni != Destroyed){
		hit();
		return true;
	}
	false;
}

int Enemy::getX(){
	if(mCurrentAni != Destroyed)return mX;
	return -1;
}

int Enemy::getY(){
	if(mCurrentAni != Destroyed)return mY;
	return -1;
}

int Enemy::getWidth(){
	if(mCurrentAni != Destroyed)return mWidth;
	return -1;
}

int Enemy::getHeight(){
	if(mCurrentAni != Destroyed)return mHeight;
	return -1;
}

Enemy::EnemyType Enemy::getType(){
	return mType;
}

//Private Methods
void Enemy::movement(int X, int Y){
	if(mType == Asteroid){
		typeAsteroidMovement();
	}else if(mType == Snake){
		typeSnakeMovement();
	}else if(mType == Step){
		typeStepMovement();
	}else if(mType == ReverseStep){
		typeReverseStepMovement();
	}else if(mType == ZigZag){
		typeZigZagMovement();
	}else if(mType == AsteroidMini){
		typeAsteroidMiniMovement();
	}else if(mType == KamikazeRunner){
		typeKamikazeRunnerMovement(X,Y);
	}
} 

//Straight down
void Enemy::typeAsteroidMovement(){
	mCurrentAni = Down;
	GameObject::moveDown();	
}

//Snake style
void Enemy::typeSnakeMovement(){
	if(mRightDirection){
		if(mX+mWidth+mXSpeed < SCREEN_W){
			mCurrentAni = Right;
			GameObject::moveRight();
		}else{
			mDownDirection++;
			mCurrentAni = Down;
			GameObject::moveDown();
		}
	}else{
		if(mX-mXSpeed > 0){
			mCurrentAni = Left;
			GameObject::moveLeft();
		}else{
			mDownDirection++;
			mCurrentAni = Down;
			GameObject::moveDown();
		}
	}
	
	if(mDownDirection == 50){
		mDownDirection = 0;
		if(mRightDirection) mRightDirection = false;
		else mRightDirection = true;
	}
}

//Step style
void Enemy::typeStepMovement(){
	if(mDownDirection < 50){
		mCurrentAni = Down;
		GameObject::moveDown();	
		mDownDirection++;	
	}else if(mRightorLeftDir < 50){
		if (mRightDirection){
			mCurrentAni = Right;
			GameObject::moveRight();
		}else {
			mCurrentAni = Left;
			GameObject::moveLeft();
		}
		mRightorLeftDir++;	
	} 
	if(mRightorLeftDir == 50 && mDownDirection == 50){
		mRightorLeftDir = 0;
		mDownDirection = 0;
	}
	if(mX+mWidth+mXSpeed > SCREEN_W){
		mRightDirection = false;
	}else if(mX-mXSpeed < 0){
		mRightDirection = true;
	}
}

//Step with reverse style
void Enemy::typeReverseStepMovement(){
	if(mDownDirection < 50){
		mCurrentAni = Down;
		GameObject::moveDown();	
		mDownDirection++;	
	}else if(mRightorLeftDir < 50){
		if (mRightDirection){
			mCurrentAni = Right;
			GameObject::moveRight();
		}else {
			mCurrentAni = Left;
			GameObject::moveLeft();
		}
		mRightorLeftDir++;	
	}else if(mUpDir < 25){
		mCurrentAni = Up;
		GameObject::moveUp();	
		mUpDir++;
	}
	if(mUpDir == 25){
		mRightorLeftDir = 0;
		mUpDir++;
	}
	if(mRightorLeftDir == 50 && mDownDirection == 50 && mUpDir == 26){
		mRightorLeftDir = 0;
		mDownDirection = 0;
		mUpDir = 0;
	}
	if(mX+mWidth+mXSpeed > SCREEN_W){
		mRightDirection = false;
	}else if(mX-mXSpeed < 0){
		mRightDirection = true;
	}
}

//Zig Zag style
void Enemy::typeZigZagMovement(){
	if(mRightDirection){
		if(mX+mWidth+mXSpeed > SCREEN_W){
			mRightDirection = false;
		}else{
			mCurrentAni = DownRight;
			GameObject::moveDownRight();
		}
	}else{
		if(mX-mXSpeed < 0){
			mRightDirection = true;
		}else{
			mCurrentAni = DownLeft;
			GameObject::moveDownLeft();
		}
	}
}

void Enemy::typeAsteroidMiniMovement(){
	if(mRightDirection){
		if(mX+mWidth+mXSpeed > SCREEN_W){
			mRightDirection = false;
		}else{
			mCurrentAni = DownRight;
			GameObject::moveDownRight();
		}
	}else{
		if(mX-mXSpeed < 0){
			mRightDirection = true;
		}else{
			mCurrentAni = DownLeft;
			GameObject::moveDownLeft();
		}
	}
}

void Enemy::typeKamikazeRunnerMovement(int X, int Y){
	int D = (int)sqrt(((mX-X)*(mX-X))+((mY-Y)*(mY-Y)));
	//StateOne
	if(D < 150){
		int tempXSpeed = mXSpeed;
		int tempYSpeed = mYSpeed;
		mXSpeed += mXSpeed;
		mYSpeed += mYSpeed;
		mDownRightFrameRow = 1;
		mDownLeftFrameRow = 1;
		mUpRightFrameRow = 1;
		mUpLeftFrameRow = 1;
		mRightFrameRow = 1;
		mLeftFrameRow = 1;
		mDownFrameRow = 1;
		mUpFrameRow = 1;
		if(mX< X){
			if(mY<Y){
				mCurrentAni = DownRight;
				GameObject::moveDownRight();	
			}else if(mY>Y){
				mCurrentAni = UpRight;
				GameObject::moveUpRight();	
			}else{
				mCurrentAni = Right;
				GameObject::moveRight();	
			}
		}else if(mX>X){
			if(mY<Y){
				mCurrentAni = DownLeft;
				GameObject::moveDownLeft();	
			}else if(mY>Y){
				mCurrentAni = UpLeft;
				GameObject::moveUpLeft();	
			}else{
				mCurrentAni = Left;
				GameObject::moveLeft();	
			}
		}else{
			if(mY<Y){
				mCurrentAni = Down;
				GameObject::moveDown();	
			}else if(mY>Y){
				mCurrentAni = Up;
				GameObject::moveUp();	
			}
		}
		mXSpeed = tempXSpeed;
		mYSpeed = tempYSpeed;
	//StateTwo	
	}else if(D < 300){
		mDownRightFrameRow = 0;
		mDownLeftFrameRow = 0;
		mUpRightFrameRow = 0;
		mUpLeftFrameRow = 0;
		mRightFrameRow = 0;
		mLeftFrameRow = 0;
		mDownFrameRow = 0;
		mUpFrameRow = 0;
		if(mX< X){
			if(mY<Y){
				mCurrentAni = DownRight;
				GameObject::moveDownRight();	
			}else if(mY>Y){
				mCurrentAni = UpRight;
				GameObject::moveUpRight();	
			}else{
				mCurrentAni = Right;
				GameObject::moveRight();	
			}
		}else if(mX>X){
			if(mY<Y){
				mCurrentAni = DownLeft;
				GameObject::moveDownLeft();	
			}else if(mY>Y){
				mCurrentAni = UpLeft;
				GameObject::moveUpLeft();	
			}else{
				mCurrentAni = Left;
				GameObject::moveLeft();	
			}
		}else{
			if(mY<Y){
				mCurrentAni = Down;
				GameObject::moveDown();	
			}else if(mY>Y){
				mCurrentAni = Up;
				GameObject::moveUp();	
			}
		}
	//State Three
	}else{
		mCurrentAni = Down;
		GameObject::moveDown();	
	}
	
	

}


