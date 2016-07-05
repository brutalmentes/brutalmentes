#include "Game.hpp"
using namespace std;

Game::Game()
{
    this->stateMachine = new StateMachine;
}

void Game::createTeams(vector<Character> team1, vector<Character> team2)
{
    // adiciona jogadores ao time 1
    for (int i=0; i<team1.size(); i++)
    {
        this->team1.push_back(team1[i]);
    }
    
    // adiciona jogadores ao time 2
    for (int i=0; i<team2.size(); i++)
    {
        this->team2.push_back(team2[i]);
    }
    
    // intercala os jogadores em uma lista
    int j=0;//inicia indice do time 2
    for (int i=0; i<team1.size(); i++)
    {
        this->playerSequence.push_back(team1[i]);
        this->playerSequence.push_back(team2[j]);
        j++;
    }
}


Character* Game::getCurrentCharacter()
{
    return &this->playerSequence[0];
}

Character* Game::getOtherCharacter()
{
    return &this->playerSequence[1];
}

void Game::nextCharacter()
{
    Character aux = playerSequence[0];
    this->playerSequence[0] = this->playerSequence[1];
    this->playerSequence[1] = aux;
}
