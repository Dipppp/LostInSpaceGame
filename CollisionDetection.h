#ifndef COLLISIONDETECTION_H
#define COLLISIONDETECTION_H


//PURPOSE - The Class is for check collision
class CollisionDetection  {
	public:
		//PURPOSE:	NONE
		//INPUT:	NONE
		//OUTPUT:	NONE
		CollisionDetection();
		//PURPOSE:	NONE
		//INPUT:	NONE
		//OUTPUT:	NONE
		~CollisionDetection();
		//PURPOSE:	Checks if the value provide for the point are inside the
		//				values provide for the box
		//INPUT:	pointX		- The x position of the point to test
		//			pointY		- The y position of the point to test
		//			boxX		- The x position of the box to test
		//			boxY		- The y position of the box to test
		//			boxWidth	- The width of the box to test
		//			boxHeight	- The height of the box to test
		//OUTPUT:	Return true if point inside the box
		//					false if not
		bool pointToBox(int pointX, int pointY, int boxX, int boxY, int boxWidth, int boxHeight);
		//PURPOSE:	Check if two boxes overlap anywhere with values provide
		//INPUT:	boxX1		- The x position of the box1 to test
		//			boxY1		- The y position of the box1 to test
		//			boxWidth1	- The width of the box1 to test
		//			boxHeight1	- The height of the box1 to test
		//			boxX2		- The x position of the box2 to test
		//			boxY2		- The y position of the box2 to test
		//			boxWidth2	- The width of the box2 to test
		//			boxHeight2	- The height of the box2 to test
		//OUTPUT:	Return true if the boxes overlap any where
		//					false if not
		bool boxToBox(int boxX1, int boxY1, int boxWidth1, int boxHeight1, int boxX2, int boxY2, int boxWidth2, int boxHeight2);

};

#endif
