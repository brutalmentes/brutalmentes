//lista dos sons
#include <string>
#include <map>
#include <SDL2/SDL_mixer.h>

class Audio
{

 private:
	 char* track1="audio/AC01.wav";
	 char* track2="audio/AC02-1.wav";
	 char* track3="audio/AC02-2.wav";
	 char* track4="audio/EJ02.wav";  
	 char* track5="audio/M01.wav";
	 char* track6="audio/M03.wav"; 
	 char* track7="audio/M04.wav";
	 char* track8="audio/RA04.wav";
	 char* track9="audio/RA05.wav"; 
	 char* track10="audio/RA06.wav";
	 char* track11="audio/SG01.wav";
	 char* track12="audio/SG03.wav";
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
         std::map<std::string, Mix_Chunk*> tracks; 
 public:
       Audio();
       int loadAudio();
       void playSound(std::string id, int loop);
};
