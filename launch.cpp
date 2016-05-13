
#include <math.h>
#include "launch.h"
#include <stdio.h>

Launch::Launch()
{
}
Launch::Launch(float force, float ang)
 {
 this->force=force;
 this->ang=force;

 }

 void Launch::setAng(float angt)
 {ang=angt;}

float  Launch::getAng(void)
 {return ang;}

float Launch::getnextspeedx()
{   float v_x=0;


   v_x=this->force*cos(this->ang);

   return v_x;
}
float Launch::getnextspeedy(float v_y_ant,float acc_y, int t)
{   float v_y;


    v_y=v_y_ant-2*t;


   return v_y;
}
float Launch::getnextpositionx(float s_ant_x,float v_x,int t)
{

    float s_x;
    s_x=s_ant_x+v_x*t;
    s_ant_x=s_x;

 return s_x;

}

float Launch::getnextpositiony(float s_ant_y, float v_y,int t)
{
    float s_y;

    s_y=s_ant_y-v_y*t;
    s_ant_y=s_y;

 return s_y;
}





