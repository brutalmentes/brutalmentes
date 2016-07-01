#pragma once
//lista dos sons
#include <string>
#include <map>
#include <SDL2/SDL_mixer.h>

class Audio
{

 private:
	 char* track1;
	 char* track2;
	 char* track3;
	 char* track4;  
	 char* track5;
	 char* track6; 
	 char* track7;
	 char* track8;
	 char* track9; 
	 char* track10;
	 char* track11;
	 char* track12;
	 char* track13;

	 Mix_Chunk* gTrack1;
	 Mix_Chunk* gTrack2; 
	 Mix_Chunk* gTrack3;
	 Mix_Chunk* gTrack4;
	 Mix_Chunk* gTrack5;
	 Mix_Chunk* gTrack6;
	 Mix_Chunk* gTrack7;
	 Mix_Chunk* gTrack8;
	 Mix_Chunk* gTrack9;
	 Mix_Chunk* gTrack10;
	 Mix_Chunk* gTrack11;
	 Mix_Chunk* gTrack12;
	 Mix_Chunk* gTrack13;
     
	 std::map<std::string, Mix_Chunk*> tracks; 
 public:
       Audio();
       int loadAudio();
       void playSound(std::string id, int loop);
};
