#include "Game.hpp"
using namespace std;

//Game::Game(list<Character> team1, list<Character> team2)
//{
//    this->team1 = team1;
//    this->team2 = team2;
//    
//    // intercala os jogadores em uma lista
//    list<Character>::iterator it2 = team2.begin();
//    for (list<Character>::iterator it1 = team1.begin(); it1 != team1.end(); it1++)
//    {
//        this->playerSequency.push_front(*it1);
//        this->playerSequency.push_front(*it2);
//        it2++;
//    }
//    
//}
Game::Game()
{
//    // team 1
//    Character newton; //ver como declarar a classe certa!
//    this->team1.push_front(newton);
//    
//    // team 2
//    Character arquimedes; //ver como declarar a classe certa!
//    this->team2.push_front(arquimedes);
//    
//    // intercala os jogadores em uma lista
//    list<Character>::iterator it2 = team2.begin();
//    for (list<Character>::iterator it1 = team1.begin(); it1 != team1.end(); it1++)
//    {
//        this->playerSequency.push_front(*it1);
//        this->playerSequency.push_front(*it2);
//        it2++;
//    }
    
}
//
//void Game::addPlayer(int team, Character player)
//{
//    if (team == 1)
//    {
//        this->team1.push_front(player);
//    }
//    else
//    {
//        this->team2.push_front(player);
//    }
//}

void Game::createTeams(list<Character> team1, list<Character> team2)
{
    // adiciona jogadores ao time 1
    for (list<Character>::iterator it = team1.begin(); it != team1.end(); it++)
    {
        this->team1.push_back(*it);
    }
    
    // adiciona jogadores ao time 2
    for (list<Character>::iterator it = team2.begin(); it != team2.end(); it++)
    {
        this->team2.push_back(*it);
    }
    
    // intercala os jogadores em uma lista
    list<Character>::iterator it2 = team2.begin();
    for (list<Character>::iterator it1 = team1.begin(); it1 != team1.end(); it1++)
    {
        this->playerSequency.push_back(*it1);
        this->playerSequency.push_back(*it2);
        it2++;
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

bool Game::VerifyDeaths()
{
    //loop com todos os jogadores pra ver se algum está com a vida = 0
    for (list<Character>::iterator it = playerSequency.begin(); it != playerSequency.end(); it++)
    {
        //verifica se algum character da lista está morto
        if (false)
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

bool Game::VerifyWinner()
{
    // verifica se todos os jogadores da equipe 1 estão mortos
    // verifica se todos os jogadores da equipe 2 estão mortos
    return false;
}

int Game::returnWinner()
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