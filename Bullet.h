#ifndef BULLET_H
#define BULLET_H

#include "GameObject.h"


//PURPOSE - The Class for all the bullet types objects and uses the game object class as a parent
class Bullet : public GameObject {
	public:
		//PURPOSE:	The different types of bullets
		enum BulletType{MachineGunBullet = 0, LaserBeam = 1, CornerGunBullet = 2, NonStandardType = 3};
		//PURPOSE:	Sets the default values for the object variables
		//INPUT:	Screen 		- The pointer to game screen
		//			Image 		- The pointer to bitmap of all the braekable object images
		//OUTPUT:	NONE
		Bullet(BITMAP *Screen, BITMAP *Image);
		//PURPOSE:	NONE
		//INPUT:	NONE
		//OUTPUT:	NONE
		~Bullet();
		//PURPOSE:	Fired the bullet by setting the position, speed and type to the specified values
		//				and set mActive to true and resets the bullet animation
		//INPUT:	StartX		- The bullets start X position
		//			StartY		- The bullets start Y position
		//			SpeedX		- The bullets X speed
		//			SpeedY		- The bullets Y speed
		//			Type		- The type the bullet will be
		//OUTPUT:	NONE
		void fired(int StartX, int StartY, int SpeedX, int SpeedY, BulletType Type);
		//PURPOSE:	Sets the the position and speed of the object to be invalid and set mActive to 
		//				false
		//INPUT:	NONE
		//OUTPUT:	NONE
		void hit();
		//PURPOSE:	Updates the bullets movement and check the out bound condition and call the animate method
		//INPUT:	NONE
		//OUTPUT:	NONE
		void update();
		//PURPOSE: 	Returns the state mActive is in
		//INPUT:	NONE
		//OUTPUT:	Return mActive
		bool getActive();
		//PURPOSE: 	Returns the mX value
		//INPUT:	NONE
		//OUTPUT:	Return mX
		int getX();
		//PURPOSE: 	Returns the mY value
		//INPUT:	NONE
		//OUTPUT:	Return mY
		int getY();
		//PURPOSE: 	Returns the mWidth value
		//INPUT:	NONE
		//OUTPUT:	Return mWidth
		int getWidth();
		//PURPOSE: 	Returns the mHeight value
		//INPUT:	NONE
		//OUTPUT:	Return mHeight
		int getHeight();
		
	protected:
		//PURPOSE: 	The type of bullet the object is
		BulletType mType;
		//PURPOSE: 	The max number of frames for bullet animation
		int mFrameMax;
		//PURPOSE: 	Holds whether the object is currently active in the game
		bool mActive;
		
		//PURPOSE:	Grabs the next image from mImagePage for the bullet and sets it to
		//			mCurImage
		//INPUT:	NONE
		//OUTPUT:	NONE
		void animate();
};

#endif
