#include "EnemyController.h"

EnemyController::EnemyController(BITMAP *Screen, BITMAP *Image, BITMAP *WeaponImage, SoundEffects *SoundEffect){
	mTotalEnemys = 50;
	mEnemy = new Enemy*[mTotalEnemys];
	for(int i = 0; i != mTotalEnemys; i++){
		mEnemy[i] = new Enemy(Screen, Image, WeaponImage, SoundEffect);
	}
	mSpawnTimer = 0;
	mDifficultyMeter=0;
}

EnemyController::~EnemyController(){
	for(int i = 0; i != mTotalEnemys; i++){
		delete mEnemy[i];
	}
	delete [] mEnemy;
	mEnemy = NULL;
}

void EnemyController::update(int X, int Y){
	spawn();
	for(int i = 0; i != mTotalEnemys; i++){
		if(mEnemy[i]->getActive()){
			mEnemy[i]->update(X, Y);
		}
	}
}

void EnemyController::draw(){
	for(int i = 0; i != mTotalEnemys; i++){ 
		if(mEnemy[i]->getActive()){
			mEnemy[i]->draw();
		}
	}
}

void EnemyController::fireWeapon(int X, int Y, int Width){
	for(int i = 0; i != mTotalEnemys; i++){ 
		if(mEnemy[i]->getActive()){
			mEnemy[i]->fireWeapon(X, Y, Width);
		}
	}
}

void EnemyController::reset(){
	for(int i = 0; i != mTotalEnemys; i++){ 
		if(mEnemy[i]->getActive()){
			mEnemy[i]->deactive();
		}
	}
	mSpawnTimer = 0;
	mDifficultyMeter=0;
}

void EnemyController::changeDifficulty(int Score){
	if(Score > 20000){
		mDifficultyMeter=4;
	}else if(Score > 15000){
		mDifficultyMeter=3;
	}else if(Score > 10000){
		mDifficultyMeter=2;
	}else if(Score > 5000){
		mDifficultyMeter=1;
	}
}

int EnemyController::hitAndGetPoints(int i){
	if(i < mTotalEnemys){
		mEnemy[i]->hit();
	}
	if(mEnemy[i]->getType() == Enemy::Asteroid){
		int count = 0;
		int offset = 25;
		for(int j = 0; j != mTotalEnemys; j++){
			if(!mEnemy[j]->getActive()){
				mEnemy[j]->spawn(mEnemy[i]->getX()+offset,mEnemy[i]->getY(),Enemy::AsteroidMini);
				offset*=-1;
				if(count==1)mEnemy[j]->asteroidMiniLeftDir();
				count++;
				if(count>1)break;
			}
		}
		return 10;
	}else if(mEnemy[i]->getType() == Enemy::Snake){
		return 10;
	}else if(mEnemy[i]->getType() == Enemy::Step){
		return 20;
	}else if(mEnemy[i]->getType() == Enemy::ReverseStep){
		return 30;
	}else if(mEnemy[i]->getType() == Enemy::ZigZag){
		return 20;
	}else if(mEnemy[i]->getType() == Enemy::AsteroidMini){
		return 5;
	}
	return 0;
}

int EnemyController::getEnemyX(int i){
	if(i < mTotalEnemys && mEnemy[i]->getActive()){
		return mEnemy[i]->getX();
	}
	return -1;
}

int EnemyController::getEnemyY(int i){
	if(i < mTotalEnemys && mEnemy[i]->getActive()){
		return mEnemy[i]->getY();
	}
	return -1;
}

int EnemyController::getEnemyWidth(int i){
	if(i < mTotalEnemys && mEnemy[i]->getActive()){
		return mEnemy[i]->getWidth();
	}
	return -1;
}

int EnemyController::getEnemyHeight(int i){
	if(i < mTotalEnemys && mEnemy[i]->getActive()){
		return mEnemy[i]->getHeight();
	}
	return -1;
}

int EnemyController::getTotalEnemy(){
	return mTotalEnemys;
}

int EnemyController::specialWeaponDestroy(){
	int total = 0;
	for(int i = 0; i != mTotalEnemys; i++){ 
		if(mEnemy[i]->getActive()){
			if(mEnemy[i]->getType() == Enemy::Asteroid){
				total+= 10;
			}else if(mEnemy[i]->getType() == Enemy::Snake){
				total+= 10;
			}else if(mEnemy[i]->getType() == Enemy::Step){
				total+= 20;
			}else if(mEnemy[i]->getType() == Enemy::ReverseStep){
				total+= 30;
			}else if(mEnemy[i]->getType() == Enemy::ZigZag){
				total+= 20;
			}else if(mEnemy[i]->getType() == Enemy::AsteroidMini){
				total+= 5;
			}
			mEnemy[i]->hit();
		}		
	}
	mSpawnTimer = 0;
	return total;
}

bool EnemyController::checkIfEnemyHitPlayer(int X, int Y, int Width, int Height){
	for(int i = 0; i < mTotalEnemys; i++){
		if(mEnemy[i]->getActive()){
			if(mEnemy[i]->checkHit( X, Y, Width, Height))return true;
		}
	}
	return false;
}

//Private Methods
void EnemyController::spawn(){
	if(mSpawnTimer < 0){
		int random = rand() % 7;
		switch (random){
			case 0:
				spawnPatternOne();
				break;
			case 1:
				spawnPatternTwo();
				break;
			case 2:
				spawnPatternThree();
				break;
			case 3:
				spawnPatternFour();
				break;
			case 4:
				spawnPatternFive();
				break;
			case 5:
				spawnPatternSix();
				break;
			case 6:
				spawnPatternSeven();
				break;
		}
		random = rand() % 2;
		if(random == 1){
			spawnPatternEight();
		}
		mSpawnTimer=750;
	}
	mSpawnTimer--;
}

//Zig zag two line
void EnemyController::spawnPatternOne(){
	int x = -50;
	int y = -50;
	int count = -1;
	for(int i = 0; i != mTotalEnemys; i++){ 
		if(!mEnemy[i]->getActive()){
			count++;
			if(count < 8){
				mEnemy[i]->setDifficulty(mDifficultyMeter);
				mEnemy[i]->spawn(x,y,Enemy::ZigZag);
				x-=30;
				y-=30;
			}
			if(count == 8){
				x=SCREEN_W+50;
			}
			if(count > 8 && count < 19){
				mEnemy[i]->setDifficulty(mDifficultyMeter);
				mEnemy[i]->spawn(x,y,Enemy::ZigZag);
				x+=30;
				y-=30;
			}
			if(count > 19)break;
		}
	}
}

//Straight down random
void EnemyController::spawnPatternTwo(){
	int x = (rand() % SCREEN_W)-50;
	int y = ((rand() % 300)+1)*-1;
	int count = -1;
	for(int i = 0; i != mTotalEnemys; i++){ 
		if(!mEnemy[i]->getActive()){
			count++;
			if(count < 10){
				mEnemy[i]->setDifficulty(mDifficultyMeter);
				mEnemy[i]->spawn(x,y,Enemy::Asteroid);
				x = (rand() % SCREEN_W)-50;
				y = ((rand() % 300)+1)*-1;
			}else{
				break;
			}
		}
	}
}

//Line Reverse stair
void EnemyController::spawnPatternThree(){
	int x = 0;
	int y = -50;
	int count = -1;
	for(int i = 0; i != mTotalEnemys; i++){ 
		if(!mEnemy[i]->getActive()){
			count++;
			if(count < 8){
				mEnemy[i]->setDifficulty(mDifficultyMeter);
				mEnemy[i]->spawn(x,y,Enemy::ReverseStep);
				x+=100;
			}else{
				break;
			}
		}
	}
}

//Snake line
void EnemyController::spawnPatternFour(){
	int x = -50;
	int y = 0;
	int count = -1;
	for(int i = 0; i != mTotalEnemys; i++){ 
		if(!mEnemy[i]->getActive()){
			count++;
			if(count < 8){
				mEnemy[i]->setDifficulty(mDifficultyMeter);
				mEnemy[i]->spawn(x,y,Enemy::Snake);
				x-=100;
			}else{
				break;
			}
		}
	}
}
//Snake Rows
void EnemyController::spawnPatternFive(){
	int x = -50;
	int d = 50; 
	int y = 150;
	int count = -1;
	for(int i = 0; i != mTotalEnemys; i++){
		if(!mEnemy[i]->getActive()){
			count++;
			if(count < 8){
				mEnemy[i]->setDifficulty(mDifficultyMeter);
				mEnemy[i]->spawn(x,y,Enemy::Snake);
				x-=d;
				y-=50;
				if(count==3){
					x=800;
					d=-50;
				}
				
			}else{
				break;
			}
		}
	}
}

//Stair & reverse stair mix
void EnemyController::spawnPatternSix(){
	int x = -50;
	int d = 50; 
	int y = 0;
	bool Switch = true;
	int count = -1;
	for(int i = 0; i != mTotalEnemys; i++){
		if(!mEnemy[i]->getActive()){
			count++;
			if(count < 8){
				if(Switch){
					mEnemy[i]->setDifficulty(mDifficultyMeter);
					mEnemy[i]->spawn(x,y,Enemy::Step);
					Switch = false;
					y-=50;
				}else{
					mEnemy[i]->setDifficulty(mDifficultyMeter);
					mEnemy[i]->spawn(x,y,Enemy::ReverseStep);
					Switch = true;
					y-=100;
				}
				x-=d;
				if(count==3){
					x=800;
					d=-50;
					y=0;
				}
			}else{
				break;
			}
		}
	}
}

void EnemyController::spawnPatternSeven(){
	int x = -50;
	int d = 50; 
	int y = 0;
	int count = -1;
	for(int i = 0; i != mTotalEnemys; i++){
		if(!mEnemy[i]->getActive()){
			count++;
			if(count < 6){
				mEnemy[i]->setDifficulty(mDifficultyMeter);
				mEnemy[i]->spawn(x,y,Enemy::Step);
				x-=d;
				y-=50;
				if(count == 2){
					x=800;
					d=-50;
					y=0;
				}
			}else if (count < 14){
				x = (rand() % SCREEN_W)-50;
				y = ((rand() % 300)+1)*-1;
				mEnemy[i]->setDifficulty(mDifficultyMeter);
				mEnemy[i]->spawn(x,y,Enemy::Asteroid);
			}else{
				break;
			}
		}
	}
}

void EnemyController::spawnPatternEight(){
	int x = (rand() % SCREEN_W)-50;
	int y = -50;
	for(int i = 0; i != mTotalEnemys; i++){
		if(!mEnemy[i]->getActive()){
			mEnemy[i]->setDifficulty(mDifficultyMeter);
			mEnemy[i]->spawn(x,y,Enemy::KamikazeRunner);
			break;
		}
	}
}
