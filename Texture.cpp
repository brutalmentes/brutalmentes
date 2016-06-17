#include "Texture.h"
#include <stdio.h>

Texture::Texture(string path, int posX, int posY) 
{
	this->path = path;
	this->posX = posX;
	this->posY = posY;
	this->next = NULL;
	this->sdlTexture = NULL;
	this->isSprite = false;
	this->currentFrame = 1;
	this->spriteWidth = 0;
	this->nFrames = 0;
	this->flip = SDL_FLIP_NONE;
}

Texture::Texture(string path, int posX, int posY, bool isSprite, float spriteWidth, int nFrames) 
{
	this->path = path;
	this->posX = posX;
	this->posY = posY;
	this->next = NULL;
	this->sdlTexture = NULL;
	this->isSprite = isSprite;
	this->currentFrame = 1;
	this->spriteWidth = spriteWidth;
	this->nFrames = nFrames;
}

Texture::~Texture() 
{
	this->free();
}

int Texture::getPosX() 
{
	return this->posX;
}

int Texture::getPosY() 
{
	return this->posY;
}

int Texture::getWidth() {
	return this->width;
} 

void Texture::setPosX(int posX) 
{
	this->posX = posX;
}

void Texture::setPosY(int posY) 
{
	this->posY = posY;
}

void Texture::setWidth(int width) 
{
	this->width = width;
}

void Texture::setHeight(int height) 
{
	this->height = height;
}

Texture* Texture::getNext()
{
	return this->next;
}

void Texture::setNext(Texture* newTexture) 
{
	this->next = newTexture;
}

bool Texture::getIsSprite() 
{
	return this->isSprite;
}

bool Texture::loadFromFile(SDL_Renderer* gRenderer) {
	free();
	SDL_Texture* newTexture = NULL;

	SDL_Surface* loadedSurface = IMG_Load(this->path.c_str());
	if(loadedSurface == NULL) 
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", this->path.c_str(), IMG_GetError());
	} 
	else 
	{
		SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0xFF));
        		newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
		if(newTexture == NULL) 
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", this->path.c_str(), SDL_GetError());
		} 
		else {
			this->width = loadedSurface->w;
			this->height = loadedSurface->h;
		}

		SDL_FreeSurface(loadedSurface);
	}
	this->sdlTexture = newTexture;
	return this->sdlTexture != NULL;
}

void Texture::free() 
{
	if(this->sdlTexture != NULL) 
	{
		SDL_DestroyTexture(this->sdlTexture);
		this->sdlTexture = NULL;
		this->width = 0;
		this->height = 0;
	}
}

void Texture::setFlip(SDL_RendererFlip flip)
{
	this->flip = flip;
}

void Texture::render(SDL_Renderer* gRenderer, SDL_Rect* clip, double angle, SDL_Point* center) 
{
	SDL_Rect spriteRect;
	
	SDL_Rect renderQuad = {this->posX, this->posY, this->width, this->height};
	
	if(this->isSprite) 
	{
		spriteRect.x = (this->currentFrame - 1) * this->spriteWidth;
		spriteRect.y = 0;
		spriteRect.w = this->spriteWidth;
		spriteRect.h = this->height;
		
		if(this->currentFrame == this->nFrames) 
		{
			this->currentFrame = 1;
		} 
		else 
		{
			this->currentFrame = this->currentFrame + 1;
		}
		renderQuad.w = spriteRect.w;
		renderQuad.h = spriteRect.h;
		
		SDL_RenderCopyEx(gRenderer, this->sdlTexture, &spriteRect, &renderQuad, angle, center, this->flip);
	} 
	else 
	{
		SDL_RenderCopyEx(gRenderer, this->sdlTexture, clip, &renderQuad, angle, center, this->flip);
	}
}