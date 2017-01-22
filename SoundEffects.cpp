#include "SoundEffects.h"

SoundEffects::SoundEffects(DATAFILE *Data){
	mTotalAmountSoundEffect = 7;
	mSoundEffect = new SAMPLE*[mTotalAmountSoundEffect];
	mSoundEffect[0] = (SAMPLE *)Data[CLICK_WAV].dat;//load_sample("SoundEffects/Click.wav");
    mSoundEffect[1] = (SAMPLE *)Data[EXPLODE_WAV].dat;//load_sample("SoundEffects/Explode.wav");
    mSoundEffect[2] = (SAMPLE *)Data[LASERGUN_WAV].dat;//load_sample("SoundEffects/LaserGun.wav");
    mSoundEffect[3] = (SAMPLE *)Data[GUN_WAV].dat;//load_sample("SoundEffects/Gun.wav");
    mSoundEffect[4] = (SAMPLE *)Data[UPCOLLECT_WAV].dat;//load_sample("SoundEffects/UpCollect.wav");
    mSoundEffect[5] = (SAMPLE *)Data[THRUSTER_WAV].dat;//load_sample("SoundEffects/Thruster.wav");
    mSoundEffect[6] = (SAMPLE *)Data[MISSILE_WAV].dat;//load_sample("SoundEffects/Missile.wav");
    mVolume = 128;
    mPan = 128;
    mPitch = 1000;
}

SoundEffects::~SoundEffects(){
	for (int i=0; i<mTotalAmountSoundEffect; i++){
        destroy_sample(mSoundEffect[i]);
    }
    delete mSoundEffect;
}

void SoundEffects::playSoundEffect(SoundEffect ToPlaySoundEffect){
	switch(ToPlaySoundEffect){
		case Click:
			play_sample(mSoundEffect[0], mVolume, mPan, mPitch, FALSE);
			break;
		case Destroyed:
			play_sample(mSoundEffect[1], mVolume, mPan, mPitch, FALSE);
			break;
		case LaserFire:
			play_sample(mSoundEffect[2], mVolume, mPan, mPitch, FALSE);
			break;
		case MachineGunFire:
			play_sample(mSoundEffect[3], mVolume, mPan, mPitch, FALSE);
			break;
		case Thruster:
			play_sample(mSoundEffect[4], mVolume, mPan, mPitch, FALSE);
			break;
		case ShipUpgradeCollect:
			play_sample(mSoundEffect[5], mVolume, mPan, mPitch, FALSE);
			break;
		case Missile:
			play_sample(mSoundEffect[6], mVolume, mPan, mPitch, FALSE);
			break;
	}
}

void SoundEffects::soundEffectToggle(){
	if(mVolume == 128)mVolume = 0;
	else mVolume = 128;
}
