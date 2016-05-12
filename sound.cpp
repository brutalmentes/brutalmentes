#include <SDL2/SDL.h>
#include <stdio.h>
#include <string>
#include <SDL2/SDL_thread.h>
#include <SDL2/SDL_mixer.h>
#include "sound.h"

Sound::sound()
{
    printf("passeeeii");
loadAudio();
SDL_Thread* threadID= SDL_CreateThread( threadFunction, "SoundThread", (void*) NULL);
}


int Sound:: threadFunction( void*data)
{
	
	  Mix_PlayChannelTimed( -1, gScratch, 0 ,-1);
return 0;

}

int Sound::loadAudio()
{
    int success = 1;
    printf("passeeeii");
    gScratch = Mix_LoadWAV( track1  );
   
    if( gScratch == NULL )
    {
	printf( "Failed to load scratch sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
         success = 0;
    }
  
   return success;
}


