#include "MoveCharacter.h"
#include "State.h"
#include "StateMachine.h"
#include "CollisionDetector.h"
#include "Renderer.h"
#include "Newton.h"
#include "Scene.h"
#include "Button.h"
#include <list>

using namespace std;

extern StateMachine stateMachine;
extern Renderer renderer;
extern CollisionDetector collisionDetector;

int mVelX = 0;
int DOT_VEL = 10;
Orientation orientation = ORIENTATION_RIGHT;

SDL_Color textColor = { 0, 0, 0 };
Text *text;

MoveCharacter::MoveCharacter()
{
	this->currentCharacter = &newton;
	text = new Text("05:00", textColor, 530, 20);
	
	while(!collisionDetector.hasCollision(scene.getCollisionList(), newton.getCollisionList()))
	{
		newton.setPosY(newton.getPosY() + 1);
	}

	newton.setPosY(newton.getPosY() - 1);

	while(!collisionDetector.hasCollision(scene.getCollisionList(), arquimedes.getCollisionList()))
	{
		arquimedes.setPosY(arquimedes.getPosY() + 1);
	}

	arquimedes.setPosY(arquimedes.getPosY() - 1);
	arquimedes.setOrientation(ORIENTATION_LEFT);
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
				case SDLK_ESCAPE: stateMachine.setState(States::STATE_EXIT); break;
				case SDLK_LEFT: mVelX -= DOT_VEL; orientation = ORIENTATION_LEFT; break;
				case SDLK_RIGHT: mVelX += DOT_VEL; orientation = ORIENTATION_RIGHT; break;
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

		this->btnContinue.handleEvent(&event);

		if(event.type == SDL_USEREVENT && event.user.code == EVENT_BUTTON_CLICKED)
		{
			if(this->currentCharacter == &newton)
			{
				orientation = ORIENTATION_LEFT;
				this->currentCharacter = &arquimedes;
			}
			else
			{
				stateMachine.setState(States::STATE_EXIT);
			}			
		}
    }
}

void MoveCharacter::logic()
{
	currentCharacter->setOrientation(orientation);
	currentCharacter->setPosX(currentCharacter->getPosX() + mVelX);

	while(collisionDetector.hasCollision(scene.getCollisionList(), currentCharacter->getCollisionList()))
	{
		currentCharacter->setPosY(currentCharacter->getPosY() - 1);
	};

	while(!collisionDetector.hasCollision(scene.getCollisionList(), currentCharacter->getCollisionList()))
	{
		currentCharacter->setPosY(currentCharacter->getPosY() + 1);
	};
}

void MoveCharacter::render()
{	
	renderer.clear();
	renderer.addTexture(this->scene.getTexture());
	renderer.addTexture(this->newton.getTexture());	
	renderer.addTexture(this->arquimedes.getTexture());
	renderer.addTexture(this->btnContinue.getTexture());
	renderer.addText(text);
	renderer.render();
}

States MoveCharacter::getName() {
	return States::STATE_MOVE_CHARACTER;
}
