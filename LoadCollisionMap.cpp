#include "LoadCollisionMap.h"

#include <fstream>

LoadCollisionMap::LoadCollisionMap()
{
}


LoadCollisionMap::~LoadCollisionMap()
{
}

list<Circle> LoadCollisionMap::load(string fileName)
{
	ifstream fin(fileName);
	string line;

	list<Circle> circlesList;

	int x, y;
	double r;
	string id;

	// descarta primeira linha
	getline(fin, line);

	while(getline(fin, line, ','))
	{
		id = line;

		getline(fin, line, ',');
		x = atoi(line.c_str());

		getline(fin, line, ',');
		y = atoi(line.c_str());

		getline(fin, line, '\n');
		r = atoi(line.c_str());

		Circle c(x, y, r, id);
		circlesList.push_back(c);
	}

	return circlesList;
}