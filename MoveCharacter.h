#pragma once

#include <string>
#include "StateMachine.h"
#include "State.h"
#include "Newton.h"
#include "Scene.h"

class MoveCharacter : public State
{
private:
	Newton newton;
	Scene scene;

public:
	MoveCharacter();

	States getName();
	void events();
	void logic();
	void render();
};

