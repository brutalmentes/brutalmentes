#include <SDL2/SDL.h>
#include <stdio.h>
#include <string>
#include <SDL2/SDL_thread.h>
#include <SDL2/SDL_mixer.h>
#include "btimer.h"



Btimer::Btimer(int adsa)
{
  printf("contruiu a thread");
 // SDL_Thread *thread = SDL_CreateThread (thread_func_wrapper, NULL, this);
}


int Btimer::thread_func_wrapper(void *data)
{
   Btimer* self = static_cast<Btimer*>(data);
   return self->threadFunction(data);
}



int Btimer:: threadFunction( void*data)
{        printf("porra");
	//SDL_Delay(250);
	return 1;
           

}

/*

int main()
{
Btimer a(1);
return 1;

}*/
