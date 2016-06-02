#pragma once

#include "Circle.h"
#include <string>
#include <list>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <cstdlib>
using namespace std;

class LoadCollisionMap
{
public:	
	LoadCollisionMap();
	~LoadCollisionMap();
	list<Circle> load(string fileName);
};

