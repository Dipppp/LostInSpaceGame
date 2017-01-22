#ifndef ENEMYCONTROLLER_H
#define ENEMYCONTROLLER_H

#include "Enemy.h"


//PURPOSE - The Class is for controlling all the enemys
class EnemyController  {
	public:
		//PURPOSE: 	Sets the default values for the object variables
		//INPUT:	Screen 		- The pointer to game screen
		//			Image 		- The pointer to bitmap of all the player images
		//			WeaponImage	- The pointer to bitmap of all the weapons image
		//			SoundEffect	- The pointer to the sound effects	
		//OUTPUT:	NONE
		EnemyController(BITMAP *Screen, BITMAP *Image, BITMAP *WeaponImage, SoundEffects *SoundEffect);
		//PURPOSE:	Free memory of mEnemys array
		//INPUT:	NONE
		//OUTPUT:	NONE
		~EnemyController();
		//PURPOSE:	Calls the spawn method and updates any active enemy
		//INPUT:	
		//OUTPUT:	NONE
		void update(int X, int Y);
		//PURPOSE:	Draws any active enemy
		//INPUT:	NONE
		//OUTPUT:	NONE
		void draw();
		//PURPOSE:	Calls any active enemys fire method
		//INPUT:	X			- Player x position
		//			Y			- Player y position
		//			Width		- Player width
		//OUTPUT:	NONE
		void fireWeapon(int X, int Y, int Width);
		//PURPOSE:	Resets enemies
		//INPUT:	NONE
		//OUTPUT:	NONE
		void reset();
		//PURPOSE:	Changes the enemy difficulty
		//INPUT:	Score		- Current score
		//OUTPUT:	NONE		
		void changeDifficulty(int Score);
		//PURPOSE:	Lets the enemy in the array that was hit know and
		//				return points for the enemy deoending on it type
		//				and if the enemy was asteroid type spawns two 
		//				asteroidmini enemy types
		//INPUT:	i			- Enemy in array that was hit
		//OUTPUT:	Returns points for the hit enemy
		//			0 if no enemy found
		int hitAndGetPoints(int i);
		//PURPOSE:	Return the enemy x position for provide enemy in the enemy array 
		//			if the enemy is active and in the array
		//INPUT:	i			- enemy in the array
		//OUTPUT:	Return enemy x position
		//				-1 if not active or i not in the array
		int getEnemyX(int i);
		//PURPOSE:	Return the enemy y position for provide enemy in the enemy array 
		//			if the enemy is active and in the array
		//INPUT:	i			- enemy in the array
		//OUTPUT:	Return enemy y position
		//				-1 if not active or i not in the array
		int getEnemyY(int i);
		//PURPOSE:	Return the enemy widthn for provide enemy in the enemy array 
		//			if the enemy is active and in the array
		//INPUT:	i			- enemy in the array
		//OUTPUT:	Return enemy width
		//				-1 if not active or i not in the array
		int getEnemyWidth(int i);
		//PURPOSE:	Return the enemy height for provide enemy in the enemy array 
		//			if the enemy is active and in the array
		//INPUT:	i			- enemy in the array
		//OUTPUT:	Return enemy height
		//				-1 if not active or i not in the array
		int getEnemyHeight(int i);
		//PURPOSE:	Returns the total number enemy object in the array
		//INPUT:	NONE
		//OUTPUT:	Return mTotalEnemys
		int getTotalEnemy();
		//PURPOSE:	Destroy all enemy on the screen reset the spawn timer to zero
		//				and returns the total score
		//INPUT:	NONE
		//OUTPUT:	Return total score from destroyed enemies
		int specialWeaponDestroy();
		//PURPOSE:	Check if the player collide with any active enemy or there weapons
		//INPUT:	X			- Players x position
		//			Y			- Players y position
		//			Width		- Players width
		//			Height		- Players height
		//OUTPUT:	Return result of the check true if collision else false
		bool checkIfEnemyHitPlayer(int X, int Y, int Width, int Height);
	private:
		//PURPOSE:	Total number of enemys in enemy object array
		int mTotalEnemys;
		//PURPOSE:	Timer before another spawn pattern is used
		int mSpawnTimer;
		//PURPOSE:	Enemy object array
		Enemy **mEnemy;
		//PURPOSE: 	Holds the difficulty level
		int mDifficultyMeter;
		
		//PURPOSE:	Randomally selects a spawn pattern to use when spawn timer is up
		//INPUT:	NONE
		//OUTPUT:	NONE
		void spawn();
		//PURPOSE:	Spawn enemy in a unique pattern
		//INPUT:	NONE
		//OUTPUT:	NONE
		void spawnPatternOne();
		//PURPOSE:	Spawn enemy in a unique pattern
		//INPUT:	NONE
		//OUTPUT:	NONE
		void spawnPatternTwo();
		//PURPOSE:	Spawn enemy in a unique pattern
		//INPUT:	NONE
		//OUTPUT:	NONE
		void spawnPatternThree();
		//PURPOSE:	Spawn enemy in a unique pattern
		//INPUT:	NONE
		//OUTPUT:	NONE
		void spawnPatternFour();
		//PURPOSE:	Spawn enemy in a unique pattern
		//INPUT:	NONE
		//OUTPUT:	NONE
		void spawnPatternFive();
		//PURPOSE:	Spawn enemy in a unique pattern
		//INPUT:	NONE
		//OUTPUT:	NONE
		void spawnPatternSix();
		//PURPOSE:	Spawn enemy in a unique pattern
		//INPUT:	NONE
		//OUTPUT:	NONE
		void spawnPatternSeven();
		//PURPOSE:	Spawn enemy in a unique pattern
		//INPUT:	NONE
		//OUTPUT:	NONE
		void spawnPatternEight();
};

#endif
