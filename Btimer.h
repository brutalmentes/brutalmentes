#ifndef BTIMER
#define BTIMER

#include <SDL_thread.h>

class Btimer
{
    private:
        float timeMs;
        SDL_Thread *thread;

    public:

       Btimer();
       ~Btimer();
       int threadFunction(void *data);
       static int threadFuncWrapper(void *data);
       float getTime();
};

#endif
