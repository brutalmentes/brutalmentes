#pragma once

#include <SDL.h>
#include <SDL_ttf.h>
#include <string>

class Text
{
private:
	SDL_Texture* sdlTexture;
	int x, y, width, height;
	std::string text;
	SDL_Color color;

public:
	Text(std::string text, SDL_Color color, int x, int y);
	~Text();

	void render(SDL_Renderer* gRenderer);
	void loadFromRenderedText(SDL_Renderer *gRenderer, TTF_Font *gFont);
};

