#include "Newton.h"

Newton::Newton() : Character()
{
	this->texture = new Texture("res/img/newton_stop.png", 200, 200, true, 32, 8);

	this->collisionList.push_back(Circle(this->getPosX(), this->getPosY(), 32));
}


Newton::~Newton()
{
	delete this->texture;
}

void Newton::setPosX(int posX) 
{
	Character::setPosX(posX);

	Circle c = this->collisionList.back();
	this->collisionList.pop_back();
	c.x = posX;
	this->collisionList.push_back(c);
}

void Newton::setPosY(int posY) 
{
	Character::setPosY(posY);

	Circle c = this->collisionList.back();
	this->collisionList.pop_back();
	c.y = posY;
	this->collisionList.push_back(c);
}