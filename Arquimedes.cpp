#include "Arquimedes.h"
#include "Character.h"

Arquimedes::Arquimedes()
{
	this->texture = new Texture("res/img/arquimedes_parado.png", 1000, 200, true, (355/4), 4);
	this->health = 300;
	this->collisionList.push_back(Circle(this->getPosX(), this->getPosY(), 44));
	this->level=3;
}

Arquimedes::~Arquimedes()
{
	delete this->texture;
}

void Arquimedes::setPosX(int posX) 
{
	Character::setPosX(posX);

	Circle c = this->collisionList.back();
	this->collisionList.pop_back();
	c.x = posX;
	this->collisionList.push_back(c);
}

void Arquimedes::setPosY(int posY) 
{
	Character::setPosY(posY);

	Circle c = this->collisionList.back();
	this->collisionList.pop_back();
	c.y = posY;
	this->collisionList.push_back(c);
}

int Arquimedes::getHealth()
{
	return this->health;
}

int Arquimedes::getLevel()
{
	return this->level;
}

void Arquimedes::setHealth(int health)
{
	this->health = health;
}
void Arquimedes::decHealth()
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

