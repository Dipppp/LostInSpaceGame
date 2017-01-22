#ifndef SPECIALBULLET_H
#define SPECIALBULLET_H

#include "Bullet.h"
//PURPOSE - The Class for the special weapon bullet and uses the bullet class as a parent
class SpecialBullet : protected Bullet {
	public:
		//PURPOSE:	Sets the default values for the object variables
		//INPUT:	Screen 		- The pointer to game screen
		//			Image 		- The pointer to bitmap of all the braekable object images
		//OUTPUT:	NONE
		SpecialBullet(BITMAP *Screen, BITMAP *Image);
		//PURPOSE:	NONE
		//INPUT:	NONE
		//OUTPUT:	NONE
		~SpecialBullet();
		//PURPOSE:	Updates the bullets movement and check the out bound condition and call the animate method
		//INPUT:	NONE
		//OUTPUT:	NONE
		void update();
		//PURPOSE:	Calls parent class draw
		//INPUT:	NONE
		//OUTPUT:	NONE
		void draw();
		//PURPOSE:	Fired the bullet by setting the position
		//				and set mActive to true and resets the bullet animation
		//INPUT:	StartX		- The bullets start X position
		//			StartY		- The bullets start Y position
		//OUTPUT:	NONE
		void fired(int StartX, int StartY);
		//PURPOSE:	Return whether bullet has exploded
		//INPUT:	NONE
		//OUTPUT:	Returns mExplode
		bool getExplode();
		//PURPOSE: 	Returns the parent state mActive is in
		//INPUT:	NONE
		//OUTPUT:	Return parent's mActive
		bool getActive();
	private:
		bool mExplode;
};


#endif
