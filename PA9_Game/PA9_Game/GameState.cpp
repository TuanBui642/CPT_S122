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

GameState::GameState(sf::RenderWindow* window) : State(window)
{
    this->initKeyBindings();
    this->initTextures();
    this->initPlayers();
    this->initEnemy1();
}

GameState::~GameState()
{
    delete mPlayer;
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

    sf::Texture temp2;
    temp2.loadFromFile("Sprites/flipper.png"); //File Input for Enemy (Flipper) to be imported to game

    mTextures["First Enemy Idle"] = temp2;
}

//Initalizes Importing Classes into window
void GameState::initPlayers()
{
    mPlayer = new Player(200.0f, 200.0f, mTextures["PLAYER_IDLE"]);
}

void GameState::initEnemy1() {

    FirstEnemy = new Enemy1(100.0f, 100.0f, mTextures["First Enemy Idle"]);
}