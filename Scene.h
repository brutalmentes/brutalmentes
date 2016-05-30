#pragma once

#include "Texture.h"
#include "Circle.h"
#include <list>

class Scene
{
private:
	Texture *texture;
	std::list<Circle> collisionList;
public:
	Scene(void);
	~Scene(void);

	Texture* getTexture();
	std::list<Circle> getCollisionList();	
};

