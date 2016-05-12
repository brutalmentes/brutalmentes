#include "cenario.h"
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
 	float getnextspeedx();
 	float getnextspeedy(float ,float , int );
 	float getnextpositionx(float ,float ,int );
 	float getnextpositiony(float , float ,int );
};
