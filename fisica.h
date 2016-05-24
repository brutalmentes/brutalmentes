#ifndef PHYSICS
#define PHYSICS

#include "object.h"
#include "launch.h"
#include "btimer.h"

#include <SDL_thread.h>

class Physics
{
 private:
	 Launch *launch;
	 Object *object;
	 bool stp;
	 SDL_Thread *thread;
	 Btimer *tempo;
	 float tempoInicial;
	 float tempoAnt;

 public:
       Physics();
       ~Physics();
       void start(Object* object,Launch* launch, Btimer* tempo);
       void stop();
       void positionProcess( );
       static int thread_func_wrapper(void *data);
       int threadFunction( void*data);
};

#endif
