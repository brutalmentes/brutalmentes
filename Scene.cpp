#include "Scene.h"
#include "LoadCollisionMap.h"

Scene::Scene()
{
	LoadCollisionMap lcm;

	this->texture = new Texture("res/img/waterlevel2.png", 0, 0);
	this->collisionList = lcm.load("res/scene.csv");
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