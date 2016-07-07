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
#include "Scene.h"

using namespace std;

class Game
{
private:
    float force;
    float angle;

public:
    vector<Character> team1; //os times devem ter o mesmo numero de jogadores
    vector<Character> team2;
    vector<Character> playerSequence;
    int winnerTeam;
    Renderer renderer;
    CollisionDetector collisionDetector;
    Audio audio;
    StateMachine *stateMachine;
    Scene scene;

    // TODO: integrar com base em CurrentPlayer e CurrentEnemy

    Game();
    void createTeams(vector<Character> team1, vector<Character> team2);// cria as equipes
    Character* getCurrentCharacter();
    Character* getOtherCharacter();
    void nextCharacter();
    void setForceAng(float force, float angle);
    float getForce();
    float getAngle();    
};
#endif /* Game_hpp */
