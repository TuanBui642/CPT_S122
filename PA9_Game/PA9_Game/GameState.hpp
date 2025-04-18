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

#pragma once

#include <iostream>
using std::cout;
using std::endl;
#include "State.hpp"	//this is a derived class of State
#include "Enemy1.hpp"

class GameState : public State {
public:
    GameState(sf::RenderWindow* window);
    virtual ~GameState();

    //member functions
    void updateInput(const float& deltaTime);
    void update(const float& deltaTime);
    void render(sf::RenderTarget* target = nullptr);

private:
    Player* mPlayer;
    Enemy1* FirstEnemy;

    //member functions
    void initKeyBindings();
    void initTextures();
    void initPlayers();
    void initEnemy1();
};
