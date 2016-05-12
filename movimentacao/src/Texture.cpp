#include "../lib/Texture.h"

Texture::Texture(string path, int posX, int posY) {
	this->path = path;
	this->posX = posX;
	this->posY = posY;
	this->next = NULL;
	this->sdlTexture = NULL;
}

Texture::~Texture() {
	this->free();
}

int Texture::getPosX() {
	return this->posX;
}

int Texture::getPosY() {
	return this->posY;
}

void Texture::setPosX(int posX) {
	this->posX = posX;
}

void Texture::setPosY(int posY) {
	this->posY = posY;
}

Texture* Texture::getNext() {
	return this->next;
}

void Texture::setNext(Texture* newTexture) {
	this->next = newTexture;
}

bool Texture::loadFromFile(SDL_Renderer* gRenderer) {
	free();
	SDL_Texture* newTexture = NULL;

	SDL_Surface* loadedSurface = IMG_Load(this->path.c_str());
	if(loadedSurface == NULL) {
		printf("Unable to load image %s! SDL_image Error: %s\n", this->path.c_str(), IMG_GetError());
	} else {
		SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0xFF));
        		newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
		if(newTexture == NULL) {
			printf("Unable to create texture from %s! SDL Error: %s\n", this->path.c_str(), SDL_GetError());
		} else {
			this->width = loadedSurface->w;
			this->height = loadedSurface->h;
		}

		SDL_FreeSurface(loadedSurface);
	}
	this->sdlTexture = newTexture;
	return this->sdlTexture != NULL;
}

void Texture::free() {
	if(this->sdlTexture != NULL) {
		SDL_DestroyTexture(this->sdlTexture);
		this->sdlTexture = NULL;
		this->width = 0;
		this->height = 0;
	}
}

void Texture::render(SDL_Renderer* gRenderer, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip) {
	SDL_Rect renderQuad = {this->posX, this->posY, this->width, this->height};
	if(clip != NULL) {
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}
	SDL_RenderCopyEx(gRenderer, this->sdlTexture, clip, &renderQuad, angle, center, flip);
}