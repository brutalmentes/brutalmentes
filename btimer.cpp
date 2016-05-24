#include <SDL.h>
#include <stdio.h>
#include <string>
#include <SDL_mixer.h>
#include "btimer.h"

#include <iostream>

Btimer::Btimer()
{
    tempoMs = 0;
    this->thread = SDL_CreateThread (thread_func_wrapper, NULL, this);
}

Btimer::~Btimer(){}

int Btimer::thread_func_wrapper(void *data)
{
   Btimer* self = static_cast<Btimer*>(data);
   return self->threadFunction(data);
}



int Btimer:: threadFunction(void *data)
{
    while(1){
        SDL_Delay(10);
        tempoMs += 0.1;
    }

	return 0;
}

float Btimer::getTempo(){
    return tempoMs;
}
