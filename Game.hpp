#ifndef Game_hpp
#define Game_hpp

#include <stdio.h>
#include <list>
#include "StateMachine.h"
#include "Renderer.h"
#include "CollisionDetector.h"
#include "State.h"
#include "Character.h"
#include "Audio.h"
#include "Newton.h"
#include "Arquimedes.h"
//#include "player.h"

using namespace std;

class Game
{
public:
    list<Character> team1; //os times devem ter o mesmo numero de jogadores
    list<Character> team2;
    list<Character> playerSequency;
    int winnerTeam;
    Renderer renderer;
    CollisionDetector collisionDetector;
    Audio audio;
    StateMachine stateMachine;
    
    //Game(list<Character> team1,list<Character> team2); //minimo 2 jogadores
    Game();
    //void addPlayer(int team, Character player); // adiciona jogador a uma equipe
    void createTeams(list<Character> team1, list<Character> team2);// cria as equipes
    void killPlayer(Character p); //retira o jogador do jogo
    bool exitGame();
    void executeTurn(Character p);
    bool VerifyDeaths(); //função que executa as mortes e retorna true caso alguém morreu
    bool VerifyWinner(); //retorna true caso todos os jogadores de uma equipe estiverem mortos
    int returnWinner(); //retorna a variável equipeVencedora
    void executeWinnerMessage(int equipeVencedora); //executa animações para a equipe vencedora
    void endGame();
    
};
#endif /* Game_hpp */
