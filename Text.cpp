#include "Text.h"

Text::Text(std::string text, SDL_Color color, int x, int y)
{
	this->color = color;
	this->text = text;
	this->x = x;
	this->y = y;
}

Text::~Text(void)
{
	if(this->sdlTexture != NULL) 
	{
		SDL_DestroyTexture(this->sdlTexture);
		this->sdlTexture = NULL;
	}
}

void Text::loadFromRenderedText(SDL_Renderer *gRenderer, TTF_Font *gFont)
{
	SDL_Surface* textSurface = TTF_RenderText_Solid( gFont, this->text.c_str(), color);
	this->sdlTexture = SDL_CreateTextureFromSurface( gRenderer, textSurface );
	this->width = textSurface->w;
	this->height = textSurface->h;
	SDL_FreeSurface(textSurface);
}

void Text::render(SDL_Renderer* gRenderer)
{
	SDL_Rect renderQuad = { this->x, this->y, this->width, this->height };
	SDL_RenderCopy( gRenderer, this->sdlTexture, NULL, &renderQuad );
}