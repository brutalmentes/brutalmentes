#ifndef OBJECT
#define OBJECT

class Object
{
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
        void move_alone(float ,float);
		//Shows the dot on the screen
		void render();

		void setinitialspeed(float,float);

    //private:
		//The X and Y offsets of the dot
		float mPosX, mPosY;

		//The velocity of the dot
		float mVelX, mVelY;
};

#endif
