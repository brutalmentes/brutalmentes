#include "MoveCharacter.h"
#include "State.h"
#include "StateMachine.h"
#include "CollisionDetector.h"
#include "Renderer.h"
#include "Newton.h"
#include "Scene.h"
#include "Button.h"
#include "Timer.h"
#include "Game.hpp"
#include <list>
#include <sstream>
 
using namespace std;
 
extern Game game;
 
int mVelX = 0;
int DOT_VEL = 4;
Orientation orientation = ORIENTATION_RIGHT;
SDL_Color textColor = { 0, 0, 0 };
Text *text;
Timer timer;
 
MoveCharacter::MoveCharacter()
{
    this->currentCharacter = &newton;
    this->btnAttack = new Button(BTN_ATTACK, "res/img/btn_atacar.png", 449, 250);
    this->btnDefense = new Button(BTN_DEFENSE, "res/img/btn_defender.png", 625, 250);
    
	//this->healthBar_newton = new Bar(800, 20);
    //this->healthBar_arquimedes = new Bar(100, 20);
	
    ostringstream temp;
    temp << "00:08";
    text = new Text(temp.str().c_str(), textColor, 530, 20);
     
    while(!game.collisionDetector.hasCollision(scene.getCollisionList(), newton.getCollisionList()))
    {
        newton.setPosY(newton.getPosY() + 1);
    }
 
    newton.setPosY(newton.getPosY() - 1);
 
    while(!game.collisionDetector.hasCollision(scene.getCollisionList(), arquimedes.getCollisionList()))
    {
        arquimedes.setPosY(arquimedes.getPosY() + 1);
    }
 
    timer.start();
 
    arquimedes.setPosY(arquimedes.getPosY() - 1);
    arquimedes.setOrientation(ORIENTATION_LEFT);
}
 
void MoveCharacter::events()
{
    SDL_Event event;
 
    while( SDL_PollEvent( &event ) )
    {
        if( event.type == SDL_QUIT )
        {
            game.stateMachine.setState(STATE_EXIT);
        }
 
        if(event.type == SDL_KEYDOWN && event.key.repeat == 0) 
        {
            switch(event.key.keysym.sym) 
            {
                case SDLK_ESCAPE: game.stateMachine.setState(STATE_EXIT); break;
                case SDLK_LEFT: mVelX -= DOT_VEL; orientation = ORIENTATION_LEFT; break;
                case SDLK_RIGHT: mVelX += DOT_VEL; orientation = ORIENTATION_RIGHT; break;
            }
        } 
 
        if(event.type == SDL_KEYUP && event.key.repeat == 0) 
        {
            switch(event.key.keysym.sym) 
            {
                case SDLK_LEFT: mVelX += DOT_VEL; break;
                case SDLK_RIGHT: mVelX -= DOT_VEL; break;
            }
        }
 
        this->btnContinue.handleEvent(&event);
        this->btnAttack->handleEvent(&event);
        this->btnDefense->handleEvent(&event);
         
        if(event.type == SDL_USEREVENT)
        {
            game.audio.playSound("SG03", 0);
             
            switch(event.user.code) {
                case BTN_ATTACK:
                    game.stateMachine.setState(STATE_ATTACK);
                    break;
                case BTN_DEFENSE:
                    if(this->currentCharacter == &newton)
                    {
                        orientation = ORIENTATION_LEFT;
                        this->currentCharacter = &arquimedes;
                        timer.stop();
                        timer.start();
                    }
                    break;
                default:
                    game.stateMachine.setState(STATE_EXIT);
                    break;
            }
        }
    }
}
 
void MoveCharacter::logic()
{
    free(text);
    ostringstream temp;
    temp << "00:" << "0" << (9 - timer.getTicks()/1000);
    text = new Text(temp.str().c_str(), textColor, 530, 20);
 
    if(currentCharacter == &arquimedes)
    {
        game.audio.playSound("M03", 0);
    }
 
    if((timer.getTicks()/1000) > 8) 
    {
        SDL_Event event;
        event.type = SDL_USEREVENT;
        SDL_PushEvent(&event);
 
        timer.stop();
        timer.start();
    }
 
    currentCharacter->setOrientation(orientation);
    currentCharacter->setPosX(currentCharacter->getPosX() + mVelX);
 
    while(game.collisionDetector.hasCollision(scene.getCollisionList(), currentCharacter->getCollisionList()))
    {
        currentCharacter->setPosY(currentCharacter->getPosY() - 1);
    };
 
    while(!game.collisionDetector.hasCollision(scene.getCollisionList(), currentCharacter->getCollisionList()))
    {
        currentCharacter->setPosY(currentCharacter->getPosY() + 1);
    };
}
 
void MoveCharacter::render()
{   
    game.renderer.clear();
    game.renderer.addTexture(this->scene.getTexture());
    game.renderer.addTexture(this->newton.getTexture());  
    game.renderer.addTexture(this->arquimedes.getTexture());
    game.renderer.addTexture(this->btnContinue.getTexture());
    game.renderer.addTexture(this->btnAttack->getTexture());
    game.renderer.addTexture(this->btnDefense->getTexture());
    game.renderer.addText(text);
    //game.renderer.addTextureWithSize(this->healthBar_newton->getTexture(this->newton.getLevel()),this->newton.getHealth(),30);
    //game.renderer.addTextureWithSize(this->healthBar_arquimedes->getTexture(this->arquimedes.getLevel()),this->arquimedes.getHealth(),30);
    game.renderer.render();
}
 
States MoveCharacter::getName() {
    return STATE_MOVE_CHARACTER;
}