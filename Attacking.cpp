#include "Attacking.h"
//#include "Physics.h"
//#include "Renderer.h"
//#include "Scene.h"

//extern Renderer renderer;

//Scene scene;

Attacking::Attacking()
{
	//object = new Object(100.0f, 400.0f);
	//launch = new Launch(10.0f, 0.5f);
	//btimer = new Btimer();

	//this->physics.start(object, launch, btimer);	
}

void Attacking::events()
{
}

void Attacking::logic()
{

}

void Attacking::render()
{
	//renderer.clear();
	//renderer.addTexture(scene.getTexture());
	//renderer.render();
}

States Attacking::getName() 
{
	return STATE_ATTACKING;
}
