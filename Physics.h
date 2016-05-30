#ifndef PHYSICS
#define PHYSICS

#include "Object.h"
#include "Launch.h"
#include "Btimer.h"

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
       void start(Object* object, Launch* launch, Btimer* tempo);
       void stop();
       void positionProcess();
       static int threadFuncWrapper(void *data);
       int threadFunction( void*data);
};

#endif
