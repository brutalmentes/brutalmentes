#ifndef TEXTURE_H
#define TEXTURE_H

#include "share.h"

class Texture {
	public:
		Texture(string path, int posX, int posY);

		Texture(string path, int posX, int posY, bool isSprite, int spriteWidth, int nFrames);
		
		~Texture();

		int getPosX();

		int getPosY();

		void setPosX(int posX);

		void setPosY(int posY);

		Texture* getNext();

		void setNext(Texture* newTexture);
		
		bool getIsSprite();

		bool loadFromFile(SDL_Renderer* gRenderer);

		void free();

		void render(SDL_Renderer* gRenderer, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);
	private:
		Texture* next;
		int posX, posY, width, height, currentFrame, nFrames, spriteWidth;
		SDL_Texture* sdlTexture;
		string path;
		bool isSprite;
};

#endif