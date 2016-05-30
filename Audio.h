//lista dos sons
#include <string>
#include <SDL_mixer.h>

class Audio
{

 private:
	 char* track1;
	 Mix_Chunk* gScratch;
         
 public:
       Audio();
       int threadFunction( void*data);
       int loadAudio();
       static int threadFuncWrapper(void *data);
};
