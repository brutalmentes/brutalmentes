#ifndef LOAD_COLLISION_H
#define LOAD_COLLISION_H

#include "share.h"
#include "Circle.h"

class LoadCollisionMap
{
public:
	LoadCollisionMap();
	~LoadCollisionMap();
	list<Circle> load();
};

#endif