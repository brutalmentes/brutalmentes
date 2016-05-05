#ifndef LTEXTURE_H
#define LTEXTURE_H

#include "share.h"

class LTexture {
	public:
		LTexture();

		~LTexture();

		bool loadFromFile(std::string path, SDL_Renderer* gRenderer);

		void free();

		void setColor( Uint8 red, Uint8 green, Uint8 blue );

		void setBlendMode( SDL_BlendMode blending );

		void setAlpha(Uint8 alpha);

		void render(SDL_Renderer* gRenderer, int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);

		int getWidth();

		int getHeight();
	private:
		SDL_Texture* mTexture;

		int mWidth;
		int mHeight;
};

#endif