#ifndef RENDERER_H
#define RENDERER_H

#include "Texture.h"
#include "Text.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>

class Renderer {
	public:
		static const int SCREEN_WIDTH = 1200;
		static const int SCREEN_HEIGHT = 670;

		Renderer();
		~Renderer();

		bool init();

		void addTexture(Texture* newTexture);
		void addTexture(Texture* newTexture,double,SDL_Point*);	
		void addTextureWithSize(Texture* newTexture, int width, int height);

		void addText(Text* newText);

		void render();
		void clear();

	private:
		SDL_Renderer* gRenderer;
		SDL_Window* gWindow;
		TTF_Font *gFont;
};

#endif
