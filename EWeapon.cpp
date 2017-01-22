#include "EWeapon.h"

EWeapon::EWeapon(BITMAP *Screen, BITMAP *Image, SoundEffects *SoundEffect):Weapon(Screen,Image, SoundEffect){

	
	mWeaponLevel = 1;
	mWeaponType = Weapon::NonStandardType;
	
	for(int i = 0; i < mTotalBullets; i++){
	 delete mBullets[i];
	 mBullets[i] = NULL;
	}
	delete mBullets;
	mBullets = NULL;
	
	mBulletDir= -1;
	mTotalBullets = 2;
	mEBullets = new EBullet*[mTotalBullets];
	mBullets = new Bullet*[mTotalBullets];
	for(int i = 0; i < mTotalBullets; i++){
		mEBullets[i] = new EBullet(Screen, Image);
		mBullets[i] = mEBullets[i];
	}
	
	
}

EWeapon::~EWeapon(){
}

void EWeapon::changeReloadMax(int NewMax){
	if(NewMax > 60){
		mMachineAndCornerReloadTimeMax = NewMax;	
	}
}

void EWeapon::shoot(int X, int Y, int Width, int Height){
	if(mWeaponType !=NonStandardType)Weapon::shoot(X,Y+Height,Width,Height);
	else{
		if(mReloadTime == 0){
			mSoundEffects->playSoundEffect(SoundEffects::Missile);
			for(int i = 0; i < mTotalBullets; i++){
				if(!mBullets[i]->getActive()){
					int StartX = (X-5)+(Width/2);
					mEBullets[i]->fired(StartX, Y, 2, 2);
					mReloadTime = mMachineAndCornerReloadTimeMax;
					break;
				}
			}
		}
	}
}

void EWeapon::update(int X, int Y){
	if(mWeaponType!=NonStandardType)Weapon::update();
	else{
		for(int i = 0; i < mTotalBullets; i++){
			if(mBullets[i]->getActive()){
				mEBullets[i]->update(X,Y);
			}
		}
		if(mReloadTime > 0)mReloadTime--;
	}
}

void EWeapon::setWeaponType(EWeaponType Type){
	switch (Type){
		case MachineGun:
			mWeaponType = Weapon::MachineGun;
			break;
		case CornerGun:
			mWeaponType = Weapon::CornerGun;
			break;
		case Missile:
			mWeaponType = Weapon::NonStandardType;
			break;
	}
}

bool EWeapon::getActive(){
	for(int i = 0; i < mTotalBullets; i++){
		if(mEBullets[i]->getActive())return true;
	}
	return false;
}
