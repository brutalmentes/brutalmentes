#include "object.h"


Object::Object(float x, float y)
{
    //Initialize the offsets
    this->mPosX = x;
    this->mPosY = y;

    //Initialize the velocity
    this->mVelX = 0;
    this->mVelY = 0;
}

void Object::setinitialspeed(float velx, float vely){
    this->mVelX = velx;
    this->mVelY = vely;
}

void Object::move_alone(float x, float y)
{

mPosY=y;
mPosX=x;


}

