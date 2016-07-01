#include "Character.h"

Character::Character() 
{
	this->health = 300;
	this->level=3;
}

// void Character::setTexture(Texture *texture) 
// {
// 	this->texture = texture;
// }

// TODO: get texture_id
int Character::getPosX() 
{
	return this->texture[0]->getPosX();
}

int Character::getPosY() 
{
	return this->texture[0]->getPosY();
}

void Character::setPosX(int posX) 
{
	this->texture[0]->setPosX(posX);
}

void Character::setPosY(int posY) 
{
	this->texture[0]->setPosY(posY);
}

int Character::getHealth()
{
	return this->health;
}

void Character::setHealth(int health)
{
	this->health = health;
}
void Character::decHealth()
{
 
	if(health > 10)
	{
 		this->health-=10;
		if(this->level >= 1)	
			this->level-=1;
	}
	else
 	{
  	health=0;
 	}
}

int Character::getLevel()
{
	return this->level;
}

Texture* Character::getTexture(int id) 
{
	return this->texture[id];
}

void Character::setOrientation(Orientation orientation)
{
	if(orientation == ORIENTATION_LEFT)
	{
		this->texture[0]->setFlip(SDL_FLIP_NONE);		
	}
	else
	{
		this->texture[0]->setFlip(SDL_FLIP_HORIZONTAL);
	}
}

std::list<Circle> Character::getCollisionList()
{
	return this->collisionList;
}