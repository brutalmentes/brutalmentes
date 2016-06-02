#ifndef RENDERER_H
#define RENDERER_H

#include "Texture.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

class Renderer {
	public:
		static const int SCREEN_WIDTH = 1557;
		static const int SCREEN_HEIGHT = 882;

		Renderer();
		~Renderer();

		bool init();

		void addTexture(Texture* newTexture);

		void render();
		void clear();

	private:
		SDL_Renderer* gRenderer;
		SDL_Window* gWindow;
};

#endif
