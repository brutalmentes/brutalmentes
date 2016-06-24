#include "Attacking.h"
#include "Game.hpp"

extern Game game;

Attacking::Attacking()
{
	
}

void Attacking::onEnter() 
{
	game.team1.at(0).setPosY(520); // TODO: REMOVER
	game.team1.at(0).setOrientation(ORIENTATION_RIGHT);
	object = new Object(game.team1.at(0).getPosX() + 11, game.team1.at(0).getPosY() + 50);
	launch = new Launch(2.0f, 0.785398f);
	timer = new Btimer();
	physics = new Physics();
	physics->start(object, launch, timer);
}

void Attacking::events()
{
	SDL_Event event;

	while( SDL_PollEvent( &event ) )
	{
		if( event.type == SDL_QUIT )
	    {
			game.stateMachine.setState(STATE_EXIT);
	    }
	}
}

void Attacking::logic()
{

}

void Attacking::render()
{	
	game.renderer.clear();
	game.renderer.addTexture(game.scene.getTexture());
	game.renderer.addTexture(game.team1.at(0).getTexture());
	game.renderer.addTexture(object->getTexture());
	game.renderer.render();
}

States Attacking::getName() {
	return STATE_ATTACKING;
}
