#include "Attacking.h"
#include "Game.hpp"

extern Game *game;

Attacking::Attacking()
{
	
}

void Attacking::onEnter() 
{
	game->team1.at(0).setPosY(450); // TODO: REMOVER
	game->team1.at(0).setOrientation(ORIENTATION_RIGHT);
	object = new Object(game->team1.at(0).getPosX() + 11, game->team1.at(0).getPosY() + 50);
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
		game->team2.at(0).getCollisionList()
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
	game->renderer.addTexture(game->team1.at(0).getTexture());
	game->renderer.addTexture(game->team2.at(0).getTexture());
	if(!done) 
	{
		game->renderer.addTexture(object->getTexture());
	}
	game->renderer.render();
}

States Attacking::getName() {
	return STATE_ATTACKING;
}
