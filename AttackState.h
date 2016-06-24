#pragma once

#include <string>
#include "StateMachine.h"
#include "State.h"
#include "Newton.h"
#include "Arquimedes.h"
#include "Character.h"
#include "Scene.h"
#include "Button.h"

class AttackState : public State
{
private:
	Newton newton;
	Arquimedes arquimedes;
	Scene scene;
	Button btnContinue;
	
	Character *currentCharacter;

public:
	AttackState();

	States getName();
	void onEnter();
	void events();
	void logic();
	void render();
};

