#include "StateMachine.h"
#include "Renderer.h"
#include "CollisionDetector.h"
#include "State.h"
#include <string>

Renderer renderer;
StateMachine stateMachine;
CollisionDetector collisionDetector;

int main(int argc, char *argv[]) 
{
	if(!renderer.init())
	{
		stateMachine.setState(States::STATE_EXIT);
	}

	State* currentState = stateMachine.getCurrentState();

	while(currentState->getName() != States::STATE_EXIT)
	{
		currentState->events();
		currentState->logic();
		currentState->render();

		currentState = stateMachine.getCurrentState();
	}

	delete currentState;

	return 0;
}