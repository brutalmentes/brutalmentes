#include "Character.h"

Character::Character() 
{
}

void Character::setTexture(Texture *texture) 
{
	this->texture = texture;
}

int Character::getPosX() 
{
	return this->texture->getPosX();
}

int Character::getPosY() 
{
	return this->texture->getPosY();
}

void Character::setPosX(int posX) 
{
	this->texture->setPosX(posX);
}

void Character::setPosY(int posY) 
{
	this->texture->setPosY(posY);
}

Texture* Character::getTexture() 
{
	return this->texture;
}

void Character::setOrientation(Orientation orientation)
{
	if(orientation == ORIENTATION_LEFT)
	{
		this->texture->setFlip(SDL_FLIP_HORIZONTAL);
	}
	else
	{
		this->texture->setFlip(SDL_FLIP_NONE);
	}
}

std::list<Circle> Character::getCollisionList()
{
	return this->collisionList;
}