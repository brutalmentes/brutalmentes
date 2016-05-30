#pragma once

#include "State.h"

class StateMachine
{
private:
	State *currentState;	
public:
	StateMachine();

	State* getCurrentState();
	States nextState();
	void setState(States);

	
	~StateMachine();
};

