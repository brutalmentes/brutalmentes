#include "Attacking.h"
#include "Game.hpp"

extern Game *game;

Attacking::Attacking()
{
	
}

void Attacking::onEnter() 
{
	//game->getCurrentCharacter->setPosY(450); // TODO: REMOVER
	//game->getCurrentCharacter->setOrientation(ORIENTATION_RIGHT);
	object = new Object(game->getCurrentCharacter()->getPosX() + 11, game->getCurrentCharacter()->getPosY() + 50);
	launch = new Launch(50.0f, 1.0472f);
	timer = new Btimer();
	physics = new Physics();
	physics->start(object, launch, timer);

	done = false;
}

void Attacking::events()
{
	SDL_Event event;

	while( SDL_PollEvent( &event ) )
	{
		if( event.type == SDL_QUIT )
	    {
			game->stateMachine->setState(STATE_EXIT);
	    }
	}
}

void Attacking::logic()
{
	bool collidedWithScene = game->collisionDetector.hasCollision(
		object->getCollisionList(), 
		game->scene.getCollisionList()
	);

	bool collidedWithEnemy = game->collisionDetector.hasCollision(
		object->getCollisionList(), 
		game->getOtherCharacter()->getCollisionList()
                                                                
	);

	if(!done && (collidedWithScene || collidedWithEnemy)) {
		physics->stop();
		game->audio.playSound("AC02-1", 0);
		done = true;
	}
}

void Attacking::render()
{	
	game->renderer.clear();
	game->renderer.addTexture(game->scene.getTexture());
	game->renderer.addTexture(game->getCurrentCharacter()->getTexture(3));
	game->renderer.addTexture(game->getOtherCharacter()->getTexture(3));
	if(!done) 
	{
		game->renderer.addTexture(object->getTexture());
	}
	game->renderer.render();
}

States Attacking::getName() {
	return STATE_ATTACKING;
}
