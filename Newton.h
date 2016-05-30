#pragma once

#include "Character.h"
#include "Circle.h"
#include <list>

class Newton : public Character
{
public:
	void setPosX(int posX);
	void setPosY(int posY);

	Newton();
	~Newton();
};

