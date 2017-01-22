#ifndef BREAKABLEOBJECT_H
#define BREAKABLEOBJECT_H

#include "GameObject.h"

//PURPOSE - The Class is for the breakable object and uses the game object class as a parent
class BreakableObject : public GameObject {
	public:
		//PURPOSE:	The different types of breakable objects 
		enum BObjectType{Life = 0, MGPowerUp = 1, LPowerUp = 2, CGPowerUp = 3, SPowerUp = 4};
		//PURPOSE: 	Sets the default values for the object variables
		//INPUT:	Screen 		- The pointer to game screen
		//			Image 		- The pointer to bitmap of all the breakable object images
		//			SoundEffect	- The pointer to the sound effects	
		//OUTPUT:	NONE
		BreakableObject(BITMAP *Screen, BITMAP *Image, SoundEffects *SoundEffect);
		//PURPOSE: 	Free the mAllImage bitmap from memory
		//INPUT:	NONE
		//OUTPUT:	NONE
		~BreakableObject();
		//PURPOSE: 	Spawn the object to positon and breakable object type specified with the default values
		//				for the type and set mType to type
		//INPUT:	X			- The X position to spawn the object
		//			Y			- The Y position to spawn the object 
		//			Type		- The type the breakable object will be
		//OUTPUT:	NONE
		void spawn(int X, int Y, BObjectType Type);
		//PURPOSE: 	Sets the the position and speed of the object to be invalid and set mCurrentAni to 
		//				the destroyed state
		//INPUT:	NONE
		//OUTPUT:	NONE
		void hit();
		//PURPOSE: 	Update the objects animation and movement if the object is not destroyed
		//				and the out of bound condition and set mActive to false if mCurrentAni
		//				mPreviousAni and mDestroyedtimer is zero
		//INPUT:	NONE
		//OUTPUT:	NONE
		void update();
		//PURPOSE: 	Returns the state mActive is in
		//INPUT:	NONE
		//OUTPUT:	Return mActive
		bool getActive();
		//PURPOSE: 	Returns the current type in mType
		//INPUT:	NONE
		//OUTPUT:	Return mType
		BObjectType getType();
		//PURPOSE: 	Return object mX value
		//INPUT:	NONE
		//OUTPUT:	return mX
		int getX();
		//PURPOSE: 	Return object mY value
		//INPUT:	NONE
		//OUTPUT:	return mY
		int getY();
		//PURPOSE: 	Return object mWidth value
		//INPUT:	NONE
		//OUTPUT:	return mWidth
		int getWidth();
		//PURPOSE: 	Return object mHeight value
		//INPUT:	NONE
		//OUTPUT:	return mHeight
		int getHeight();
		
	private:
		//PURPOSE: The type of breakable object that object is currently
		BObjectType mType;
		//PURPOSE: Holds whether the object is currently active in the game
		bool mActive;
		//PURPOSE: Pointer to the image that holds all the breakable object images
		BITMAP *mAllImagePage;
		
		//PURPOSE:	Moves the object in the down direction
		//INPUT:	NONE
		//OUTPUT:	NONE
		void movement(); 
		//PURPOSE: 	Gets the breakable object type's images from the all images(mAllImagePage) and scales images down
		//				then sets it to mImagePage then call the parent class animate method
		//INPUT:	NONE
		//OUTPUT:	NONE
		void animate();
};

#endif
