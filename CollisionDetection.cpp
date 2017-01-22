#include "CollisionDetection.h"

CollisionDetection::CollisionDetection(){
	
}

CollisionDetection::~CollisionDetection(){
	
}

bool CollisionDetection::pointToBox(int pointX, int pointY, int boxX, int boxY, int boxWidth, int boxHeight){
	return (pointX > boxX && pointX < (boxX+boxWidth) && pointY > boxY && pointY < (boxY+boxHeight))
		&&(boxX != -1 && boxY != -1 &&boxWidth != -1 &&boxHeight != -1 && pointX != -1 && pointY != -1);
}

bool CollisionDetection::boxToBox(int boxX1, int boxY1, int boxWidth1, int boxHeight1, int boxX2, int boxY2, int boxWidth2, int boxHeight2){
	return (boxX1 < (boxX2+boxWidth2) && (boxX1+boxWidth1) > boxX2 && boxY1 < (boxY2+boxHeight2) && (boxY1+boxHeight1) > boxY2) 
		&&(boxX1 != -1 && boxY1 != -1 && boxWidth1 != -1 && boxHeight1 != -1 && boxX2 != -1 && boxY2 != -1 && boxWidth2 != -1 && boxHeight2  != -1);
}
