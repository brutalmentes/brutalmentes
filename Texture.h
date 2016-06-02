#ifndef TEXTURE_H
#define TEXTURE_H

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

using namespace std;

enum Orientation {
	ORIENTATION_LEFT,
	ORIENTATION_RIGHT
};

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

		void setFlip(SDL_RendererFlip flip);

		void free();

		void render(SDL_Renderer* gRenderer, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL);
	private:
		SDL_RendererFlip flip;
		Texture* next;
		int posX, posY, width, height, currentFrame, nFrames, spriteWidth;
		SDL_Texture* sdlTexture;
		string path;
		bool isSprite;
};

#endif