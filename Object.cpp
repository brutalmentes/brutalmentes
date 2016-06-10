#include "Object.h"

Object::Object(float posX, float posY)
{
    //Initialize the offsets
    this->mPosX = posX;
    this->mPosY = posY;

    //Initialize the velocity
    this->mVelX = 0;
    this->mVelY = 0;
}

void Object::setInitialSpeed(float velX, float velY)
{
    this->mVelX = velX;
    this->mVelY = velY;
}

void Object::moveAlone(float posX, float posY)
{
	mPosY = posY;
	mPosX = posX;
}

