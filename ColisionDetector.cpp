#include "ColisionDetector.h"



ColisionDetector::ColisionDetector()
{
}


ColisionDetector::~ColisionDetector()
{
}

bool ColisionDetector::hasCircleColision(Circle c1, Circle c2) {
	return c1.r + c2.r <= c1.dist(c2);
}

bool ColisionDetector::hasColision(list<Circle> obj1, list<Circle> obj2) {
	for (list<Circle>::iterator it1 = obj1.begin(); it1 != obj1.end(); it1++) {
		for (list<Circle>::iterator it2 = obj2.begin(); it2 != obj2.end(); it2++) {
			if (hasCircleColision(*it1, *it2)) return true;				
		}
	}
	return false;
}