#include "GameLogic.h"

GameLogic::GameLogic(){
	mData = load_datafile("GameData.dat"); 
	mBuffer = create_bitmap(SCREEN_W, SCREEN_H);
    //mImages = new Images();
    mSoundEffects = new SoundEffects(mData);
    mMusic = new Music(mData);
	mPlayer = new Player(mBuffer,(BITMAP *)mData[PLAYER_BMP].dat,(BITMAP *)mData[PLAYERBULLET_BMP].dat,mSoundEffects);
	mEnemys = new EnemyController(mBuffer,(BITMAP *)mData[ENEMYS_BMP].dat,(BITMAP *)mData[ENEMYBULLET_BMP].dat,mSoundEffects);
	mGameScreen = new GameScreen(mBuffer,(BITMAP *)mData[GAMESCREENIMAGES_BMP].dat);
	mHelpScreen = new HelpScreen(mBuffer,(BITMAP *)mData[HELPSCREENIMAGES_BMP].dat,mSoundEffects);
	mStartScreen = new StartScreen(mBuffer,(BITMAP *)mData[STARTSCREEN_BMP].dat,mSoundEffects);
	mGameOverScreen = new GameOverScreen(mBuffer,(BITMAP *)mData[GAMEOVERSCREENIMAGES_BMP].dat,mSoundEffects);
	mBreakableObj = new BreakableObject*[4];
	for(int i = 0; i < 4; i++){
		mBreakableObj[i] = new BreakableObject(mBuffer,(BITMAP *)mData[ALLBREAKABLEOBJ_BMP].dat,mSoundEffects);
	}
}

GameLogic::~GameLogic(){
	destroy_bitmap(mBuffer);
	//delete mImages;
	unload_datafile(mData); 
	delete mSoundEffects;
	delete mPlayer;
	delete mEnemys;
	delete mGameScreen;
	delete mHelpScreen;
	delete mStartScreen;
	delete mGameOverScreen;
	for(int i = 0; i < 4; i++){
		delete mBreakableObj[i];
	}
	delete mBreakableObj;
}

void GameLogic::update(){
	userInputs();
	if(!mHelpScreen->getActive() && !mStartScreen->getStarted())mStartScreen->update();
	if(!mHelpScreen->getActive() && !mStartScreen->getStarted() && mStartScreen->getHelp())mHelpScreen->mainHelpSwitch();
	
	if(!mHelpScreen->getActive() && mStartScreen->getStarted()){
		if(!mGameScreen->gameover()){
			mGameScreen->update();
			mGameScreen->setNumSWScharge(mPlayer->getSpecialWeaponCharges());
				
			//Ship Upgrades
			spawnShipUpgrades();
			for(int i = 0; i < 4; i++){
				if(mBreakableObj[i]->getActive())mBreakableObj[i]->update();
			}
			checkShipUpgradesHit();
			
			//enemy hits
			mEnemys->fireWeapon(mPlayer->getX(),mPlayer->getY(),mPlayer->getWidth());
			mEnemys->changeDifficulty(mGameScreen->getScore());
			mEnemys->update(mPlayer->getX(),mPlayer->getY());	
			
			checkPlayerBulletHitEnemy();
			checkEnemyBulletOrEnemyHitPlayer();
			
			checkPlayerSpecialWeapon();
			
			playerShipInputs();
			mPlayer->update();
			
		}else{
			mGameOverScreen->update();
			if(mGameOverScreen->getPlayAgain()){
				mPlayer->reset();
				mEnemys->reset();
				mGameScreen->reset();
				mGameOverScreen->unSetPlayAgain();
			}
		}
	}
}

void GameLogic::draw(){
	if(mHelpScreen->getActive()){
		mHelpScreen->draw();
	}else{
		if(!mStartScreen->getStarted()){
			mStartScreen->draw();
		}else{
			if(!mGameScreen->gameover()){
				mGameScreen->draw();
				for(int i = 0; i < 4; i++){
					if(mBreakableObj[i]->getActive())mBreakableObj[i]->draw();
				}
				mEnemys->draw();
				mPlayer->draw();
			}else{
				mGameOverScreen->draw();
			}
		}
	}
	
	blit(mBuffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
}

//Private Methods
void GameLogic::playerShipInputs(void){
	if(key[KEY_W] && key[KEY_D]){
		mPlayer->moveUpRight();
	}else if(key[KEY_S] && key[KEY_D]){
		mPlayer->moveDownRight();
	}else if(key[KEY_W] && key[KEY_A]){
		mPlayer->moveUpLeft();
	}else if(key[KEY_S] && key[KEY_A]){
		mPlayer->moveDownLeft();
	}else if(key[KEY_W]){
		mPlayer->moveUp();
	}else if(key[KEY_S]){
		mPlayer->moveDown();
	}else if(key[KEY_D]){
		mPlayer->moveRight();
	}else if(key[KEY_A]){
		mPlayer->moveLeft();
	}else{
		mPlayer->moveNeutral();
	}
	
	if(key[KEY_SPACE]){
		mPlayer->fireWeapon();
	}
	if(key[KEY_E]){
		mPlayer->fireSpecialWeapon();
	}
}

void GameLogic::userInputs(){
	if(key[KEY_H] && (key[KEY_LCONTROL] || key[KEY_RCONTROL])){
		if(mStartScreen->getStarted())mHelpScreen->quickHelpSwitch();
	}
	
	if(key[KEY_M] && (key[KEY_LCONTROL] || key[KEY_RCONTROL])){
		mMusic->musicToggle();
	}
	
	if(key[KEY_N] && (key[KEY_LCONTROL] || key[KEY_RCONTROL])){
		mSoundEffects->soundEffectToggle();
	}
	
	if(mouse_b & 1){
		if(!mHelpScreen->getActive() && !mStartScreen->getStarted()){
			mStartScreen->clicked(mouse_x, mouse_y);
			if(mStartScreen->getStarted())mMusic->play();
		}
		if(!mHelpScreen->getActive() && mStartScreen->getStarted() && mGameScreen->gameover())mGameOverScreen->clicked(mouse_x, mouse_y);
		if(mHelpScreen->getActive())mHelpScreen->clicked(mouse_x, mouse_y);
	}
	
}

void GameLogic::spawnShipUpgrades(){
	int spawn = rand() % 1250;
	int type = rand() % 5;
	int x = rand() % 580;
	if(spawn == 0){
		for(int i = 0; i < 4; i++){
			if(!mBreakableObj[i]->getActive()){
				mBreakableObj[i]->spawn(x,-20,static_cast<BreakableObject::BObjectType>(type));
				break;
			}
		}
	}
}

void GameLogic::checkShipUpgradesHit(){
	for(int i = 0; i < 4; i++){
		if(mBreakableObj[i]->getActive()){
			if(mPlayer->checkHitWithBullet(mBreakableObj[i]->getX(),mBreakableObj[i]->getY(),mBreakableObj[i]->getWidth(),mBreakableObj[i]->getHeight())){
				if(mBreakableObj[i]->getType() == BreakableObject::Life){
					mGameScreen->increaseNumberLifes();
				}else if(mBreakableObj[i]->getType() == BreakableObject::MGPowerUp){
					mPlayer->weaponUpgrade(Weapon::MachineGun);
				}else if(mBreakableObj[i]->getType() == BreakableObject::LPowerUp){
					mPlayer->weaponUpgrade(Weapon::Laser);
				}else if(mBreakableObj[i]->getType() == BreakableObject::CGPowerUp){
					mPlayer->weaponUpgrade(Weapon::CornerGun);
				}else if(mBreakableObj[i]->getType() == BreakableObject::SPowerUp){
					if(mPlayer->getSpecialWeaponCharges()<3)mPlayer->increaseSpecialWeapon();
				}
				mBreakableObj[i]->hit();
			}
		}
	}
}

void GameLogic::checkPlayerBulletHitEnemy(){
	for(int i = 0; i != mEnemys->getTotalEnemy(); i++ ){
		if(mEnemys->getEnemyX(i) != -1 && mEnemys->getEnemyY(i) != -1 && mEnemys->getEnemyWidth(i) != -1 && mEnemys->getEnemyHeight(i) != -1){
			if(mPlayer->checkHitWithBullet(mEnemys->getEnemyX(i),mEnemys->getEnemyY(i),mEnemys->getEnemyWidth(i),mEnemys->getEnemyHeight(i))){
				mGameScreen->increaseScoreBy(mEnemys->hitAndGetPoints(i));
				break;
			}
		}
	}
}

void GameLogic::checkEnemyBulletOrEnemyHitPlayer(){
	if(mEnemys->checkIfEnemyHitPlayer(mPlayer->getX(),mPlayer->getY(),mPlayer->getWidth(),mPlayer->getHeight())){
		mGameScreen->decreaseNumberLifes();
		mPlayer->destroyed();
		if(mGameScreen->gameover())mGameOverScreen->gameoverSwitch(mGameScreen->getScore());
	}
}

void GameLogic::checkPlayerSpecialWeapon(){
	if(mPlayer->specialWeaponExplode()){
		mGameScreen->increaseScoreBy(mEnemys->specialWeaponDestroy());
	}
}
