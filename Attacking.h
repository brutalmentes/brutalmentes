#pragma once

#include "State.h"
//#include "Physics.h"

class Attacking : public State
{
private:
	/*Physics *physics;
	Object *object;
	Btimer *btimer;
	Launch *launch;*/

public:
	Attacking();

	States getName();
	void events();
	void logic();
	void render();
};

