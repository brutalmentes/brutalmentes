#include "Arquimedes.h"
#include "Character.h"

Arquimedes::Arquimedes()
{
	this->texture[0] = new Texture("res/img/arquimedesParado.png", 1000, 200, true, (352/4), 4);
	// transição entre parado e movendo
	this->texture[1] = new Texture("res/img/arquimedesMovendo1.png", 1000,200, true, (528/6), 6);
	// movendo
	this->texture[2] = new Texture("res/img/arquimedesMovendoLoop.png",1000,200, true, (616/7), 7);
	this->texture[3] = new Texture("res/img/arquimedesAtacando.png", 1000,200, true, (1920/12), 12);
	this->texture[4] = new Texture("res/img/arquimedesDefendendo.png", 1000,200, true, (1144/13), 13);
	this->texture[5] = new Texture("res/img/arquimedesDefendendoLoop.png",1000,200, true, 88, 1);
	this->collisionList.push_back(Circle(this->getPosX(), this->getPosY(), 88));
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
