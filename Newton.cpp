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

std::list<Circle> Newton::getCollisionList()
{
	return this->collisionList;
}