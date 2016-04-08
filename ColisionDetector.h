#pragma once
#include "Circle.h"
#include<list>
using namespace std;

class ColisionDetector
{
private:
	bool hasCircleColision(Circle c1, Circle c2);
	bool hasColision(list<Circle> obj1, list<Circle> obj2);
public:
	ColisionDetector();

	~ColisionDetector();
};

