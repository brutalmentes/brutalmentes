#pragma once

#include <iostream>

enum States
{
    STATE_MOVE_CHARACTER,
    STATE_EXIT
};

class State
{
public:
	virtual States getName() = 0;

	virtual void events() = 0;
	virtual void logic() = 0;
	virtual void render() = 0;
};

