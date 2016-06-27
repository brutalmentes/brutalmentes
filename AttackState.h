#pragma once

#include <string>
#include "StateMachine.h"
#include "State.h"
#include "Newton.h"
#include "Arquimedes.h"
#include "Character.h"
#include "Scene.h"
#include "Button.h"
#include "Bar.h"

class AttackState : public State
{
private:
	Newton newton;
	Arquimedes arquimedes;
	Scene scene;
	Button btnContinue;
        Button *btnAttack;
        Button *btnDefense;
	Bar *forceBar;
	Character *currentCharacter;
	Bar *healthBar_newton;
	Bar *healthBar_arquimedes;

public:
	AttackState();

	States getName();
	void events();
	void logic();
	void render();
};

