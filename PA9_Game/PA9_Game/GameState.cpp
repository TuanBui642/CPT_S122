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
#include "GameState.hpp"

GameState::GameState(sf::RenderWindow* window) : State(window), worldLayout(window->getSize().x, window->getSize().y)
{
    this->initKeyBindings();
    this->initTextures();
    this->initPlayers();
    this->initEnemies();
     this->initWorld();
}

GameState::~GameState()
{
    delete mPlayer;
    delete mEnemy1;
}

void GameState::updateInput(const float& deltaTime)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
        this->endState();
    }

    //update player input
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
        mPlayer->move(deltaTime, -5.0f, 0.0f);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
        mPlayer->move(deltaTime, 5.0f, 0.0f);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) { //Jump

        mPlayer->move(deltaTime, 0.0f, -2.5f);  //Up is Negative
    }

}

void GameState::update(const float& deltaTime)
{
    this->updateInput(deltaTime);
    mPlayer->update(deltaTime);
}

void GameState::render(sf::RenderTarget* target)
{
    if (!target) {
        target = mStateWindow;
    }
    mPlayer->render(mStateWindow);
    mEnemy1->render(mStateWindow);

    //Ashton work
    auto* window = static_cast<sf::RenderWindow*>(mStateWindow);
    worldLayout.draw(*window); 
}

void GameState::initKeyBindings()
{
    //mKeyBindings.emplace("MOVE_LEFT", this->mSupportedKeys->at("A"));
    //mKeyBindings.emplace("MOVE_RIGHT", this->mSupportedKeys->at("D"));
    //mKeyBindings.emplace("JUMP", this->mSupportedKeys->at(" "));
}

//Initalizes Textures for Respected Sprites/Classes
void GameState::initTextures()
{
    sf::Texture temp;
    temp.loadFromFile("Sprites/protag_.png");//File Input for Sprite Texture

    mTextures["PLAYER_IDLE"] = temp;

    sf::Texture tempEnemy1;
    tempEnemy1.loadFromFile("Sprites/flipper.png"); //File Input for Enemy (Flipper) to be imported to game

    mTextures["First Enemy Idle"] = tempEnemy1;
}

//Initalizes Importing Classes into window
void GameState::initPlayers()
{
    mPlayer = new Player(200.0f, 200.0f, mTextures["PLAYER_IDLE"]);
}

void GameState::initEnemies() {

                    //Sets Position (0,-500), Set Texture 
    mEnemy1 = new Enemy(0.0f, 500.0f, mTextures["First Enemy Idle"]); 
}

void GameState::initWorld()
{
    //Generate first level of the game 
    worldLayout.generateBlock(sf::Vector2f(0, 180), sf::Vector2f(550, 270), sf::Vector2f(20, 20));
    worldLayout.generateBlock(sf::Vector2f(1350, 180), sf::Vector2f(1500, 270), sf::Vector2f(20, 20));
    worldLayout.generateBlock(sf::Vector2f(1320, 180), sf::Vector2f(1400, 240), sf::Vector2f(20, 20));
    worldLayout.generateBlock(sf::Vector2f(1300, 180), sf::Vector2f(1320, 220), sf::Vector2f(20, 20));
    worldLayout.generateBlock(sf::Vector2f(550, 180), sf::Vector2f(580, 235), sf::Vector2f(20, 20));

}