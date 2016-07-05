#include "Menu.h"

Menu::Menu()
{
    this->texture = new Texture(" res/img/menu.png", 0, 0);
    this->boxJogar = new SDL_Rect();
    this->boxSair = new SDL_Rect();
    setRect();
}

Menu::~Menu()
{
    delete this->texture;
}

Texture* Menu::getTexture()
{
	return this->texture;
}

SDL_Rect* Menu::getBoxJogar()
{
    return this->boxJogar;
}

SDL_Rect* Menu::getBoxSair()
{
    return this->boxSair;
}

void Menu::setRect()
{
    this->boxJogar->x=735;
    this->boxJogar->y=320;
    this->boxJogar->w=200;
    this->boxJogar->h=60;

    this->boxSair->x=750;
    this->boxSair->y=515;
    this->boxSair->w=155;
    this->boxSair->h=60;
}
