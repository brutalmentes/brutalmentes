#ifndef LAUNCH
#define LAUNCH

class Launch
 {
   private:
   	float force;
   	float ang;
   	//Cenario cenario;

   public:
	Launch();
 	Launch(float , float  );
	void setAng(float );
 	float  getAng(void);
 	float getForce();
 	float initialspeedy();
 	float getnextspeedx();
 	float getnextspeedy(float ,float , float );
 	float getnextpositionx(float ,float ,float );
 	float getnextpositiony(float , float ,float );
};

#endif
