#include "object.h"


Object::Object(float x, float y)
{
    //Initialize the offsets
    mPosX = 0;
    mPosY = 300;

    //Initialize the velocity
    mVelX = 0;
    mVelY = 0;
}
void Object::move_alone(float x, float y)
{

mPosY=y;
mPosX=x;


}

