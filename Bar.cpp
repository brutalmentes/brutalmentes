#include "Bar.h"
#include <stdio.h>

Bar::Bar()
{
 	this->texture = new Texture("res/img/bar_verde.png", 1000, 200);
	if(texture ==NULL)
	{
		printf("valor null na testure");
	}	
	texture->setWidth(30);	
	texture->setHeight(10);
}


Bar::~Bar()
{
	delete this->texture;
}

Texture* Bar::getTexture()
{
	return this->texture;
}


