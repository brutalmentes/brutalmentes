#pragma once

#include "Texture.h"
#define EVENT_BUTTON_CLICKED 1

class Button
{
private:
	Texture *texture;
public:
	Texture* getTexture();
	void handleEvent(SDL_Event* e);

	Button();
	~Button();
};

