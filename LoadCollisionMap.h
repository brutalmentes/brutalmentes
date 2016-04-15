#pragma once

#include "Circle.h"
#include <string>
#include <list>

using namespace std;

class LoadCollisionMap
{
public:	
	LoadCollisionMap();
	~LoadCollisionMap();
	list<Circle> load(string fileName);
};

