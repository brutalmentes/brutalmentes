#include "Renderer.h"

using namespace std;

Renderer::Renderer() {
	this->gRenderer = NULL;
	this->gWindow = NULL;
}

Renderer::~Renderer() {
	// Dar free em todos os elementos

	SDL_DestroyRenderer(this->gRenderer);
	SDL_DestroyWindow(this->gWindow);
	this->gWindow = NULL;
	this->gRenderer = NULL;

	TTF_CloseFont(this->gFont);
	this->gFont = NULL;

	IMG_Quit();
	SDL_Quit();
}

bool Renderer::init() {
	if(SDL_Init(SDL_INIT_EVERYTHING < 0)) {
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		return false;
	} 

	this->gWindow = SDL_CreateWindow("Brutal Mentes!", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 
									SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	if(this->gWindow == NULL) {
		printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
		return false;
	} 	
	
	this->gRenderer = SDL_CreateRenderer(this->gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	
	if(this->gRenderer == NULL) {
		printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
		return false;
	} 

	SDL_SetRenderDrawColor(this->gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

	int imgFlags = IMG_INIT_PNG;

	if(!(IMG_Init(imgFlags) & imgFlags)) {
		printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
		return false;
	}

	if( TTF_Init() == -1 )
	{
		const char* error = TTF_GetError();
		printf( "SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError() );
		return false;
	}

	this->gFont = TTF_OpenFont( "fonts/PermanentMarker.ttf", 50);

	return true;	
}

void Renderer::clear() {
	SDL_SetRenderDrawColor(this->gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(this->gRenderer);
}

void Renderer::addTexture(Texture* newTexture) {
	newTexture->loadFromFile(this->gRenderer);
	newTexture->render(this->gRenderer);
}

void Renderer::addText(Text* newText) {
	newText->loadFromRenderedText(this->gRenderer, this->gFont);
	newText->render(this->gRenderer);
}

void Renderer::render() {
	SDL_RenderPresent(this->gRenderer);
}