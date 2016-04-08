#include "Circle.h"
#include <cmath>


Circle::Circle()
{
}


Circle::~Circle()
{
}


float Circle::dist(Circle c) {
	return sqrt(pow((this->x - c.x), 2) + pow((this->y - c.y), 2));
}