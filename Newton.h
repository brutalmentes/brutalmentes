#pragma once

#include "Character.h"
#include "Circle.h"
#include <list>

class Newton : public Character
{
private:	
	std::list<Circle> collisionList;
public:
	Newton();
	~Newton();

	std::list<Circle> getCollisionList();	
};

