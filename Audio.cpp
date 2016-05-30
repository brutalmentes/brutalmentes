#include <stdio.h>
#include <string>
#include <SDL_thread.h>
#include <SDL_mixer.h>
#include "audio.h"

Audio::Audio()
{
	track1 = "snd/Brutalmentes_theme_sample_-_29_04_16_11.wav";
	gScratch = NULL;

    loadAudio();
    SDL_Thread *thread = SDL_CreateThread (threadFuncWrapper, NULL, this);
}


int Audio:: threadFunction( void*data)
{
	  Mix_PlayChannelTimed(-1, gScratch, 0 ,-1);
      return 0;
}

int Audio::loadAudio()
{
    int success = 1;
    gScratch = Mix_LoadWAV( track1  );
   
    if( gScratch == NULL )
    {
		printf( "Failed to load scratch sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
        success = 0;
    }
 
   return success;
}


int Audio::threadFuncWrapper(void *data)
{
   Audio* self = static_cast<Audio*>(data);
   return self->threadFunction(data);
}

