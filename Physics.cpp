/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
and may not be redistributed without written permission.*/

#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <string>
#include <SDL2/SDL_mixer.h>
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
    this->tempoAnt = tempo->getTime();

    this->object->mVelY = this->launch->initialSpeedY();
}

void Physics::stop()
{
 	this->stp = true;
}

void Physics::positionProcess( )
{
    while(true) 
	{
		float dt;

        while(!stp)
        {
            dt = tempo->getTime() - tempoAnt;

            if(dt != tempoAnt)
			{
                object->setPosX(launch->getNextPositionX(object->getPosX(), launch->getNextSpeedX(), dt));
                object->mVelY = launch->getNextSpeedY(object->mVelY, 2.0f, dt);
                object->setPosY(launch->getNextPositionY(object->getPosY(), -object->mVelY, dt));

                std::cout << "dt: "<< dt << "\n";
                //std::cout << "mPosx: "<< object->getPosX() << "\n";
                //std::cout << "mPosy: " << object->getPosY() << "\n";
                tempoAnt += dt;
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


