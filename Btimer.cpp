#include <stdio.h>
#include <string>
#include <SDL2/SDL.h>
#include "Btimer.h"

#include <iostream>

Btimer::Btimer()
{
    timeMs = 0;
    this->thread = SDL_CreateThread (threadFuncWrapper, NULL, this);
}

Btimer::~Btimer(){}

int Btimer::threadFuncWrapper(void *data)
{
   Btimer* self = static_cast<Btimer*>(data);
   return self->threadFunction(data);
}

int Btimer:: threadFunction(void *data)
{
    while(1)
	{
        SDL_Delay(10);
        timeMs += 0.1f;
    }

	return 0;
}

float Btimer::getTime(){
    return timeMs;
}
