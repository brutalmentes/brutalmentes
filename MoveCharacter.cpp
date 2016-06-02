#include "MoveCharacter.h"
#include "State.h"
#include "StateMachine.h"
#include "CollisionDetector.h"
#include "Renderer.h"
#include "Newton.h"
#include "Scene.h"
#include <list>

using namespace std;

extern StateMachine stateMachine;
extern Renderer renderer;
extern CollisionDetector collisionDetector;

int mVelX = 0;
int DOT_VEL = 10;

MoveCharacter::MoveCharacter()
{
	while(!collisionDetector.hasCollision(scene.getCollisionList(), newton.getCollisionList()))
	{
		newton.setPosY(newton.getPosY() + 1);
	}

	newton.setPosY(newton.getPosY() - 1);
}

void MoveCharacter::events()
{
	SDL_Event event;

	while( SDL_PollEvent( &event ) )
    {
        if( event.type == SDL_QUIT )
        {
			stateMachine.setState(STATE_EXIT);
        }

		if(event.type == SDL_KEYDOWN && event.key.repeat == 0) 
		{
			switch(event.key.keysym.sym) 
			{
				case SDLK_LEFT: mVelX -= DOT_VEL; break;
				case SDLK_RIGHT: mVelX += DOT_VEL; break;
			}
		} 

		if(event.type == SDL_KEYUP && event.key.repeat == 0) 
		{
			switch(event.key.keysym.sym) 
			{
				case SDLK_LEFT: mVelX += DOT_VEL; break;
				case SDLK_RIGHT: mVelX -= DOT_VEL; break;
			}
		}
    }
}

void MoveCharacter::logic()
{
	newton.flip(mVelX < 0);
	newton.setPosX(newton.getPosX() + mVelX);

	while(collisionDetector.hasCollision(scene.getCollisionList(), newton.getCollisionList()))
	{
		newton.setPosY(newton.getPosY() - 1);
	};

	while(!collisionDetector.hasCollision(scene.getCollisionList(), newton.getCollisionList()))
	{
		newton.setPosY(newton.getPosY() + 1);
	};
}

void MoveCharacter::render()
{	
	renderer.clear();
	renderer.addTexture(this->scene.getTexture());
	renderer.addTexture(this->newton.getTexture());	
	renderer.render();
}

States MoveCharacter::getName() {
	return STATE_MOVE_CHARACTER;
}
