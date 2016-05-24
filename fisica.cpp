/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
and may not be redistributed without written permission.*/

//Using SDL, SDL_image, standard IO, and strings
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>

#include <SDL_mixer.h>

#include <iostream>

#include "fisica.h"

//Screen dimension constants
Physics::Physics()
{
  	this->stp = true;
  	this->thread = SDL_CreateThread (thread_func_wrapper, NULL, this);

}

Physics::~Physics(){
}

void Physics::start(Object* object,Launch* launch, Btimer* tempo)
{
    this->launch=launch;
    this->object=object;
	this->stp=false;
	this->tempo = tempo;
	this->tempoInicial = tempo->getTempo();
    this->tempoAnt = 0;
}
void Physics::stop()
{
 	this->stp=true;
}

void Physics::positionProcess( )
{
    while(1){

    float tmp = 0;
            while(!stp)
        {
            tmp = tempo->getTempo() - tempoInicial;

            if(tmp != tempoAnt){
                object->mPosX=launch->getnextpositionx(object->mPosX,launch->getnextspeedx(),tmp);
                object->mPosY=launch->getnextpositiony(object->mPosY,launch->getnextspeedy(object->mVelY,-(launch->getForce())*0.5,tmp),tmp);
                std::cout << "Tempo: "<< tmp << "\n";
                std::cout << "mPosx: "<< object->mPosX << "\n";
                std::cout << "mPosy: " << object->mPosY << "\n";
                tempoAnt = tmp;
            }

        }
    }

}

int Physics:: threadFunction( void*data)
{
        positionProcess();
        return 0;
}

int Physics::thread_func_wrapper(void *data)
{
   Physics* self = static_cast<Physics*>(data);
   return self->threadFunction(data);
}


