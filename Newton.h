#pragma once

#include "Character.h"
#include "Circle.h"
#include "Health.h"
#include <list>

class Newton : public Character
{
private:
	Health *health;
public:
	void setPosX(int posX);
	void setPosY(int posY);
	Newton();
	~Newton();
};

