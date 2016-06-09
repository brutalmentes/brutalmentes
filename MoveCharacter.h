#pragma once

#include <string>
#include "StateMachine.h"
#include "State.h"
#include "Newton.h"
#include "Arquimedes.h"
#include "Character.h"
#include "Scene.h"
#include "Button.h"

class MoveCharacter : public State
{
private:
	Newton newton;
	Arquimedes arquimedes;
	Scene scene;
	Button btnContinue;
	Button *btnAttack;
	Button *btnDefense;
	
	Character *currentCharacter;

public:
	MoveCharacter();

	States getName();
	void events();
	void logic();
	void render();
};

