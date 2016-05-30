#include "StateMachine.h"
#include "Renderer.h"
#include "CollisionDetector.h"
#include "State.h"
#include <string>
#include "Audio.h"
Renderer renderer;
StateMachine stateMachine;
CollisionDetector collisionDetector;
Audio audio;
int main(int argc, char *argv[]) 
{

	audio.playSound("audio/AC01.wav",3);
	if(!renderer.init())
	{
		stateMachine.setState(STATE_EXIT);
	}

	State* currentState = stateMachine.getCurrentState();

	while(currentState->getName() != STATE_EXIT)
	{
		currentState->events();
		currentState->logic();
		currentState->render();

		currentState = stateMachine.getCurrentState();
	}

	delete currentState;

	return 0;
}
