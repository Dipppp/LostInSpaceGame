#ifndef EWEAPON_H
#define EWEAPON_H

#include "Weapon.h"
#include "EBullet.h"

//PURPOSE - The Class is the controller class for the different bullets of the enemys and 
//				uses the weapon class as a parent
class EWeapon : public Weapon {
	public:
		//PURPOSE: The different types of weapon
		enum EWeaponType{MachineGun = 0, CornerGun = 2, Missile = 3};
		
		//PURPOSE:	Sets the default values for the object variables
		//INPUT:	Screen 		- The pointer to game screen
		//			Image 		- The pointer to bitmap of all the weapon images
		//			SoundEffect	- The pointer to the sound effects
		//OUTPUT:	NONE
		EWeapon(BITMAP *Screen, BITMAP *Image, SoundEffects *SoundEffect);
		//PURPOSE:	NONE
		//INPUT:	NONE
		//OUTPUT:	NONE
		~EWeapon();
		//PURPOSE: 	Change the bullet reload max time to specified value
		//				if it is greater than 60
		//INPUT:	NewMax		- The new reload max time value
		//OUTPUT:	NONE
		void changeReloadMax(int NewMax);
		//PURPOSE:	Adjusts the weapons firing point to the bottom of enemy and calls
		//				parent class shoot method
		//INPUT:	X			- X position the enemy's at
		//			Y			- Y position the enemy's at
		//			Width		- Enemy's width
		//			Height		- Enemy's height
		//OUTPUT:	NONE
		void shoot(int X, int Y, int Width, int Height);
		//PURPOSE:	
		//INPUT:	
		//OUTPUT:	NONE
		void update(int X, int Y);
		//PURPOSE:	
		//INPUT:	
		//OUTPUT:	NONE
		void setWeaponType(EWeaponType Type);
		//PURPOSE: 	Returns if there is an active bullet
		//INPUT:	NONE
		//OUTPUT:	Return true if there is an actvie bullet
		//				false if there is no active bullet 
		bool getActive();
		private:
		//PURPOSE: 	An array to hold all the bullet objects
		EBullet **mEBullets;
};

#endif
