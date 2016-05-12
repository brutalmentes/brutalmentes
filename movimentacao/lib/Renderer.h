#ifndef RENDERER_H
#define RENDERER_H

#include "Texture.h"
#include "share.h"

class Renderer {
	public:
		static const int SCREEN_WIDTH = 1557;
		static const int SCREEN_HEIGHT = 882;

		Renderer();

		~Renderer();

		bool init();

		void addTexture(Texture* newTexture);

		void render();
	private:
		SDL_Renderer* gRenderer;
		SDL_Window* gWindow;

		Texture* textures;
};

#endif