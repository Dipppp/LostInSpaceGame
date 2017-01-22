#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <allegro.h>

#include "SoundEffects.h"

//PURPOSE - The Class is the base class for all game objects
class GameObject {
	public:
		//PURPOSE: 	Sets all variables to default setting for the object
		//INPUT:	NONE
		//OUTPUT:	NONE
		GameObject();
		//PURPOSE:	Free the mCurImage bitmap from memory
		//INPUT:	NONE
		//OUTPUT:	NONE
		~GameObject();
		//PURPOSE:	Draw the objects sprite to the buffer use the picture/image in mCurImage bitmap
		//INPUT:	NONE
		//OUTPUT:	NONE
		void draw();
		
	private:
	protected:
		//PURPOSE:	The different states that the object's animation can be in
		enum AnimateType{Neutral = 0, Up = 1, Right = 2, Down = 3, Left = 4, UpRight = 5, DownRight = 6, UpLeft = 7, DownLeft = 8, Destroyed = 9};
		//PURPOSE:	The previous and current state that objects animation is in
		AnimateType mPreviousAni, mCurrentAni;
		//PURPOSE:	The X, Y position and the Width, Height and Speed of the object
		int mX, mY;
		int mWidth, mHeight;
		int mXSpeed, mYSpeed;
		//PURPOSE:	The current frame in the animation sequence that the object is in
		int mCurFrame;
		//PURPOSE:	The max frame for the different states of the animation for the object
		int mNeutralFrameMax, mUpFrameMax, mRightFrameMax, mDownFrameMax, mLeftFrameMax;
		int mUpRightFrameMax, mDownRightFrameMax, mUpLeftFrameMax, mDownLeftFrameMax, mDestroyedFrameMax;
		//PURPOSE:	The frame count and frame delay is the delay before an animation change occurs
		int mFrameCount, mFrameDelay;
		//PURPOSE:	The number of frames for animation in the rows for each state in the bitmap of all the images
		int mNeutralFrameRow, mUpFrameRow, mRightFrameRow, mDownFrameRow, mLeftFrameRow;
		int mUpRightFrameRow, mDownRightFrameRow, mUpLeftFrameRow, mDownLeftFrameRow, mDestroyedFrameRow;
		//PURPOSE:	The delay for the object after the object been destroyed
		int mDestroyedTimer;
		//PURPOSE:	The pointer to the bitmap that is the game screen and what everything is drawn on
		BITMAP *mScreen;
		//PURPOSE:	The current image of the object to draw
		BITMAP *mCurImage;
		//PURPOSE:	The image that holds all the images for all the animation states
		BITMAP *mImagePage;
		//PURPOSE: The pointer to the sound effects
		SoundEffects *mSoundEffects;
		
		//PURPOSE:	Decreases the mDestroyedTimer if mCurrentAni and mPreviousAni 
		//				is in the destroyed state and if mDestroyedTimer is greater 
		//				than zero
		//INPUT:	NONE
		//OUTPUT:	NONE
		void update();
		//PURPOSE:	Decrease the mY by mYSpeed
		//INPUT:	NONE
		//OUTPUT:	NONE
		void moveUp();
		//PURPOSE:	Increase the mY by mYSpeed
		//INPUT:	NONE
		//OUTPUT:	NONE
		void moveDown();
		//PURPOSE:	Increase the mX by mXSpeed
		//INPUT:	NONE
		//OUTPUT:	NONE
		void moveRight();
		//PURPOSE:	Decrease the mX by mXSpeed
		//INPUT:	NONE
		//OUTPUT:	NONE
		void moveLeft();
		//PURPOSE:	Decrease the mY by mYSpeed and increase the mX by mXSpeed
		//INPUT:	NONE
		//OUTPUT:	NONE
		void moveUpRight();
		//PURPOSE:	Increase the mY by mYSpeed and increase the mX by mXSpeed
		//INPUT:	NONE
		//OUTPUT:	NONE
		void moveDownRight();
		//PURPOSE:	Decrease the mY by mYSpeed and decrease the mX by mXSpeed
		//INPUT:	NONE
		//OUTPUT:	NONE
		void moveUpLeft();
		//PURPOSE:	Increase the mY by mYSpeed and decrease the mX by mXSpeed
		//INPUT:	NONE
		//OUTPUT:	NONE
		void moveDownLeft();
		//PURPOSE:	Grabs the next image from mImagePage for the current animate state and sets it 
		//				to the mCurImage depending on if mFrameCount greater than mFrameDelay or 
		//				if mPreviousAni is not equal mCurrentAni and reset mFrameCount to zero
		//				and sets mPreviousAni to mCurrentAni
		//INPUT:	NONE
		//OUTPUT:	NONE
		void animate();
};

#endif
