#include "Bar.h"
#include <stdio.h>

Bar::Bar(int posX, int posY)
{
 	this->textures[3] = new Texture("res/img/bar_verde.png", posX, posY);
  this->textures[2]= new Texture("res/img/bar_amarela.png", posX, posY);
	this->textures[1]= new Texture("res/img/bar_laranja.png", posX, posY);
	this->textures[0]   = new Texture("res/img/bar_vermelha.png", posX, posY);	
	if(textures ==NULL)
	{
		printf("valor null na texture");
	}
}


Bar::~Bar()
{
	delete this->textures;
}

Texture* Bar::getTexture(int id)
{
	return this->textures[id];
}


