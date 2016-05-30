/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
and may not be redistributed without written permission.*/

#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <SDL_mixer.h>
#include <iostream>
#include "Physics.h"

//Screen dimension constants
Physics::Physics()
{
  	this->stp = true;
  	this->thread = SDL_CreateThread (threadFuncWrapper, NULL, this);
}

Physics::~Physics()
{
}

void Physics::start(Object* object, Launch* launch, Btimer* tempo)
{
    this->launch = launch;
    this->object = object;
	this->stp = false;
	this->tempo = tempo;
	this->tempoInicial = tempo->getTime();
    this->tempoAnt = 0;
}

void Physics::stop()
{
 	this->stp = true;
}

void Physics::positionProcess( )
{
    while(1) 
	{
		float tmp = 0;

        while(!stp)
        {
            tmp = tempo->getTime() - tempoInicial;

            if(tmp != tempoAnt)
			{
                object->mPosX=launch->getNextPositionX(object->mPosX,launch->getNextSpeedX(),tmp);
                object->mPosY=launch->getNextPositionY(object->mPosY,launch->getNextSpeedY(object->mVelY,-(launch->getForce())*0.5f,tmp),tmp);
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

int Physics::threadFuncWrapper(void *data)
{
   Physics* self = static_cast<Physics*>(data);
   return self->threadFunction(data);
}


