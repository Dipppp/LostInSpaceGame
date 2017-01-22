#include "BaseInterface.h"

BaseInterface::BaseInterface(){
}

BaseInterface::~BaseInterface(){
	destroy_bitmap(mBackgroundImage);
}

void BaseInterface::draw(){
	blit(mBackgroundImage,mScreen,0,0,0,0,mBackgroundWidth,mBackgroundHeight);
}
