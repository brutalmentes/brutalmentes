#include "Arquimedes.h"
#include "Character.h"

Arquimedes::Arquimedes()
{
	this->texture = new Texture("res/img/arquimedes_move.png", 1000, 200, true, 32, 2);

	this->collisionList.push_back(Circle(this->getPosX(), this->getPosY(), 32));
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