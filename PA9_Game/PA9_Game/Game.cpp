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
#include "Game.hpp"

//initialize everything
Game::Game()
{
    this->initWindow();
    this->initKeys();
    this->initStates();
}

Game::~Game()
{
    delete mWindow;

    while (!mStates.empty()) {
        delete mStates.top();	//remove data
        mStates.pop();			//remove pointer
    }
}

//setup window
void Game::initWindow()
{
    unsigned int width = 1500;
    unsigned int height = 1000;

    mWindow = new sf::RenderWindow(sf::VideoMode({ width, height }), "Untitled 2D Platformer");

    mWindow->setFramerateLimit(60);	//set frame rate cap to 60 fps
}

//this is for future testing of key rebinding
void Game::initKeys()
{
    /*mSupportedKeys.emplace("Escape", sf::Keyboard::Key::Escape);
    mSupportedKeys.emplace("A", sf::Keyboard::Key::A);
    mSupportedKeys.emplace("D", sf::Keyboard::Key::D);*/
    //mSupportedKeys.emplace(" ", sf::Keyboard::Key::Space);
}

//manage states with a stack, set the first State to a GameState
void Game::initStates()
{
    mStates.push(new GameState(mWindow));
}

//end the application
void Game::endApp()
{
    cout << "Ending game." << endl;
}

void Game::update()
{
    //mainly see if the window is closed or needs to close
    this->updateSFMLEvents();

    //is the state stack empty? If not update the state and if the state wants to end, end it and delete the state, then pop the stack
    if (!mStates.empty()) {
        mStates.top()->update(mDeltaTime);

        if (mStates.top()->getQuit()) {
            mStates.top()->endState();
            delete mStates.top();
            mStates.pop();
        }
    }

    //End game
    else {
        this->endApp();
        mWindow->close();
    }
}

//see if window is closed
void Game::updateSFMLEvents()
{
    while (const std::optional event = mWindow->pollEvent())
    {
        if (event->is<sf::Event::Closed>())
            mWindow->close();
    }
}

//restart the delta time clock
void Game::updateDeltaTime()
{
    mDeltaTime = mDTClock.restart().asSeconds();
}

void Game::render()
{
    mWindow->clear();

    //render objects
    if (!mStates.empty()) {
        mStates.top()->render(mWindow);
    }

    mWindow->display();
}

void Game::run()
{
    while (mWindow->isOpen()) {
        //restart the delta time clock
        this->updateDeltaTime();
        //update everything
        this->update();
        //draw everything
        this->render();
    }
}

void Game::drawMenu()
{
    //need to put stuff here later
}
