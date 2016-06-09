#include "MoveCharacter.h"
#include "State.h"
#include "StateMachine.h"
#include "CollisionDetector.h"
#include "Renderer.h"
#include "Newton.h"
#include "Scene.h"
#include "Button.h"
#include "Timer.h"
#include "Audio.h"
#include <list>
#include <sstream>

using namespace std;

extern StateMachine stateMachine;
extern Renderer renderer;
extern CollisionDetector collisionDetector;
extern Audio audio;

int mVelX = 0;
int DOT_VEL = 4;
Orientation orientation = ORIENTATION_RIGHT;
SDL_Color textColor = { 0, 0, 0 };
Text *text;
Timer timer;

MoveCharacter::MoveCharacter()
{
	this->currentCharacter = &newton;
	this->btnAttack = new Button("res/img/btn_atacar.png", 449, 250);
	this->btnDefense = new Button("res/img/btn_defender.png", 625, 250);
	
	ostringstream temp;
	temp << "00:08";
	text = new Text(temp.str().c_str(), textColor, 530, 20);
	
	while(!collisionDetector.hasCollision(scene.getCollisionList(), newton.getCollisionList()))
	{
		newton.setPosY(newton.getPosY() + 1);
	}

	newton.setPosY(newton.getPosY() - 1);

	while(!collisionDetector.hasCollision(scene.getCollisionList(), arquimedes.getCollisionList()))
	{
		arquimedes.setPosY(arquimedes.getPosY() + 1);
	}

	timer.start();

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
			stateMachine.setState(STATE_EXIT);
        }

		if(event.type == SDL_KEYDOWN && event.key.repeat == 0) 
		{
			switch(event.key.keysym.sym) 
			{
				case SDLK_ESCAPE: stateMachine.setState(STATE_EXIT); break;
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
			audio.playSound("SG03", 0);

			if(this->currentCharacter == &newton)
			{
				orientation = ORIENTATION_LEFT;
				this->currentCharacter = &arquimedes;
				timer.stop();
				timer.start();
			}
			else
			{
				stateMachine.setState(STATE_EXIT);
			}			
		}
    }
}

void MoveCharacter::logic()
{
	free(text);
	ostringstream temp;
	temp << "00:" << "0" << (9 - timer.getTicks()/1000);
	text = new Text(temp.str().c_str(), textColor, 530, 20);

	if(currentCharacter == &arquimedes)
	{
		audio.playSound("M03", 0);
	}

	if((timer.getTicks()/1000) > 8) 
	{
		SDL_Event event;
		event.type = SDL_USEREVENT;
		event.user.code = EVENT_BUTTON_CLICKED;
		SDL_PushEvent(&event);

		timer.stop();
		timer.start();
	}

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
	renderer.addTexture(this->btnAttack->getTexture());
	renderer.addTexture(this->btnDefense->getTexture());
	renderer.addText(text);
	renderer.render();
}

States MoveCharacter::getName() {
	return STATE_MOVE_CHARACTER;
}
