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

}

void MoveCharacter::events()
{
	SDL_Event event;

	while( SDL_PollEvent( &event ) )
    {
        if( event.type == SDL_QUIT )
        {
			stateMachine.setState(States::STATE_EXIT);
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
	newton.setPosX(newton.getPosX() + mVelX);
}

void MoveCharacter::render()
{	
	renderer.clear();
	renderer.addTexture(this->scene.getTexture());
	renderer.addTexture(this->newton.getTexture());	
	renderer.render();
}

States MoveCharacter::getName() {
	return States::STATE_MOVE_CHARACTER;
}
