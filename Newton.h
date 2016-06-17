#pragma once

#include "Character.h"
#include "Circle.h"
#include <list>
class Newton : public Character
{
private:

int health;
int level;
public:
	void setPosX(int posX);
	void setPosY(int posY);
	int getHealth();
	void setHealth(int);
	void decHealth();
	int getLevel();
	Newton();
	~Newton();
};

