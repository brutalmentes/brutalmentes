#pragma once

#include "Character.h"

class Arquimedes : public Character
{
private:

int health;

public:
	void setPosX(int posX);
	void setPosY(int posY);
	int getHealth();
	void setHealth(int);
	void decHealth();

	Arquimedes();
	~Arquimedes();
};

