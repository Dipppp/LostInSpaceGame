#ifndef ENEMY_H
#define ENEMY_H

#include <math.h>

#include "GameObject.h"
#include "EWeapon.h"
#include "CollisionDetection.h"

//PURPOSE - The Class is for the all the enemy types and uses the game object class as a parent
class Enemy : public GameObject {
	public:
		//PURPOSE: The different types of enemys
		enum EnemyType{Asteroid = 0, Snake = 1, Step = 2, ReverseStep = 3, ZigZag = 4, AsteroidMini = 5, KamikazeRunner = 6};
		//PURPOSE: 	Sets the default values for the object variables
		//INPUT:	Screen 		- The pointer to game screen
		//			Image 		- The pointer to bitmap of all the enemy images
		//			WeaponImage	- The pointer to bitmap of all the weapons image
		//			SoundEffect	- The pointer to the sound effects	
		//OUTPUT:	NONE
		Enemy(BITMAP *Screen, BITMAP *Image, BITMAP *WeaponImage, SoundEffects *SoundEffect);
		//PURPOSE:	Free memory of mWeapon and mImagePage
		//INPUT:	NONE
		//OUTPUT: 	NONE
		~Enemy();
		//PURPOSE:	Spawn the type of enemy provide and set the value for the enemy to the type
		//				and exacts that type of enemys image from mAllImage and puts it in 
		//				mImages and set mCurImage the default image for that type of enemy
		//INPUT:	X			- The x position to spawn the enemy from
		//			Y			- The y position to spawn the enemy from
		//			Type		- The type of enemy to spawn
		//OUTPUT: 	NONE
		void spawn(int X, int Y, EnemyType Type);
		//PURPOSE:	Sets mRightDirection to false 
		//INPUT:	NONE
		//OUTPUT: 	NONE
		void asteroidMiniLeftDir();
		//PURPOSE: 	Sets enemy speed to zero and mCurrentAni state to destroyed if
		//				enemy type is not asteroid or asteroid mini otherwise set mActive to false
		//INPUT:	NONE
		//OUTPUT: 	NONE
		void hit();
		//PURPOSE:	Fire the weapon if the player is in its firing range( which is if enemys middle  
		//				inbetween the players x position and x+width) and player y greater than mY 
		//				and if enemy is not a asteroid or asteroidmini type and mCurrentAni is not 
		//				in the destroyed state
		//INPUT:	X			- The players x position
		//			Y			- The players y position
		//			Width		- The players width
		//OUTPUT: 	NONE
		void fireWeapon(int X, int Y, int Width);
		//PURPOSE:	Calls parent class update method and animate method, call the weapons update
		//				and call the movement method if mCurrentAni is not in the destroyed state
		//				and check if the out of bounds if yes set mActive to false
		//				and checks if in destroyed state and destroyed timer and no active bullet
		//				up then set mActive to false otherwise clear objects image
		//INPUT:	X			- Players X position
		//			Y			- Players Y position
		//OUTPUT: 	NONE
		void update(int X, int Y);
		//PURPOSE:	Call parents draw method and draws weapons
		//INPUT:	NONE
		//OUTPUT: 	NONE
		void draw();
		//PURPOSE:	Deactives all the bullets
		//INPUT:	NONE
		//OUTPUT:	NONE		
		void deactive();
		//PURPOSE:	Sets the enemy difficulty
		//INPUT:	DifficutlyLevel	- The current difficutly level
		//OUTPUT:	NONE		
		void setDifficulty(int DifficutlyLevel);
		//PURPOSE:	Returns if the object is active
		//INPUT:	NONE
		//OUTPUT: 	Return mActive
		bool getActive();
		//PURPOSE:	Check if the box provide through the values collides with a bullet from the weapon
		//				and the enemy itself then return the result
		//INPUT:	X			- The x position of the box to check against
		//			Y			- The y position of the box to check against
		//			Width		- The width of the box to check against
		//			Height		- The height of the box to check against
		//OUTPUT:	Return true if there is a collision
		//					false if no collision
		bool checkHit(int X, int Y, int Width, int Height);
		//PURPOSE:	Return player x position or -1
		//INPUT:	NONE
		//OUTPUT:	Return mX if mCurrentAni is not in destroyed 
		//					-1 if mCurrentAni is in destroyed
		int getX();
		//PURPOSE:	Return player y position or -1
		//INPUT:	NONE
		//OUTPUT:	Return mY if mCurrentAni is not in destroyed 
		//					-1 if mCurrentAni is in destroyed
		int getY();
		//PURPOSE:	Return player width or -1
		//INPUT:	NONE
		//OUTPUT:	Return mWidth if mCurrentAni is not in destroyed 
		//					-1 if mCurrentAni is in destroyed
		int getWidth();
		//PURPOSE:	Return player height or -1
		//INPUT:	NONE
		//OUTPUT:	Return mHeight if mCurrentAni is not in destroyed 
		//					-1 if mCurrentAni is in destroyed
		int getHeight();
		//PURPOSE: 	Returns the current type in mType
		//INPUT:	NONE
		//OUTPUT:	Return mType
		EnemyType getType();
	private:
		//PURPOSE:	The pointer to all the enemy types images
		BITMAP *mAllImages;
		//PURPOSE:	The utility object used to check collision between objects 
		CollisionDetection mCol;
		//PURPOSE:	Holds whether the object is currently active in the game
		bool mActive;
		//PURPOSE:	The type of enemy the object is
		EnemyType mType;
		//PURPOSE:	Pointer to the enemy object weapons
		EWeapon *mWeapon;
		//PURPOSE:	The direction for the asteroidmini as to whether it is right or not
		bool mRightDirection;
		//PURPOSE: 	Holds the difficulty level
		int mDifficultyMeter;
		//PURPOSE: 	Used by certain enemy type moved in the down direction
		int mDownDirection;
		//PURPOSE: 	Used by certain enemy type moved in the right or left direction
		int mRightorLeftDir;
		//PURPOSE: 	Used by certain enemy type moved in the up direction
		int mUpDir;
		//PURPOSE:	The width of the all images of acertain enemy type to be used to 
		//				extract out of the bitmap that contains all the enemy types 
		int mAllEnemyWidth;
		//PURPOSE:	The height of the all images of asteroid enemy type in the mAllImages to 
		//				extract out of the bitmap that contains all the enemy types 
		int mTypeAsteroidHeight;
		//PURPOSE:	The height of the all images of snake enemy type in the mAllImages to 
		//				extract out of the bitmap that contains all the enemy types 
		int mTypeSnakeHeight;
		//PURPOSE:	The height of the all images of step enemy type in the mAllImages to 
		//				extract out of the bitmap that contains all the enemy types 
		int mTypeStepHeight;
		//PURPOSE:	The height of the all images of reverse step enemy type in the mAllImages to 
		//				extract out of the bitmap that contains all the enemy types 
		int mTypeReverseStepHeight;
		//PURPOSE:	The height of the all images of zigzag enemy type in the mAllImages to 
		//				extract out of the bitmap that contains all the enemy types 
		int mTypeZigZagHeight;
		//PURPOSE:	The height of the all images of asteroidmini enemy type in the mAllImages to 
		//				extract out of the bitmap that contains all the enemy types 
		int mTypeAsteroidMiniHeight;
		//PURPOSE:	The height of the all images of kamikazerunner enemy type in the mAllImages to 
		//				extract out of the bitmap that contains all the enemy types 
		int mTypeKamikazeRunnerHeight;
		
		//PURPOSE:	Call the movement method depending on the type in mType
		//INPUT:	X			- Players X position
		//			Y			- Players Y position
		//OUTPUT: 	NONE
		void movement(int X, int Y); 
		//PURPOSE:	Sets mCurrentAni to the down state and calls parent class movedown method
		//INPUT:	NONE
		//OUTPUT: 	NONE
		void typeAsteroidMovement();
		//PURPOSE:	The snake type enemys movement(moves the enemy from one side of the screen then 
		//				down than to the other side and repeats)
		//INPUT:	NONE
		//OUTPUT: 	NONE
		void typeSnakeMovement();
		//PURPOSE:	The stair type enemys movement(moves the enemy in a stair type motion down)
		//INPUT:	NONE
		//OUTPUT: 	NONE
		void typeStepMovement();
		//PURPOSE:	The reversestair type enemys movement(moves the enemy in a stair type motion down
		//				except moves up half step after each step)
		//INPUT:	NONE
		//OUTPUT: 	NONE
		void typeReverseStepMovement();
		//PURPOSE:	The zigzag type enemys movement(moves the enemy in a zigzag pattern down the screen)
		//INPUT:	NONE
		//OUTPUT: 	NONE
		void typeZigZagMovement();
		//PURPOSE:	The asteroidmini type enemys movement(moves the enemy away from the spawn point in a 
		//				diagonal movement)
		//INPUT:	NONE
		//OUTPUT: 	NONE
		void typeAsteroidMiniMovement();
		//PURPOSE:	The kamikaze type enemys movement(depend on the range does different actions)
		//INPUT:	NONE
		//OUTPUT: 	NONE
		void typeKamikazeRunnerMovement(int X, int Y);
		
};

#endif
