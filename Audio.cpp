#include <stdio.h>
#include <string>
#include <SDL2/SDL_thread.h>
#include <SDL2/SDL_mixer.h>
#include "Audio.h"

Audio::Audio()
{
    Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 );
    loadAudio();
}

void Audio::playSound(std::string id, int loop)
{
  std::string dir ("audio/");
  std::string extension (".wav");
 
  Mix_PlayChannel(-1,tracks[dir+id+extension], loop);
}

int Audio::loadAudio()
{  
    int success = 1;
    gTrack1 = Mix_LoadWAV(track1);
    tracks[track1]=gTrack1;
    gTrack2 = Mix_LoadWAV(track2);
    tracks[track2]=gTrack2;
    gTrack3 = Mix_LoadWAV( track3  );
    tracks[track3]=gTrack3;
    gTrack4 = Mix_LoadWAV( track4  );
    tracks[track4]=gTrack4;
    gTrack5 = Mix_LoadWAV( track5  );
    tracks[track5]=gTrack5;
    gTrack6 = Mix_LoadWAV( track6  );
    tracks[track6]=gTrack6;
    gTrack7 = Mix_LoadWAV( track7  );
    tracks[track7]=gTrack7;
    gTrack8 = Mix_LoadWAV( track8  );
    tracks[track8]=gTrack8;
    return success; 
}

