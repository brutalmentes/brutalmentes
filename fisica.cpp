/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
and may not be redistributed without written permission.*/

//Using SDL, SDL_image, standard IO, and strings
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <string>
#include <SDL2/SDL_thread.h>
#include <SDL2/SDL_mixer.h>
#include "launch.h"
#include "object.h"

//Screen dimension constants
Physics::Physics()
{
  	SDL_Thread *thread = SDL_CreateThread (thread_func_wrapper, NULL, this); 
}
void Physics::start(Object* object,Launch* launch)
{
        this->launch=launch;
        this->object=object;
	stp=false;

}
void Physics::stop()
{
 
 	stp=true;

}

void positionProcess( )
{
        while(!stp)
	{
		tempo+=0.01;
		velx=launch.getnextspeedx();
		vely=launch.getnextspeedy(vely,0,tempo);
		object.mPosX=launch.getnextpositionx(object.mPosX,velx,tempo);
		object.mPosY=launch.getnextpositiony(object.mPosY,vely,tempo)
	}
}
		
