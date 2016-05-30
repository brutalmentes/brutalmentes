#include "ExitState.h"
#include "State.h"

ExitState::ExitState()
{
}

void ExitState::events()
{
}

void ExitState::logic()
{
}

void ExitState::render()
{
}

States ExitState::getName() 
{
	return States::STATE_EXIT;
}