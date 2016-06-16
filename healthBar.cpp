#include "healthBar.h"
#include <stdio.h>

healthBar::healthBar()
{
 	this->texture = new Texture("res/img/bar_verde.png", 1000, 200);
/*	if(texture ==NULL)
	{
		printf("valor null na testure");
	}	*/
	texture->setWidth(30);	
	texture->setHeight(10);
}


healthBar::~healthBar()
{
	delete this->texture;
}

Texture* healthBar::getTexture()
{
	return this->texture;
}


