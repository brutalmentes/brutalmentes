#include "InitialState.h"
#include "Game.hpp"
#include "Renderer.h"

extern Game *game;

InitialState::InitialState()
{
    this->menu = new Menu();
}

void InitialState::events()
{
    SDL_Event event;

    while( SDL_PollEvent( &event ) )
    {
        if( event.type == SDL_QUIT )
        {
            game->stateMachine->setState(STATE_EXIT);
        }

        if( event.type == SDL_MOUSEBUTTONDOWN ){
            SDL_Point mousePos = {event.button.x, event.button.y};
            if(SDL_EnclosePoints(&mousePos, 1, menu->getBoxJogar(), NULL) ){
                game->stateMachine->setState(STATE_MOVE_CHARACTER);
            }
            if(SDL_EnclosePoints(&mousePos, 1, menu->getBoxSair(), NULL) ){
                game->stateMachine->setState(STATE_EXIT);
            }
        }
    }
}

void InitialState::render()
{
    game->renderer.clear();
    game->renderer.addTexture(this->menu->getTexture());
    game->renderer.render();
}

States InitialState::getName() {
    return STATE_INIT_GAME;
}

void InitialState::logic()
{}

void InitialState::onEnter()
{

}
