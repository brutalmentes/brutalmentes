//Using SDL, SDL_image, standard IO, and strings
#include "lib/dot.h"
#include "lib/CollisionDetector.h"
#include "lib/LoadCollisionMap.h"
#include "lib/Renderer.h"
#include "lib/Character.h"
#include <unistd.h>

int main(int argc, char* args[]) {
	Renderer* renderer = new Renderer();
	bool quit = false;

	if(!renderer->init()) {
		printf( "Failed to initialize!\n" );
	} else {
		Character* c = new Character(new Texture("res/img/dot.bmp", 200, 200));
		renderer->addTexture(new Texture("res/img/waterlevel2.png", 0, 0));
		renderer->addTexture(c->getTexture());

		renderer->render();

		bool quit = false;

		SDL_Event e;

		LoadCollisionMap lcm;
		list<Circle> circlesList;
		circlesList = lcm.load();

		list<Circle> l;
		Circle c1(200,0,10);
		l.push_back(c1);

		CollisionDetector cd;
		int y = 0;

		while(!cd.hasCollision(circlesList, l)) {
			l.pop_back();
			y += 1;
			Circle c1(200,y,10);
			l.push_back(c1);
		}
		y -= 1;
		c->setPosX(200);
		c->setPosY(y);

		renderer->render();

		int mVelX = 0;
		int DOT_VEL = 1;

		while(!quit) {
			while(SDL_PollEvent(&e) != 0) {
				if(e.type == SDL_QUIT) {
					quit = true;
				}
				if(e.type == SDL_KEYDOWN && e.key.repeat == 0) {
					switch(e.key.keysym.sym) {
						case SDLK_LEFT: mVelX -= DOT_VEL; break;
						case SDLK_RIGHT: mVelX += DOT_VEL; break;
					}
				} else if(e.type == SDL_KEYUP && e.key.repeat == 0) {
					switch(e.key.keysym.sym) {
						case SDLK_LEFT: mVelX += DOT_VEL; break;
						case SDLK_RIGHT: mVelX -= DOT_VEL; break;
					}
				}
			}
			c->setPosX(c->getPosX() + mVelX);


			LoadCollisionMap lcm;
			list<Circle> circlesList;
			circlesList = lcm.load();

			int mPosX = c->getPosX();
			int mPosY = c->getPosY();

			list<Circle> l;
			Circle c1(mPosX,mPosY,10);
			l.push_back(c1);

			CollisionDetector cd;
			int y = mPosY;
			while(cd.hasCollision(circlesList, l)) {
				l.pop_back();
				y -= 1;
				Circle c1(mPosX,y,10);
				l.push_back(c1);
			};
			while(!cd.hasCollision(circlesList, l)) {
				l.pop_back();
				y += 1;
				Circle c1(mPosX,y,10);
				l.push_back(c1);
			};

			c->setPosY(y);

			renderer->render();
		}
	}
	return 0;
}