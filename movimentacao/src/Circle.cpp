#include "../lib/Circle.h"

using namespace std;

Circle::Circle(int x, int y, double r)
{
	this->x = x;
	this->y = y;
	this->r = r;
}

Circle::Circle(int x, int y, double r, string id)
{
	this->x = x;
	this->y = y;
	this->r = r;
	this->id = id;
}

Circle::~Circle()
{
}

double Circle::dist(Circle c) {
	return sqrt(pow((this->x - c.x), 2) + pow((this->y - c.y), 2));
}