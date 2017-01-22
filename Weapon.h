#ifndef WEAPON_H
#define WEAPON_H

#include "GameObject.h"
#include "Bullet.h"
#include "SpecialBullet.h"
#include "CollisionDetection.h"

//PURPOSE - The Class is the controller class for the different bullets and 
//				uses the game object class as a parent
class Weapon : public GameObject {
	public:
		//PURPOSE: The different types of weapon
		enum WeaponType{MachineGun = 0, Laser = 1, CornerGun = 2, NonStandardType = 3};
		
		//PURPOSE:	Sets the default values for the object variables
		//INPUT:	Screen 		- The pointer to game screen
		//			Image 		- The pointer to bitmap of all the weapon images
		//			SoundEffect	- The pointer to the sound effects
		//OUTPUT:	NONE
		Weapon(BITMAP *Screen, BITMAP *Image, SoundEffects *SoundEffect);
		//PURPOSE:	Free memory of the bullet pointers array
		//INPUT:	NONE
		//OUTPUT:	NONE
		~Weapon();
		//PURPOSE:	Fires the weapon for the type of weapon indicated in mType and
		//				if mReloadTime is equal to zero  
		//INPUT:	X			- Firing objects x position
		//			Y			- Firing objects y position
		//			Width		- Firing objects width
		//			Height		- Firing objects height
		//OUTPUT:	NONE
		void shoot(int X, int Y, int Width, int Height);
		//PURPOSE:	Fires the weapon for the special bomb  
		//INPUT:	X			- Firing objects x position
		//			Y			- Firing objects y position
		//OUTPUT:	NONE
		void shootSpecial(int X, int Y);
		//PURPOSE:	Changes the mType to the new weapon type provide and reset the weapon level to 1 
		//				if the new weapon type is the same as the old one then call the private method levelUpWeapon
		//INPUT:	NewWeaponType - The weapon type that mType is to change too
		//OUTPUT:	NONE
		void changeWeaponType(WeaponType NewWeaponType);
		//PURPOSE:	Updates all active bullet, decrements mReloadTime if greater then zero, decrements mLaserChargeTime 
		//				if greater then zero and decrement mLaserBulletCount if mLaserBulletCount greater than zero and
		//				mLaserChargeTime is equal to zero
		//INPUT:	NONE
		//OUTPUT:	NONE
		void update();
		//PURPOSE:	Draws all active bullets
		//INPUT:	NONE
		//OUTPUT:	NONE
		void draw();
		//PURPOSE:	Deactives all the bullets
		//INPUT:	NONE
		//OUTPUT:	NONE		
		void deactive();
		//PURPOSE:	Increase special weapon charge
		//INPUT:	NONE
		//OUTPUT:	NONE
		void increaseSpecialWeapon();
		//PURPOSE:	Check if the box provide through the values collides with a  active bullet then return the result
		//INPUT:	X			- The x position of the box to check against
		//			Y			- The y position of the box to check against
		//			Width		- The width of the box to check against
		//			Height		- The height of the box to check against
		//OUTPUT:	Return true if there is a collision
		//					false if no collision
		bool checkHit(int X, int Y, int Width, int Height);
		//PURPOSE:	Return where the special wepaon explode
		//INPUT:	NONE
		//OUTPUT:	Return true if explode
		//				false if not
		bool getSpecialExplosion();
		//PURPOSE:	Return the number of charges that special weapon has
		//INPUT:	NONE
		//OUTPUT:	Return mSpecialCharge
		int getSpecialCharge();
	protected:
		//PURPOSE: 	An array to hold all the bullet objects
		Bullet **mBullets;
		//PURPOSE: 	An array to hold all the special bullet objects
		SpecialBullet **mSpecialBullets;
		//PURPOSE: 	The current type of weapon that the object should be
		WeaponType mWeaponType;
		//PURPOSE: 	The total number of bullets objects in the array
		int mTotalBullets;
		//PURPOSE: 	The total number of special bullets objects in the array
		int mTotalSpecialBullets;
		//PURPOSE: 	Hold the delay time between firing
		int mSpecialBulletDelay;
		//PURPOSE: 	Hold the max delay time between firing
		int mSpecialBulletDelayMax;
		//PURPOSE: Holds the number of charges the special weapon has
		int mSpecialCharge;
		//PURPOSE: 	The speed which the bullets should move
		int mBulletSpeed;
		//PURPOSE: 	The laser movement speed
		int mLaserSpeed;
		//PURPOSE: 	The direction the bullets should travel 
		//				1 for down
		//				-1 for up
		int mBulletDir;
		//PURPOSE:	 The level that the weapon is currently in
		int mWeaponLevel;
		//PURPOSE: 	The time it takes to reload the weapon
		int mReloadTime;
		//PURPOSE: 	The max reload time it takes for the machine and corner gun types
		int mMachineAndCornerReloadTimeMax;
		//PURPOSE: 	The max reload time for the laser type weapon
		int mLaserReloadTimeMax;
		//PURPOSE: 	The charge timer for the laser bullets
		int mLaserChargeTime;
		//PURPOSE: 	The count of bullets that the laser can use
		int mLaserBulletCount;
		//PURPOSE: 	The utility object used to check collision between objects 
		CollisionDetection mCol;
		
		//PURPOSE: 	Increase mWeaponLevel if it is less then 3
		//INPUT:	NONE
		//OUTPUT:	NONE
		void levelUpWeapon();
		//PURPOSE:	Depend on the weapon level fires one, two, or three inactive bullets in the 
		//				direction given by mBulletDir in parallel
		//INPUT:	X			- The x position of the object firing the weapon
		//			Y			- The y position of the object firing the weapon
		//			Width		- The width of the object firing the weapon
		//			Height		- The height of the object firing the weapon
		//OUTPUT:	NONE
		void machineGunShoot(int X, int Y, int Width, int Height);
		//PURPOSE:	Depend on the weapon level fires the laser for the specified number inactive
		//				laser bullets for the amount charged
		//INPUT:	X			- The x position of the object firing the weapon
		//			Y			- The y position of the object firing the weapon
		//			Width		- The width of the object firing the weapon
		//			Height		- The height of the object firing the weapon
		//OUTPUT:	NONE
		void laserShoot(int X, int Y, int Width, int Height);
		//PURPOSE:	Depend on the weapon level fires one, two, or three inactive bullets in the 
		//				direction given by mBulletDir in one in a straight line and two in a diagonal
		//				line to opposite sides
		///INPUT:	X			- The x position of the object firing the weapon
		//			Y			- The y position of the object firing the weapon
		//			Width		- The width of the object firing the weapon
		//			Height		- The height of the object firing the weapon
		//OUTPUT:	NONE
		void cornerGunShoot(int X, int Y, int Width, int Height);
};

#endif
