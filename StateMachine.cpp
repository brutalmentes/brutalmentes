#include "StateMachine.h"
#include "ExitState.h"
#include "MoveCharacter.h"
#include "AttackState.h"

State* StateMachine::getCurrentState()
{
	return this->currentState;
}

void StateMachine::setState(States state)
{
	switch(state) 
	{
		case STATE_EXIT: this->currentState = new ExitState(); break;
		case STATE_MOVE_CHARACTER: this->currentState = new MoveCharacter(); break;
		case STATE_ATTACK: this->currentState = new AttackState(); break;
	}
}

StateMachine::StateMachine()
{
	this->currentState = new MoveCharacter();
}

StateMachine::~StateMachine()
{
}

