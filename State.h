#pragma once

#include <iostream>

enum States
{
    STATE_MOVE_CHARACTER,
    STATE_ATTACKING,
    STATE_ATTACK,
    STATE_EXIT
};

class State
{
public:
	virtual States getName() = 0;

	virtual void onEnter() = 0;
	virtual void events() = 0;
	virtual void logic() = 0;
	virtual void render() = 0;
};

