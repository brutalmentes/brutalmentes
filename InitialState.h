#ifndef INITIALSTATE_H
#define INITIALSTATE_H

#include "Menu.h"
#include "StateMachine.h"
#include "State.h"

class InitialState : public State
{
    public:
        InitialState();

        States getName();
        void events();
        void logic();
        void render();
        void onEnter();

    private:
        Menu* menu;


};

#endif // INITIALSTATE_H
