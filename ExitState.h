#pragma once

#include "State.h"

class ExitState : public State
{
public:
	ExitState();
	States getName();
	void events();
	void logic();
	void render();
};

