#include "cenario.cpp"
#include <math.h>
class Launch
 {
   private:
   float force;
   float ang;
   Cenario cenario;

   public:


Launch(float force, float ang, Cenario cenario)
 {
 this->force=force;
 this->ang=force;
 this->cenario=cenario;

 }

 void setAng(float angt)
 {ang=angt;}

float  getAng(void)
 {return ang;}

float getnextspeedx(float force,float ang)
{   float v_x;


    v_x=force*cos(ang);


   return v_x;
}
float getnextspeedy(float v_y_ant,float acc_y, int t)
{   float v_y;


    v_y=v_y_ant-2*t;


   return v_y;
}
float getnextpositionx(float s_ant_x,float v_x,int t)
{

    float s_x;
    s_x=s_ant_x+v_x*t;
    s_ant_x=s_x;

 return s_x;

}

float getnextpositiony(float s_ant_y, float v_y,int t)
{
    float s_y;

    s_y=s_ant_y-v_y*t;
    s_ant_y=s_y;

 return s_y;
}

};



