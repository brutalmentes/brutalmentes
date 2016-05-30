#include <stdio.h>
#include <string>
#include <SDL2/SDL_thread.h>
#include <SDL2/SDL_mixer.h>
#include "Audio.h"

Audio::Audio()
{
    printf("constroi \n");
    Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 );
    loadAudio();
}

void Audio::playSound(std::string id, int loop)
{
  printf("recebe ordem para tocar %s \n",id);  
  Mix_PlayChannel(-1,tracks[id], loop);
}

int Audio::loadAudio()
{  
   printf("carrega os audios \n"); 
    int success = 1;
    gTrack1 = Mix_LoadWAV(track1);
    tracks[track1]=gTrack1;
 /*   gTrack2 = Mix_LoadWAV( track2  );
    tracks[id++]=gTrack2;
    gTrack3 = Mix_LoadWAV( track3  );
    tracks[id++]=gTrack3;
    gTrack4 = Mix_LoadWAV( track4  );
    tracks[id++]=gTrack4;
    gTrack5 = Mix_LoadWAV( track5  );
    tracks[id++]=gTrack5;
    gTrack6 = Mix_LoadWAV( track6  );
    tracks[id++]=gTrack6;
    gTrack7 = Mix_LoadWAV( track7  );
    track[id++]=gTrack7;
    gTrack8 = Mix_LoadWAV( track8  );
    track[id++]=gTrack8;
*/    return success; 
}

