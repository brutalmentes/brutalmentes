#include "Object.h"

Object::Object(float x, float y)
{
    //Initialize the offsets
    this->mPosX = x;
    this->mPosY = y;

    //Initialize the velocity
    this->mVelX = 0;
    this->mVelY = 0;
}

void Object::setInitialSpeed(float velx, float vely){
    this->mVelX = velx;
    this->mVelY = vely;
}

void Object::moveAlone(float x, float y)
{
	mPosY = y;
	mPosX = x;
}

