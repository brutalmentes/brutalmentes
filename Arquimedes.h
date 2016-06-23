#pragma once

#include "Character.h"
#include "Health.h"
class Arquimedes : public Character
{
private:
	Health *health;
public:
	void setPosX(int posX);
	void setPosY(int posY);
	Health* getHealt():	
	Arquimedes();
	~Arquimedes();
};

