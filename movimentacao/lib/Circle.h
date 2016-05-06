#ifndef CIRCLE_H
#define CIRCLE_H
#include "share.h"

class Circle
{
public:
	Circle(int x, int y, double r);
	Circle(int x, int y, double r, std::string id);
	double dist(Circle c);
	~Circle();
	int x;
	int y;
	double r;
	string id;
};


#endif