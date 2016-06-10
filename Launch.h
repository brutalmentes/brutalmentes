#ifndef LAUNCH
#define LAUNCH

class Launch
 {
   private:
   	float force;
   	float ang;

   public:
	Launch();
 	Launch(float force, float  angle);
	void setAng(float );
 	float getAng(void);
 	float getForce();
 	float initialSpeedY();
 	float getNextSpeedX();
 	float getNextSpeedY(float ,float , float);
 	float getNextPositionX(float ,float, float);
 	float getNextPositionY(float , float, float);
};

#endif
