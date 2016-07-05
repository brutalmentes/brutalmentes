#include "Object.h"

Object::Object(float x, float y)
{
    //Initialize the offsets
    this->mPosX = x;
    this->mPosY = y;

    //Initialize the velocity
    this->mVelY = 0;

    //Initialize the texture
    this->texture = new Texture(" res/img/newtonmaca.png", x, y);

    //Set collision list
    this->collisionList.push_back(Circle(x + 7, y + 7, 7));
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

    std::list<Circle>::iterator it = collisionList.begin();
    (*it).x = posX;
}

void Object::setPosY(float posY) 
{
    mPosY = posY;
    this->texture->setPosY(posY);

    std::list<Circle>::iterator it = collisionList.begin();
    (*it).y = posY;
}

float Object::getPosX() 
{
    return mPosX;
}

float Object::getPosY()
{
    return mPosY;
}

std::list<Circle> Object::getCollisionList()
{
    return this->collisionList;
}