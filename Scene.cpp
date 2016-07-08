#include "Scene.h"
#include "LoadCollisionMap.h"

Scene::Scene(void)
{
	LoadCollisionMap lcm;

	this->texture = new Texture("res/img/moon_level.png", 0, 0);
	this->collisionList = lcm.load("res/moon_level_new.csv");
}

Texture* Scene::getTexture()
{
	return this->texture;
}

Scene::~Scene()
{
	delete this->texture;
}

std::list<Circle> Scene::getCollisionList()
{
	return this->collisionList;
}