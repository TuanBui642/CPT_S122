/*
*	Program: PA9 (Group Game Project)
*	Date: 4/12/25
*	Group:
*		Tuan Bui
*		Ashton Palma
*		Tyler Simmons
*		Brandon Weirth
*
*	File Programmer: Tyler Simmons
*/

#ifndef GAMESTATE
#define GAMESTATE

#include <iostream>
using std::cout;
using std::endl;
#include "State.hpp"	//this is a derived class of State
#include "Enemy.hpp"
#include "gameWorld.hpp"

class GameState : public State {
public:
    GameState(sf::RenderWindow* window);
    virtual ~GameState();

    //member functions
    void updateInput(const float& deltaTime);
    void update(const float& deltaTime);
    void render(sf::RenderTarget* target = nullptr);


private:
    //Initalization for Game (Possible Entities Present in Game)
    Player* mPlayer;
    bool mJumpUsed;

    Enemy* mEnemy1;
    Enemy* mEnemy2;
    Enemy* mEnemy3;
    Enemy* mEnemy4;
    Enemy* mEnemy5;

    gameWorld worldLayout;

    //Time (real world seconds) usage
    sf::Clock OngoingTime;
    sf::Time Time;


    //member functions
    bool checkJump();
    void initKeyBindings();
    void initTextures();
    void initPlayers();
    void initEnemies();

    //initiate world's object and environment
    void initWorld();

};

#endif