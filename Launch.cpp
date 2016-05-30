
#include <math.h>
#include "launch.h"
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
   float v_y;
   v_y=this->force*sin(this->ang);
   return v_y;
 }


float Launch::getNextSpeedX()
{   
	float v_x=0;
	v_x=this->force*cos(this->ang);
	return v_x;
}

float Launch::getNextSpeedY(float v_y_ant, float acc_y, float t)
{   
	float v_y;
	v_y=v_y_ant+acc_y*t;
	return v_y;
}

float Launch::getNextPositionX(float s_ant_x, float v_x, float t)
{
    float s_x;
    s_x=s_ant_x+v_x*t;
	return s_x;
}

float Launch::getNextPositionY(float s_ant_y, float v_y, float t)
{
    float s_y;
    s_y=s_ant_y+v_y*t;
	return s_y;
}

float Launch::getForce()
{
	return this->force;
}




