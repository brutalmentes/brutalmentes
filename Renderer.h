#ifndef RENDERER_H
#define RENDERER_H

#include "Texture.h"
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

class Renderer {
	public:
		static const int SCREEN_WIDTH = 1300;
		static const int SCREEN_HEIGHT = 680;

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