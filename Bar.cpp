#include "Bar.h"
#include <stdio.h>

Bar::Bar()
{
 	this->textures[3] = new Texture("res/img/bar_verde.png", 1000, 200);
        this->textures[2]= new Texture("res/img/bar_amarela.png", 1000, 200);
	this->textures[1]= new Texture("res/img/bar_laranja.png", 1000, 200);
	this->textures[0]   = new Texture("res/img/bar_vermelha.png", 1000, 200);	
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


