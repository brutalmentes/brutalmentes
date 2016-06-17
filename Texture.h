#ifndef TEXTURE_H
#define TEXTURE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

using namespace std;

enum Orientation {
	ORIENTATION_LEFT,
	ORIENTATION_RIGHT
};

class Texture {
	public:
		Texture(string path, int posX, int posY);

		Texture(string path, int posX, int posY, bool isSprite, float spriteWidth, int nFrames);
		
		~Texture();

		int getPosX();

		int getPosY();

		int getWidth();

		void setPosX(int posX);

		void setPosY(int posY);
                
                void setHeight(int);

		void setWidth(int);

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
