#ifndef OBJECT
#define OBJECT

#include "Texture.h"
#include "Circle.h"
#include <list>

class Object
{
	private:
		Texture *texture;
		//The X and Y offsets of the dot
		float mPosX, mPosY;

		std::list<Circle> collisionList;
    public:
		//The dimensions of the dot
		static const int DOT_WIDTH = 20;
		static const int DOT_HEIGHT = 20;

		//Maximum axis velocity of the dot
		static const int DOT_VEL = 10;

		//Initializes the variables
		Object(float,float);

		//Takes key presses and adjusts the dot's velocity

		//Moves the dot
        void moveAlone(float ,float);
		//Shows the dot on the screen
		void render();

		void setInitialSpeed(float,float);

    	void setPosX(float posX);
    	void setPosY(float posY);

    	float getPosX();
    	float getPosY();

    	std::list<Circle> getCollisionList();
		
		//The velocity of the dot
		float mVelX, mVelY;

		Texture* getTexture();
};

#endif
