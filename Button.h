#pragma once
 
#include "Texture.h"
#define BTN_ATTACK 1
#define BTN_DEFENSE 2
#define BTN_CONTINUE 3
 
class Button
{
private:
    Texture *texture;
    int id;
public:
    Texture* getTexture();
    void handleEvent(SDL_Event* e);
 
    Button(int id, string path, int posX, int posY);
    Button();
    ~Button();
};