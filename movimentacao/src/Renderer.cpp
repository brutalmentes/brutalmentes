#include "../lib/Renderer.h"

using namespace std;

Renderer::Renderer() {
	this->gRenderer = NULL;
	this->gWindow = NULL;
	this->textures = NULL;
}

Renderer::~Renderer() {
	// Dar free em todos os elementos

	SDL_DestroyRenderer(this->gRenderer);
	SDL_DestroyWindow(this->gWindow);
	this->gWindow = NULL;
	this->gRenderer = NULL;

	IMG_Quit();
	SDL_Quit();
}

bool Renderer::init() {
	bool success = true;

	if(SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	} else {
		if(!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
			printf( "Warning: Linear texture filtering not enabled!" );
		}

		this->gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if(this->gWindow == NULL) {
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		} else {
			this->gRenderer = SDL_CreateRenderer(this->gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			if(this->gRenderer == NULL) {
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
				success = false;
			} else {
				SDL_SetRenderDrawColor(this->gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
				int imgFlags = IMG_INIT_PNG;
				if(!(IMG_Init(imgFlags) & imgFlags)) {
					printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
					success = false;
				}
			}
		}
	}

	return success;
}

void Renderer::addTexture(Texture* newTexture) {
	newTexture->loadFromFile(this->gRenderer);
	if(this->textures == NULL) {
		this->textures = newTexture;
	} else {
		Texture* texture = this->textures;
		while(texture->getNext() != NULL) {
			texture = texture->getNext();
		}

		texture->setNext(newTexture);
	}
}

void Renderer::render() {
	Texture* texture = this->textures;

	SDL_SetRenderDrawColor(this->gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(this->gRenderer);

	while(texture != NULL) {
		if(texture->getPosX() > Renderer::SCREEN_WIDTH) {
			texture->setPosX(Renderer::SCREEN_WIDTH);
		} else if(texture->getPosX() < 0) {
			texture->setPosX(0);
		}

		texture->render(this->gRenderer);
		texture = texture->getNext();
	}

	SDL_RenderPresent(this->gRenderer);
}