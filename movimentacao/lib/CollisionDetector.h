#pragma once
#include "Circle.h"
#include<list>
using namespace std;

class CollisionDetector
{
public:	
	bool hasCollision(list<Circle> obj1, list<Circle> obj2);
	CollisionDetector();
	~CollisionDetector();
	bool hasCircleCollision(Circle c1, Circle c2);	
};

