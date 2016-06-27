#include "AttackState.h"
#include "State.h"
#include "StateMachine.h"
#include "CollisionDetector.h"
#include "Renderer.h"
#include "Newton.h"
#include "Scene.h"
#include "Game.hpp"
#include "Button.h"
#include "Timer.h"
#include "Audio.h"
#include "MoveCharacter.h"
#include <list>
#include <sstream>

using namespace std;

extern Game *game;

extern StateMachine stateMachine;
extern Renderer renderer;
extern CollisionDetector collisionDetector;
extern Audio audio;

extern int mVelX;
extern int DOT_VEL;
extern Orientation orientation;
extern SDL_Color textColor;
extern Text *text;
extern Timer timer;

int force;

AttackState::AttackState()
{
	this->currentCharacter = &newton;
	this->forceBar = new Bar(100,100);
   	this->healthBar_newton = new Bar(100, 20);
    	this->healthBar_arquimedes = new Bar(800, 20);

  	ostringstream temp;
  	temp << "00:08";
  	text = new Text(temp.str().c_str(), textColor, 530, 20);
     
   	while(!game->collisionDetector.hasCollision(scene.getCollisionList(), newton.getCollisionList()))
  	{
   	   newton.setPosY(newton.getPosY() + 1);
    	}
 
   	newton.setPosY(newton.getPosY() - 1);
 
   	while(!game->collisionDetector.hasCollision(scene.getCollisionList(), arquimedes.getCollisionList()))
        {
   	    arquimedes.setPosY(arquimedes.getPosY() + 1);
 	}
 
   	timer.start();
 
   	arquimedes.setPosY(arquimedes.getPosY() - 1);
   	arquimedes.setOrientation(ORIENTATION_RIGHT);


}

void AttackState::events()
{
	
    SDL_Event event;
    Timer barTimer;
    while( SDL_PollEvent( &event ) )
    {
        if( event.type == SDL_QUIT )
        {
            game->stateMachine->setState(STATE_EXIT);
        }
 	if(event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_SPACE) 
        {
            barTimer.start();
	    force+=2;
	    if(force >100) 
	    {
		force = 100;
	    }
        }
	if(event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_SPACE)
	{
	   barTimer.stop();
	}
	
    }


}


void AttackState::logic()
{

    free(text);
    ostringstream temp;
    temp << "00:" << "0" << (9 - timer.getTicks()/1000);
    text = new Text(temp.str().c_str(), textColor, 530, 20);
 
    if(currentCharacter == &arquimedes)
    {
        game->audio.playSound("M03", 0);
    }
 
    if((timer.getTicks()/1000) > 8) 
    {
        SDL_Event event;
        event.type = SDL_USEREVENT;
        SDL_PushEvent(&event);
 
        timer.stop();
        timer.start();
    }
 
    currentCharacter->setOrientation(orientation);
    currentCharacter->setPosX(currentCharacter->getPosX() + mVelX);
 
    while(game->collisionDetector.hasCollision(scene.getCollisionList(), currentCharacter->getCollisionList()))
    {
        currentCharacter->setPosY(currentCharacter->getPosY() - 1);
    };
 
    while(!game->collisionDetector.hasCollision(scene.getCollisionList(), currentCharacter->getCollisionList()))
    {
        currentCharacter->setPosY(currentCharacter->getPosY() + 1);
    };

}

void AttackState::render()
{
	game->renderer.clear();
    	game->renderer.addTexture(this->scene.getTexture());
   	game->renderer.addTexture(this->newton.getTexture());  
   	game->renderer.addTexture(this->arquimedes.getTexture());
  	game->renderer.addTextureWithSize(this->healthBar_newton->getTexture(this->newton.getLevel()),this->newton.getHealth(),30);
   	game->renderer.addTextureWithSize(this->healthBar_arquimedes->getTexture(this->arquimedes.getLevel()),this->arquimedes.getHealth(),30);
	game->renderer.addTextureWithSize(this->forceBar->getTexture(5),100,30);
	game->renderer.addTextureWithSize(this->forceBar->getTexture(6),force,30);
  	game->renderer.render();
}

States AttackState::getName() {
	return STATE_ATTACK;
}
