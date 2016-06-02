#include <stdio.h>
#include <string>
#include <SDL2/SDL_thread.h>
#include <SDL2/SDL_mixer.h>
#include "Audio.h"

Audio::Audio()
{
	Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 );
	if(!loadAudio())	
	{
		printf( "SDL could not load audio's files! SDL Error: %s\n", SDL_GetError() );
	}	
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
	
	if(gTrack1 == NULL)
	{
		success=0;
	}

	gTrack2 = Mix_LoadWAV(track2);
	tracks[track2]=gTrack2;
	
	if(gTrack2 == NULL)
	{
		success=0;
	}
	
	gTrack3 = Mix_LoadWAV(track3);
	tracks[track3]=gTrack3;
	
	if(gTrack3 == NULL)
	{
		success=0;
	}
	
	gTrack4 = Mix_LoadWAV(track4);
	tracks[track4]=gTrack4;
	
	if(gTrack4 == NULL)
	{
		success=0;
	}

	gTrack5 = Mix_LoadWAV(track5);
	tracks[track5]=gTrack5;
	
	if(gTrack5 == NULL)
	{
		success=0;
	}
	
	gTrack6 = Mix_LoadWAV(track6);
	tracks[track6]=gTrack6;
	
	if(gTrack6 == NULL)
	{
		success=0;
	}
/* TODO missing wav
	gTrack7 = Mix_LoadWAV(track7);
	tracks[track7]=gTrack7;
	
	if(gTrack7 == NULL)
	{
		success=0;
	}
*/	
	gTrack8 = Mix_LoadWAV(track8);
	tracks[track8]=gTrack8;
	
	if(gTrack8 == NULL)
	{
		success=0;
	}

    	gTrack9 = Mix_LoadWAV(track9);
	tracks[track9]=gTrack9;
	
	if(gTrack9 == NULL)
	{
		success=0;
	}
	
	gTrack10 = Mix_LoadWAV(track10);
	tracks[track10]=gTrack10;
	
	if(gTrack10 == NULL)
	{
		success=0;
	}
	gTrack11 = Mix_LoadWAV(track11);
	tracks[track11]=gTrack11;
	
	if(gTrack11 == NULL)
	{
		success=0;
	}
	
	gTrack12 = Mix_LoadWAV(track12);
	tracks[track12]=gTrack12;
	
	if(gTrack12 == NULL)
	{
		success=0;
	}
	return success; 
}

