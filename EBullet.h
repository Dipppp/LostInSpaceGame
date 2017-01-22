#ifndef EBULLET_H
#define EBULLET_H

#include "Bullet.h"
//PURPOSE - The Class for the enemy bullet and uses the bullet class as a parent
class EBullet : public Bullet {
	public:
		//PURPOSE:	Sets the default values for the object variables
		//INPUT:	Screen 		- The pointer to game screen
		//			Image 		- The pointer to bitmap of all the braekable object images
		//OUTPUT:	NONE
		EBullet(BITMAP *Screen, BITMAP *Image);
		//PURPOSE:	NONE
		//INPUT:	NONE
		//OUTPUT:	NONE
		~EBullet();
		//PURPOSE:	
		//INPUT:	NONE
		//OUTPUT:	NONE
		void update(int X, int Y);
		//PURPOSE:	
		//INPUT:	
		//OUTPUT:	NONE
		void fired(int StartX, int StartY, int SpeedX, int SpeedY);			

	private:
		//PURPOSE:	Grabs the next image from mImagePage for the bullet and sets it to
		//			mCurImage
		//INPUT:	NONE
		//OUTPUT:	NONE
		void animate();
};


#endif
