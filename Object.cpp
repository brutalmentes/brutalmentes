#include "Object.h"

Object::Object(float x, float y)
{
    //Initialize the offsets
    this->mPosX = x;
    this->mPosY = y;

    //Initialize the velocity
    this->mVelX = 0;
    this->mVelY = 0;

    //Initialize the texture
    this->texture = new Texture("res/img/newtonmaca.png", x, y);
}

void Object::setInitialSpeed(float velx, float vely)
{
    this->mVelX = velx;
    this->mVelY = vely;
}

void Object::moveAlone(float x, float y)
{
	mPosY = y;
	mPosX = x;
}

Texture* Object::getTexture()
{
    return texture;
}

void Object::setPosX(float posX) 
{
    mPosX = posX;
    this->texture->setPosX(posX);
}

void Object::setPosY(float posY) 
{
    mPosY = posY;
    this->texture->setPosY(posY);
}

float Object::getPosX() 
{
    return mPosX;
}

float Object::getPosY()
{
    return mPosY;
}