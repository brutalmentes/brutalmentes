#ifndef DOT_H
#define DOT_H

#include "share.h"

class Dot {
	public:
		static const int DOT_WIDTH = 20;
		static const int DOT_HEIGHT = 20;

		static const int DOT_VEL = 1;

		Dot();

		void handleEvent(SDL_Event& e);

		void move();

		void render(LTexture* gDotTexture, LTexture* backgroundTexture, SDL_Renderer *gRenderer);

		void setPosX(int posX);

		void setPosY(int posY);
	private:
		int mPosX, mPosY;

		int mVelX, mVelY;
};

#endif