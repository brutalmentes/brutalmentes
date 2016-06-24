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
#include <list>
#include <sstream>

using namespace std;

extern Game *game;

extern StateMachine stateMachine;
extern Renderer renderer;
extern CollisionDetector collisionDetector;
extern Audio audio;

AttackState::AttackState()
{
	/*this->currentCharacter = &newton;
	this->forceBar = new Bar(100,100);
*/

}

void AttackState::events()
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

void AttackState::logic()
{
}

void AttackState::render()
{
	game->renderer.clear();
	//game->renderer.addTextureWithSize(this->forceBar->getTexture(5),100,30);
        game->renderer.render();
}

States AttackState::getName() {
	return STATE_ATTACK;
}
