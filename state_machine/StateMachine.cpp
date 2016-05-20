#include "StateMachine.h"

State StateMachine::GetCurrentState()
{
	return this->CurrentState;
}

State StateMachine::NextState()
{
	State nextState;

	switch (this->CurrentState)
	{
	case MOVEMENT: nextState = ATTACK_OR_DEFEND; break;
	case ATTACK_OR_DEFEND: nextState = CHOOSE_ATTACK_TYPE; break;
	case CHOOSE_ATTACK_TYPE: nextState = PLAN_ATTACK; break;
	case PLAN_ATTACK: nextState = ATTACK; break;
	default:
		break;
	}
}

StateMachine::StateMachine()
{
	this->CurrentState = INITIAL_OVERVIEW;
}

StateMachine::~StateMachine()
{
}
