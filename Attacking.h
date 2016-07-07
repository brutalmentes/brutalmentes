#pragma once

#include "State.h"
#include "Object.h"
#include "Physics.h"
#include "Launch.h"
#include "Btimer.h"
#include "Bar.h"

class Attacking : public State
{
private:
	Object *object;
	Physics *physics;
	Btimer *timer;
	Launch *launch;
    Bar *healthBar_newton;
	Bar *healthBar_arquimedes;

	bool done;

public:
	Attacking();

	States getName();
	void onEnter();
	void events();
	void logic();
	void render();
};

