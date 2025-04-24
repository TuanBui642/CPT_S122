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

#ifndef GAME
#define GAME

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include "Portal.hpp"
#include "Platform.hpp"
#include "Enemy.hpp"
#include "GameState.hpp"
#include "State.hpp"
using std::cout;
using std::endl;

class Game {
public:
    Game();
    virtual ~Game();

    //member functions

    void endApp();
    void update();
    void updateSFMLEvents();
    void updateDeltaTime();

    void render();

    void run();

    void drawMenu();

private:
    //data members
    sf::RenderWindow* mWindow;	//this is a pointer to the main window
    float mDeltaTime;			//the time it takes to run through one game loop
    sf::Clock mDTClock;			//the clock that is needed to keep track of the gameloop time
    std::stack<State*> mStates;	//stack of states, keeps track of different types of states game gets in
    //std::map<std::string, int> mSupportedKeys;	//an array-like structure of supported keys

    //private member functions
    //initialization
    void initWindow();
    void initKeys();
    void initStates();
};

#endif