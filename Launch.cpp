
#include <math.h>
#include "Launch.h"
#include <stdio.h>

Launch::Launch()
{
}

Launch::Launch(float force, float ang)
 {
    this->force=force;
    this->ang=ang;
 }

 void Launch::setAng(float angt)
 {ang=angt;}

float  Launch::getAng(void)
 {return ang;}

 float Launch::initialSpeedY()
 {
   return this->force*sin(this->ang);
 }


float Launch::getNextSpeedX()
{   
	return this->force*cos(this->ang);
}

float Launch::getNextSpeedY(float v_y_ant, float acc_y, float dt)
{   
	return v_y_ant - acc_y*dt;
}

float Launch::getNextPositionX(float s_ant_x, float v_x, float dt)
{
	return s_ant_x + v_x*dt;
}

float Launch::getNextPositionY(float s_ant_y, float v_y, float dt)
{
	return s_ant_y + v_y*dt;
}

float Launch::getForce()
{
	return this->force;
}




