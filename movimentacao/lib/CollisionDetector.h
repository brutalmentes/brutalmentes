#ifndef COLLISION_DETECTOR_H
#define COLLISION_DETECTOR_H

#include "Circle.h"
#include "share.h"

class CollisionDetector
{
public:
	bool hasCollision(list<Circle> obj1, list<Circle> obj2);
	CollisionDetector();
	~CollisionDetector();
	bool hasCircleCollision(Circle c1, Circle c2);
};

#endif