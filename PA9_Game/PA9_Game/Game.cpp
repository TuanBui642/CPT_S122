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

void Game::endApp()
{
    cout << "Ending game." << endl;
}

void Game::update()
{
    this->updateSFMLEvents();

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

void Game::updateSFMLEvents()
{
    while (const std::optional event = mWindow->pollEvent())
    {
        if (event->is<sf::Event::Closed>())
            mWindow->close();
    }
}

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

        this->updateDeltaTime();
        this->update();
        this->render();
    }
}

void Game::drawMenu()
{
    //need to put stuff here later
}

void Game::initWindow()
{
    unsigned int width = 1280;
    unsigned int height = 720;

    mWindow = new sf::RenderWindow(sf::VideoMode({ width, height }), "Untitled 2D Platformer");

    mWindow->setFramerateLimit(60);	//set frame rate cap to 60 fps
}

void Game::initKeys()
{
    /*mSupportedKeys.emplace("Escape", sf::Keyboard::Key::Escape);
    mSupportedKeys.emplace("A", sf::Keyboard::Key::A);
    mSupportedKeys.emplace("D", sf::Keyboard::Key::D);*/
    //mSupportedKeys.emplace(" ", sf::Keyboard::Key::Space);
}

void Game::initStates()
{
    mStates.push(new GameState(mWindow));
}