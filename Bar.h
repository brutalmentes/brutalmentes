#pragma once
#include "Texture.h"
class Bar
{
private:
	Texture *textures[10]; 
 
 public:
 Bar(int, int);
 ~Bar();
 Texture* getTexture(int);
 void setWidth(int id, int width);
 void setHeight(int id ,int height);
 int getWidth(int id);
};
