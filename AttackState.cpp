#include "AttackState.h"
#include "State.h"
#include "StateMachine.h"
#include "CollisionDetector.h"
#include "Renderer.h"
#include "Newton.h"
#include "Scene.h"
#include "Button.h"
#include "Timer.h"
#include "Audio.h"
#include <list>
#include <sstream>

using namespace std;

extern StateMachine stateMachine;
extern Renderer renderer;
extern CollisionDetector collisionDetector;
extern Audio audio;

AttackState::AttackState()
{
}

void AttackState::onEnter()
{
}

void AttackState::events()
{
	
}

void AttackState::logic()
{
}

void AttackState::render()
{
}

States AttackState::getName() {
	return STATE_ATTACK;
}
