#include "Button.h"
 
#define BUTTON_WIDTH 126
#define BUTTON_HEIGHT 40
 
Button::Button(int id, string path, int posX, int posY)
{
    this->id = id;
    this->texture = new Texture(path, posX, posY);
}
 
Button::Button()
{
    this->id = 3;
    this->texture = new Texture(" res/img/btn_continuar.png", 1064, 620);
}
 
Button::~Button(void)
{
    delete this->texture;
}
 
Texture* Button::getTexture()
{
    return this->texture;
}
 
void Button::handleEvent(SDL_Event* e)
{
    if(e->type == SDL_MOUSEBUTTONDOWN)
    {
        //Get mouse position
        int x, y;
        SDL_GetMouseState( &x, &y );
 
        bool inside = true;
 
        //Mouse is left of the button
        if( x < this->texture->getPosX() )
        {
            inside = false;
        }
        //Mouse is right of the button
        else if( x > this->texture->getPosX() + BUTTON_WIDTH )
        {
            inside = false;
        }
        //Mouse above the button
        else if( y < this->texture->getPosY() )
        {
            inside = false;
        }
        //Mouse below the button
        else if( y > this->texture->getPosY() + BUTTON_HEIGHT )
        {
            inside = false;
        }
 
        if(inside)
        {
            SDL_Event event;
            event.type = SDL_USEREVENT;
            event.user.code = this->id;
            SDL_PushEvent(&event);
        }
    }
}