#include "StateMachine.h"
#include "ExitState.h"
#include "Attacking.h"
#include "MoveCharacter.h"
#include "AttackState.h"
#include "InitialState.h"
#include "EndTurn.h"

State* StateMachine::getCurrentState()
{
	return this->currentState;
}

void StateMachine::setState(States state)
{
    switch(state)
    {
        case STATE_EXIT: this->currentState = new ExitState(); break;
        case STATE_MOVE_CHARACTER: this->currentState = new MoveCharacter(); break;
        case STATE_ATTACK: this->currentState = new AttackState(); break;
        case STATE_ATTACKING: this->currentState = new Attacking(); break;
        case STATE_INIT_GAME: this->currentState = new InitialState(); break;
        case STATE_END_TURN: this->currentState = new EndTurn(); break;
            
    }
}

StateMachine::StateMachine()
{
	this->currentState = new InitialState();
}

StateMachine::~StateMachine()
{
}

