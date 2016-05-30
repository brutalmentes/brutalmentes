#include "StateMachine.h"
#include "ExitState.h"
#include "MoveCharacter.h"

State* StateMachine::getCurrentState()
{
	return this->currentState;
}

void StateMachine::setState(States state)
{
	switch(state) 
	{
		case STATE_EXIT: this->currentState = new ExitState(); break;
	}
}

StateMachine::StateMachine()
{
	this->currentState = new MoveCharacter();
}

StateMachine::~StateMachine()
{
}
