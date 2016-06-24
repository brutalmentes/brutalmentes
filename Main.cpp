
#include <string>
#include "Game.hpp"

Game *game = new Game();//pegar uma lista de jogadores

int main(int argc, char *argv[])
{
    
    // seleciona os jogadores das equipes;
    Arquimedes arquimedes;
    Newton newton;
    list<Character> team1,team2;
    
    team1.push_front(newton);
    team2.push_front(arquimedes);
    
    // cria as equipes
    game->createTeams(team1,team2);
    game->audio.playSound("SG05", -1);
    
    if(!game->renderer.init())
    {
        game->stateMachine->setState(STATE_EXIT);
    }
    
    State* currentState = game->stateMachine->getCurrentState();
    
    while(currentState->getName() != STATE_EXIT)
    {
        
        // pega o primeiro jogador da lista de jogadores
        // realiza o turno com o jogador
        // verifica se alguem morreu
        currentState->events();
        currentState->logic();
        currentState->render();
        
        currentState = game->stateMachine->getCurrentState();
    }
    
    delete currentState;
    
    return 0;
}
