#ifndef RENDERER_H
#define RENDERER_H

#include "Texture.h"
#include "Text.h"
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <iostream>

class Renderer {
	public:
		static const int SCREEN_WIDTH = 1200;
		static const int SCREEN_HEIGHT = 670;

		Renderer();
		~Renderer();

		bool init();

		void addTexture(Texture* newTexture);
		void addText(Text* newText);

		void render();
		void clear();

	private:
		SDL_Renderer* gRenderer;
		SDL_Window* gWindow;
		TTF_Font *gFont;
};

#endif