#include "Character.h"

Character::Character() 
{
	this->health = 300;
	this->level=3;
	this->numTexture = 0;
}

// void Character::setTexture(Texture *texture) 
// {
// 	this->texture = texture;
// }

// TODO: get texture_id
int Character::getPosX() 
{
	return this->texture[this->numTexture]->getPosX();
}

int Character::getPosY() 
{
	return this->texture[this->numTexture]->getPosY();
}

void Character::setPosX(int posX) 
{
    this->texture[0]->setPosX(posX);
    this->texture[1]->setPosX(posX);
    this->texture[2]->setPosX(posX);
    this->texture[3]->setPosX(posX);
    this->texture[4]->setPosX(posX);
    this->texture[5]->setPosX(posX);
    
    Circle c = this->collisionList.back();
    this->collisionList.pop_back();
    c.x = posX;
    this->collisionList.push_back(c);
}

void Character::setPosY(int posY) 
{
    this->texture[0]->setPosY(posY);
    this->texture[1]->setPosY(posY);
    this->texture[2]->setPosY(posY);
    this->texture[3]->setPosY(posY);
    this->texture[4]->setPosY(posY);
    this->texture[5]->setPosY(posY);
    
    Circle c = this->collisionList.back();
    this->collisionList.pop_back();
    c.y = posY;
    this->collisionList.push_back(c);
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

void Character::setNumTexture(int numTexture)
{
	this->numTexture = numTexture;
}

Texture* Character::getTexture(int id) 
{
	return this->texture[this->numTexture];
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