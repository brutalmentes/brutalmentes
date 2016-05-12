//lista dos sons
#include <string>
class Audio
{

 private:
	 char*  track1= "21_sound_effects_and_music/Brutalmentes_theme_sample_-_29_04_16_11.wav";
	Mix_Chunk* gScratch = NULL;
         
 public:
       Audio();
       int threadFunction( void*data);
       int loadAudio();
       static int thread_func_wrapper(void *data);
};
