#pragma once

#include "State.h"
#include "Character.h"
#include "Scene.h"
#include "Bar.h"

class EndTurn : public State
{
private:
    Scene scene;
    Character *currentCharacter;
    Character *otherCharacter;
    Bar *healthBar_newton;
    Bar *healthBar_arquimedes;
public:
    EndTurn();
    
    States getName();
    void onEnter();
    void events();
    void logic();
    void render();
};
