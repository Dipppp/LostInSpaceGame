#include "Weapon.h"

Weapon::Weapon(BITMAP *Screen, BITMAP *Image, SoundEffects *SoundEffect){
	mScreen = Screen;
	mImagePage = Image;
	mSoundEffects = SoundEffect;
	
	mReloadTime = 0;
	mMachineAndCornerReloadTimeMax = 60;
	mLaserReloadTimeMax = 3;
	mLaserBulletCount = 0;
	mLaserChargeTime = 0;
	
	mWeaponLevel = 1;
	mWeaponType = MachineGun;
	
	mBulletSpeed = 3;
	mLaserSpeed = 2;
	mBulletDir = 1;
	mTotalBullets = 60;
	mBullets = new Bullet*[mTotalBullets];
	for(int i = 0; i < mTotalBullets; i++){
		mBullets[i] = new Bullet(Screen, Image);
	}
	
	mSpecialCharge = 3;
	mSpecialBulletDelay = 0;
	mSpecialBulletDelayMax = 15;
	mTotalSpecialBullets = 3;
	mSpecialBullets = new SpecialBullet*[mTotalSpecialBullets];
	for(int i = 0; i < mTotalSpecialBullets; i++){
		mSpecialBullets[i] = new SpecialBullet(Screen, Image);
	}
}

Weapon::~Weapon(){
	for(int i = 0; i < mTotalBullets; i++){
		 delete mBullets[i];
		 mBullets[i] = NULL;
	}
	delete mBullets;
	mBullets = NULL;
	for(int i = 0; i < mTotalSpecialBullets; i++){
		 delete mSpecialBullets[i];
		 mSpecialBullets[i] = NULL;
	}
	delete mSpecialBullets;
	mSpecialBullets = NULL;
}

void Weapon::shoot(int X, int Y, int Width, int Height){
	if(mReloadTime == 0){
		if(mWeaponType == MachineGun){
			mSoundEffects->playSoundEffect(SoundEffects::MachineGunFire);
			machineGunShoot( X, Y, Width, Height);
		}else if(mWeaponType == Laser){
			mSoundEffects->playSoundEffect(SoundEffects::LaserFire);
			laserShoot( X, Y, Width, Height);
		}else if(mWeaponType == CornerGun){
			mSoundEffects->playSoundEffect(SoundEffects::MachineGunFire);
			cornerGunShoot( X, Y, Width, Height);
		}
	}
}

void Weapon::shootSpecial(int X, int Y){
	if(mSpecialBulletDelay == 0){
		mSpecialBulletDelay = mSpecialBulletDelayMax;
		for(int i = 0; i < mTotalSpecialBullets; i++){
			if(!mSpecialBullets[i]->getActive() && mSpecialCharge > 0){
				mSpecialBullets[i]->fired(X, Y);
				mSpecialCharge--;
				break;
			}
		}
	}
}

void Weapon::changeWeaponType(WeaponType NewWeaponType){
	if(mWeaponType != NewWeaponType){
		mWeaponLevel = 1;
		mWeaponType = NewWeaponType;
		mReloadTime = 0;
	}else{
		levelUpWeapon();
	}
}

void Weapon::update(){
	for(int i = 0; i < mTotalBullets; i++){
		if(mBullets[i]->getActive()){
			mBullets[i]->update();
		}
	}
	
	for(int i = 0; i < mTotalSpecialBullets; i++){
		if(mSpecialBullets[i]->getActive()){
			mSpecialBullets[i]->update();
		}
	}
	
	if(mSpecialBulletDelay > 0)mSpecialBulletDelay--;
	if(mReloadTime > 0)mReloadTime--;
	if(mLaserChargeTime > 0 )mLaserChargeTime--;	
	if(mLaserChargeTime == 0 && mLaserBulletCount > 0)mLaserBulletCount--;
}

void Weapon::draw(){
	for(int i = 0; i < mTotalBullets; i++){
		if(mBullets[i]->getActive()){
			mBullets[i]->draw();
		}
	}
	
	for(int i = 0; i < mTotalSpecialBullets; i++){
		if(mSpecialBullets[i]->getActive()){
			mSpecialBullets[i]->draw();
		}
	}
}

void Weapon::deactive(){
	for(int i = 0; i < mTotalBullets; i++){
		mBullets[i]->hit();
	}
	mReloadTime = 0;
	mLaserBulletCount = 0;
	mLaserChargeTime = 0;
	mSpecialCharge = 3;
	mSpecialBulletDelay = 0;
	mWeaponLevel = 1;
	mWeaponType = MachineGun;
}

void Weapon::increaseSpecialWeapon(){
	mSpecialCharge++;
}

bool Weapon::checkHit(int X, int Y, int Width, int Height){
	for(int i = 0; i < mTotalBullets; i++){
		if(mBullets[i]->getActive()){
			if(mCol.boxToBox(X,Y,Width,Height,mBullets[i]->getX(),mBullets[i]->getY(),mBullets[i]->getWidth(),mBullets[i]->getHeight())){
				mBullets[i]->hit();
				return true;
			}
		}
	}
	return false;
}

bool Weapon::getSpecialExplosion(){
	for(int i = 0; i < mTotalSpecialBullets; i++){
		if(mSpecialBullets[i]->getActive() && mSpecialBullets[i]->getExplode()){
			return true;
		}
	}
	return false;
}

int Weapon::getSpecialCharge(){
	return mSpecialCharge;
}

//Private Methods
void Weapon::levelUpWeapon(){
	if (mWeaponLevel < 3)mWeaponLevel++;
}

void Weapon::machineGunShoot(int X, int Y, int Width, int Height){
	if(mWeaponLevel == 1){
		for(int i = 0; i < mTotalBullets; i++){
			if(!mBullets[i]->getActive()){
				int StartX = (X-5)+(Width/2);
				mBullets[i]->fired(StartX, Y, 0, mBulletSpeed*mBulletDir, mBullets[i]->MachineGunBullet);
				mReloadTime = mMachineAndCornerReloadTimeMax;
				break;
			}
		}
	}else if(mWeaponLevel == 2){
		int bulletNum = 0;
		for(int i = 0; i < mTotalBullets; i++){
			if(!mBullets[i]->getActive()){
				if(bulletNum == 0){
					mBullets[i]->fired(X+5, Y+10, 0, mBulletSpeed*mBulletDir, mBullets[i]->MachineGunBullet);	
					bulletNum ++;
				}else if(bulletNum == 1){
					mBullets[i]->fired((X+Width)-17, Y+10, 0, mBulletSpeed*mBulletDir, mBullets[i]->MachineGunBullet);
					mReloadTime = mMachineAndCornerReloadTimeMax-10;
					break;
				}
			}
		}		
	}else if(mWeaponLevel == 3){
		int bulletNum = 0;
		for(int i = 0; i < mTotalBullets; i++){
			if(!mBullets[i]->getActive()){
				if(bulletNum == 0){
					mBullets[i]->fired(X+5, Y+10, 0, mBulletSpeed*mBulletDir, mBullets[i]->MachineGunBullet);	
					bulletNum ++;
				}else if(bulletNum == 1){
					int StartX = (X-5)+(Width/2);
					mBullets[i]->fired(StartX, Y, 0, mBulletSpeed*mBulletDir, mBullets[i]->MachineGunBullet);
					bulletNum ++;
				}else if(bulletNum == 2){
					mBullets[i]->fired((X+Width)-17, Y+10, 0, mBulletSpeed*mBulletDir, mBullets[i]->MachineGunBullet);
					mReloadTime = mMachineAndCornerReloadTimeMax-20;
					break;
				}
			}
		}
	}
}
	
void Weapon::laserShoot(int X, int Y, int Width, int Height){
	int bulletMax = 10;
	if(mWeaponLevel == 1){
		bulletMax =10;
	}else if(mWeaponLevel == 2){
		bulletMax =20;
	}else if(mWeaponLevel == 3){
		bulletMax =30;
	}
	
	if(mLaserBulletCount < bulletMax){
		for(int i = 0; i < mTotalBullets; i++){
			if(!mBullets[i]->getActive()){
				int StartX = (X-5)+(Width/2);
				mBullets[i]->fired(StartX, Y, 0, mLaserSpeed*mBulletDir, mBullets[i]->LaserBeam);
				mLaserBulletCount++;
				mReloadTime = mLaserReloadTimeMax;
				mLaserChargeTime = 60;
				break;
			}
		}
	}
}

void Weapon::cornerGunShoot(int X, int Y, int Width, int Height){
	if(mWeaponLevel == 1){
		for(int i = 0; i < mTotalBullets; i++){
			if(!mBullets[i]->getActive()){
				int StartX = (X-5)+(Width/2);
				mBullets[i]->fired(StartX, Y, 0, mBulletSpeed*mBulletDir, mBullets[i]->CornerGunBullet);
				mReloadTime = mMachineAndCornerReloadTimeMax;
				break;
			}
		}
	}else if(mWeaponLevel == 2){
		int bulletNum = 0;
		for(int i = 0; i < mTotalBullets; i++){
			if(!mBullets[i]->getActive()){
				if(bulletNum == 0){
					mBullets[i]->fired(X+5, Y, -2, mBulletSpeed*mBulletDir, mBullets[i]->CornerGunBullet);	
					bulletNum ++;
				}else if(bulletNum == 1){
					mBullets[i]->fired((X+Width)-5, Y, 2, mBulletSpeed*mBulletDir, mBullets[i]->CornerGunBullet);
					mReloadTime = mMachineAndCornerReloadTimeMax-10;
					break;
				}
			}
		}		
	}else if(mWeaponLevel == 3){
		int bulletNum = 0;
		for(int i = 0; i < mTotalBullets; i++){
			if(!mBullets[i]->getActive()){
				if(bulletNum == 0){
					mBullets[i]->fired(X+5, Y, -2, mBulletSpeed*mBulletDir, mBullets[i]->CornerGunBullet);	
					bulletNum ++;
				}else if(bulletNum == 1){
					int StartX = (X-5)+(Width/2);
					mBullets[i]->fired(StartX, Y, 0, mBulletSpeed*mBulletDir, mBullets[i]->CornerGunBullet);
					bulletNum ++;
				}else if(bulletNum == 2){
					mBullets[i]->fired((X+Width)-5, Y, 2, mBulletSpeed*mBulletDir, mBullets[i]->CornerGunBullet);
					mReloadTime = mMachineAndCornerReloadTimeMax-20;
					break;
				}
			}
		}
	}
}
