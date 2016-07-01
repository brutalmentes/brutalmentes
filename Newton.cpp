#include "Newton.h"

Newton::Newton() : Character()
{
	this->texture[0] = new Texture("res/img/newtonParado.png", 100, 800, true, 52, 22);
	// transição entre parado e movendo
	this->texture[1] = new Texture("res/img/newtonMovendoLoop.png", 100,800, true, (624/12), 12);
	// movendo
	this->texture[2] = new Texture("res/img/newtonMovendoLoop.png", 100,800, true, (624/12), 12);
	this->texture[3] = new Texture("res/img/newtonAtacando.png",100,800, true, (1480/20), 20);
	this->texture[4] = new Texture("res/img/newtonDefendendo.png", 100,800, true, (1691/12), 12);
	this->texture[5] = new Texture("res/img/newtonDefendendoLoop.png", 100,800, true, 140, 1);
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
