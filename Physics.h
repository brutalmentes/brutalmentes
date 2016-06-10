#ifndef PHYSICS
#define PHYSICS

#include "Object.h"
#include "Launch.h"
#include "Btimer.h"

#include <SDL2/SDL_thread.h>

class Physics
{
 private:
	 Launch *launch;
	 Object *object;
	 bool mStop;
	 SDL_Thread *thread;
	 Btimer *temporizador;
	 float tempoInicial;
	 float tempoAnt;

 public:
       Physics();
       ~Physics();
       void start(Object* object, Launch* launch, Btimer* temporizador);
       void stop();
       void positionProcess();
       static int threadFuncWrapper(void *data);
       int threadFunction( void*data);
};

#endif
