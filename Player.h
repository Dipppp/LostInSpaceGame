#ifndef PLAYER_H
#define PLAYER_H

#include "GameObject.h"
#include "Weapon.h"

//PURPOSE - The Class is for the players object and uses the game object class as a parent
class Player : public GameObject {
	public:
		//PURPOSE: 	Sets the default values for the object variables
		//INPUT:	Screen 		- The pointer to game screen
		//			Image 		- The pointer to bitmap of all the player images
		//			WeaponImage	- The pointer to bitmap of all the weapons image
		//			SoundEffect	- The pointer to the sound effects	
		//OUTPUT:	NONE
		Player(BITMAP *Screen, BITMAP *Image, BITMAP *WeaponImage, SoundEffects *SoundEffect);
		//PURPOSE:	Free mWeapon from memory
		//INPUT:	NONE
		//OUTPUT:	NONE
		~Player();
		//PURPOSE:	If the mY-mYSpeed is not out of bounds and mCurrentAni is not in destroyed state
		//				call parent class's move up method and sets mCurrentAni to up state
		//INPUT:	NONE
		//OUTPUT:	NONE
		void moveUp();
		//PURPOSE:	If the mY+mYSpeed is not out of bounds and mCurrentAni is not in destroyed state
		//				call parent class's move down method and sets mCurrentAni to down state
		//INPUT:	NONE
		//OUTPUT:	NONE
		void moveDown();
		//PURPOSE:	If the mX+mXSpeed is not out of bounds and mCurrentAni is not in destroyed state
		//				call parent class's move right method and sets mCurrentAni to right state
		//INPUT:	NONE
		//OUTPUT:	NONE
		void moveRight();
		///PURPOSE:	If the mX-mXSpeed is not out of bounds and mCurrentAni is not in destroyed state
		//				call parent class's move left method and sets mCurrentAni to left state
		//INPUT:	NONE
		//OUTPUT:	NONE
		void moveLeft();
		//PURPOSE:	If the mY-mYSpeed and mX+mXSpeed is not out of bounds and mCurrentAni is not 
		//				in destroyed state call parent class's move up right method and sets 
		//				mCurrentAni to up right state
		//INPUT:	NONE
		//OUTPUT:	NONE
		void moveUpRight();
		//PURPOSE:	If the mY+mYSpeed and mX+mXSpeed is not out of bounds and mCurrentAni is not 
		//				in destroyed state call parent class's move down right method and sets 
		//				mCurrentAni to down right state
		//INPUT:	NONE
		//OUTPUT:	NONE
		void moveDownRight();
		//PURPOSE:	If the mY-mYSpeed and mX-mXSpeed is not out of bounds and mCurrentAni is not 
		//				in destroyed state call parent class's move up left method and sets 
		//				mCurrentAni to up left state
		//INPUT:	NONE
		//OUTPUT:	NONE
		void moveUpLeft();
		//PURPOSE:	If the mY+mYSpeed and mX-mXSpeed is not out of bounds and mCurrentAni is not 
		//				in destroyed state call parent class's move down left method and sets 
		//				mCurrentAni to down left state
		//INPUT:	NONE
		//OUTPUT:	NONE
		void moveDownLeft();
		//PURPOSE:	If mCurrent is not in destroyed state sets mCurrent to neutral state
		//INPUT:	NONE
		//OUTPUT:	NONE
		void moveNeutral();
		//PURPOSE: 	Sets mCurrent to destroyed state
		//INPUT:	NONE
		//OUTPUT:	NONE
		void destroyed();
		//PURPOSE: 	If mCurrentAni not in destroyed state then fires the weapon
		//INPUT:	NONE
		//OUTPUT:	NONE
		void fireWeapon();
		//PURPOSE: 	If mCurrentAni not in destroyed state and mSpecialCharge is greater than 0
		//				then fires the special weapon
		//INPUT:	NONE
		//OUTPUT:	NONE
		void fireSpecialWeapon();
		//PURPOSE:	Upgrades weapon to the type provide
		//INPUT:	Type		- The type of the weapon upgrade wanted
		//OUTPUT:	NONE
		void weaponUpgrade(Weapon::WeaponType Type);
		//PURPOSE:	Update the player data 
		//INPUT:	NONE
		//OUTPUT:	NONE
		void update();
		//PURPOSE:	Calls parent class draw method and draws weapon
		//INPUT:	NONE
		//OUTPUT:	NONE
		void draw();
		//PURPOSE:	Resets player
		//INPUT:	NONE
		//OUTPUT:	NONE
		void reset();
		//PURPOSE:	Increase special weapon charge
		//INPUT:	NONE
		//OUTPUT:	NONE
		void increaseSpecialWeapon();
		//PURPOSE:	Return player x position or -1
		//INPUT:	NONE
		//OUTPUT:	Return mX if mCurrentAni is not in destroyed and mReviveSavedTimer equal 0
		//					-1 if mCurrentAni is in destroyed and mReviveSavedTimer is not equal 0
		int getX();
		//PURPOSE:	Return player y position or -1
		//INPUT:	NONE
		//OUTPUT:	Return mY if mCurrentAni is not in destroyed and mReviveSavedTimer equal 0
		//					-1 if mCurrentAni is in destroyed and mReviveSavedTimer is not equal 0
		int getY();
		//PURPOSE:	Return player width or -1
		//INPUT:	NONE
		//OUTPUT:	Return mWidth if mCurrentAni is not in destroyed and mReviveSavedTimer equal 0
		//					-1 if mCurrentAni is in destroyed and mReviveSavedTimer is not equal 0
		int getWidth();
		//PURPOSE:	Return player height or -1
		//INPUT:	NONE
		//OUTPUT:	Return mHeight if mCurrentAni is not in destroyed and mReviveSavedTimer equal 0
		//					-1 if mCurrentAni is in destroyed and mReviveSavedTimer is not equal 0
		int getHeight();
		//PURPOSE:	Return's player's special weapon number of charges left
		//INPUT:	NONE
		//OUTPUT:	Return special weapon charges
		int getSpecialWeaponCharges();
		//PURPOSE:	Check if the box provide through the values collides with a bullet from the weapon
		//				then return the result
		//INPUT:	X			- The x position of the box to check against
		//			Y			- The y position of the box to check against
		//			Width		- The width of the box to check against
		//			Height		- The height of the box to check against
		//OUTPUT:	Return true if there is a collision
		//					false if no collision
		bool checkHitWithBullet(int X, int Y, int Width, int Height);
		//PURPOSE:	Returns if the special weapon explodes
		//INPUT:	NONE
		//OUTPUT:	Return special weapon explode
		bool specialWeaponExplode();
		
	private:
		//PURPOSE: Pointer to the weapon object that house the player's weapons
		Weapon *mWeapon;
		//PURPOSE: The timer for how long the player is immune to the enemy after being 
		//				revived
		int mReviveSavedTimer;
		//PURPOSE: The timer for when to flicker players image
		int mFlickerTimer;
		
		
		//PURPOSE:	Counts down player immunity from enemys and cause player image to
		//				flicker 
		//INPUT:	NONE
		//OUTPUT:	NONE
		void reviveCounter();
};

#endif
