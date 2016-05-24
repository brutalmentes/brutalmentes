#ifndef BTIMER
#define BTIMER

#include <SDL_thread.h>

class Btimer
{
    private:
        float tempoMs;
        SDL_Thread *thread;

    public:

       Btimer();
       ~Btimer();
       int threadFunction(void *data);
       static int thread_func_wrapper(void *data);
       float getTempo();
};

#endif
