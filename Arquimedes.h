#pragma once

#include "Character.h"

class Arquimedes : public Character
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
	Arquimedes();
	~Arquimedes();
};

