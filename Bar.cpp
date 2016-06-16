#include "Bar.h"
#include <stdio.h>

Bar::Bar()
{
 	this->texture = new Texture("res/img/bar_verde.png", 1000, 200);
	if(texture ==NULL)
	{
		printf("valor null na testure");
	}
}


Bar::~Bar()
{
	delete this->texture;
}

Texture* Bar::getTexture()
{
	return this->texture;
}

void Bar::setWidth(int width) 
{
	this->texture->setWidth(width);
}

void Bar::setHeight(int height) 
{
	this->texture->setHeight(height);
}


int Bar::getWidth() {
	return this->texture->getWidth();
}