#include "EndTurn.h"
#include "Game.hpp"
#include "Timer.h"

using namespace std;

extern Game *game;
extern Timer timer;

EndTurn::EndTurn()
{
    
    this->currentCharacter = game->getCurrentCharacter();
    this->otherCharacter = game->getOtherCharacter();
   	timer.start();
}

void EndTurn::onEnter()
{
    
}

void EndTurn::events()
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


void EndTurn::logic()
{
    
    // verifica se alguem morreu e mata os jogadores
    if (this->currentCharacter->getHealth()<=0 && this->otherCharacter->getHealth()>0)
    {
        //jogador corrente morreu, outro jogador venceu
    }
    else if (this->otherCharacter->getHealth()<=0 && this->currentCharacter->getHealth()>0)
    {
        
        //jogador corrente venceu
        
    }
    else if (this->otherCharacter->getHealth()<=0 && this->currentCharacter->getHealth()<=0)
    {
        //empate
    }
    
    // troca o jogador
    game->nextCharacter();
    
    //chama o novo estado
    game->stateMachine->setState(STATE_MOVE_CHARACTER);
    
}

void EndTurn::render()
{
    game->renderer.clear();
    game->renderer.addTexture(this->scene.getTexture());
    game->renderer.addTexture(this->currentCharacter->getTexture(0));
   	game->renderer.addTexture(this->otherCharacter->getTexture(0));
    game->renderer.render();
    
}

States EndTurn::getName() {
    return STATE_END_TURN;
}

