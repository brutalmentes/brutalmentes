#ifndef MENU_H
#define MENU_H

#include "Texture.h"

class Menu
{
    public:
        Menu();
        virtual ~Menu();
        Texture* getTexture();
        SDL_Rect* getBoxJogar();
        SDL_Rect* getBoxSair();
        void setRect();

    private:
        Texture *texture;
        SDL_Rect* boxJogar = new SDL_Rect();
        SDL_Rect* boxSair = new SDL_Rect();
};

#endif // MENU_H
