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
        this->playerSequency.push_back(team1[i]);
        this->playerSequency.push_back(team2[j]);
        j++;
    }
}

bool Game::exitGame()
{
    return false;
}

void Game::executeTurn(Character p)
{
    //joga o turno com o jogador
}

bool Game::verifyDeaths()
{
    //loop com todos os jogadores pra ver se algum está com a vida = 0
    for (int i=0; i<this->playerSequency.size(); i++)
    {
        //verifica se algum character da lista está morto
        if (this->playerSequency[i].getHealth()==0)
        {
            return true;
        }
    }
    return false;
}

void Game::killPlayer(Character p)
{
    //mata o jogador
    // remove jogador das listas
}

bool Game::gameHasWinner()
{
    int livingPlayers = 0;
    
    // verifica se todos os jogadores da equipe 1 estão mortos
    for (int i=0; i< this->team1.size(); i++)
    {   //verifica se algum character da lista está vivo
        if (this->team1[i].getHealth()) livingPlayers++;
        
    }
    if (livingPlayers==0)
    {   //todos os jogadores da equipe 1 estão mortos
        this->winnerTeam = 2; // equipe 2 venceu
        return true;
    }
    livingPlayers = 0;
    
    // verifica se todos os jogadores da equipe 1 estão mortos
    for (int i=0; i<this->team2.size(); i++)
    {   //verifica se algum character da lista está vivo
        if (this->team2[i].getHealth()) livingPlayers++;
        
    }
    if (livingPlayers==0)
    {   //todos os jogadores da equipe 2 estão mortos
        this->winnerTeam = 1; // equipe 1 venceu
        return true;
    }
    return false;
}

int Game::getWinner()
{
    //retorna a equipe vencedora
    return winnerTeam;
}

void Game::executeWinnerMessage(int equipeVencedora)
{
    
}
void Game::endGame()
{
    // apaga as variaveis e termina com o jogo
}