//Using SDL, SDL_image, standard IO, and strings
#include "lib/ltexture.h"
#include "lib/dot.h"
#include "lib/CollisionDetector.h"
#include "lib/LoadCollisionMap.h"

SDL_Renderer* gRenderer = NULL;

bool init();

bool loadMedia();

void close();

SDL_Window* gWindow = NULL;

LTexture gDotTexture;
LTexture backgroundTexture;

bool init() {
	bool success = true;

	if(SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	} else {
		if(!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
			printf( "Warning: Linear texture filtering not enabled!" );
		}

		gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if(gWindow == NULL) {
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		} else {
			gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
			if(gRenderer == NULL) {
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
				success = false;
			} else {
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
				int imgFlags = IMG_INIT_PNG;
				if(!(IMG_Init( imgFlags ) & imgFlags)) {
					printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
					success = false;
				}
			}
		}
	}

	return success;
}

bool loadMedia() {
	//Loading success flag
	bool success = true;

	//Load dot texture
	if(!gDotTexture.loadFromFile("dot.bmp", gRenderer)) {
		printf( "Failed to load dot texture!\n" );
		success = false;
	}

	if(!backgroundTexture.loadFromFile("waterlevel2.png", gRenderer)) {
		printf( "Failed to load dot texture!\n" );
		success = false;
	}

	return success;
}

void close() {
	gDotTexture.free();

	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	gRenderer = NULL;

	IMG_Quit();
	SDL_Quit();
}

int main( int argc, char* args[] ) {

	if(!init()) {
		printf( "Failed to initialize!\n" );
	} else {
		if(!loadMedia()) {
			printf( "Failed to load media!\n" );
		} else {
			bool quit = false;

			SDL_Event e;
			Dot dot;

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
			dot.setPosX(200);
			dot.setPosY(y);

			while(!quit) {
				while(SDL_PollEvent(&e) != 0) {
					if(e.type == SDL_QUIT) {
						quit = true;
					}
					dot.handleEvent(e);
				}
				dot.move();

				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
				SDL_RenderClear(gRenderer);
				dot.render(&gDotTexture, &backgroundTexture, gRenderer);
				SDL_RenderPresent( gRenderer );
			}
		}
	}
	close();

	return 0;
}