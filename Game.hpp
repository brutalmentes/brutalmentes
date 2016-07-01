#ifndef Game_hpp
#define Game_hpp

#include <stdio.h>
#include <vector>
#include "StateMachine.h"
#include "Renderer.h"
#include "CollisionDetector.h"
#include "State.h"
#include "Character.h"
#include "Audio.h"
#include "Newton.h"
#include "Arquimedes.h"

using namespace std;

class Game
{
public:
    vector<Character> team1; //os times devem ter o mesmo numero de jogadores
    vector<Character> team2;
    vector<Character> playerSequency;
    int winnerTeam;
    Renderer renderer;
    CollisionDetector collisionDetector;
    Audio audio;
    StateMachine *stateMachine;
    int posNewtonX;
    int posNewtonY;
    int posArquimedesX;
    int posArquimedesY;

    //Game(list<Character> team1,list<Character> team2); //minimo 2 jogadores
    Game();
    //void addPlayer(int team, Character player); // adiciona jogador a uma equipe
    void createTeams(vector<Character> team1, vector<Character> team2);// cria as equipes
    void killPlayer(Character p); //retira o jogador do jogo
    bool exitGame(); // comando externo para sair do jogo
    void executeTurn(Character p);
    bool verifyDeaths(); //função que executa as mortes e retorna true caso alguém morreu
    bool gameHasWinner(); //retorna true caso todos os jogadores de uma equipe estiverem mortos
    int getWinner(); //retorna a variável equipeVencedora
    void executeWinnerMessage(int equipeVencedora); //executa animações para a equipe vencedora
    void endGame();
    
};
#endif /* Game_hpp */
