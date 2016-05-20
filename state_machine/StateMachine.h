#pragma once
enum State
{
	INITIAL_OVERVIEW,
	MOVEMENT,
	ATTACK_OR_DEFEND,
	CHOOSE_ATTACK_TYPE,
	PLAN_ATTACK,
	ATTACK,
	UPDATE_INFO,
	RANDOM_ELEMENTS,
	END_MATCH
};

class StateMachine
{
private:
	State CurrentState;
public:
	State GetCurrentState();
	State NextState();

	StateMachine();
	~StateMachine();
};

