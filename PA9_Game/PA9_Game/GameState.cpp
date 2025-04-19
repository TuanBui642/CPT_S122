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
    delete mEnemy2;
    delete mEnemy3;
    delete mEnemy4;
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

    if (!mJumpUsed) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {	//jump
            mPlayer->move(deltaTime, 0.0f, -75.0f);			//up is negative
            mJumpUsed = this->checkJump();					//check if apex of jump has happened
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) { //Jump

        mPlayer->move(deltaTime, 0.0f, -2.5f);  //Up is Negative
    }

    //cout << "DeltaTime:" << deltaTime << endl;
  
    
    //Move Enemies Back And Forth
    //NEED TO BE POSITIONED/POLISHED WHEN SETTING (Enviroment) IS FINAL
    if (mEnemy1->GetStatus() != false) {

        if (mEnemy1->GetLeftMoveStat() == true) {

            mEnemy1->move(deltaTime, -5.0f, 0.0f);
            mEnemy1->UpdatePosition(-5.0f, 0.0f);
        }
        else if (mEnemy1->GetRightMoveStat() == true) {

            mEnemy1->move(deltaTime, 5.0f, 0.0f);
            mEnemy1->UpdatePosition(5.0f, 0.0f);
        }

        if (mEnemy1->GetCurXPos() >= mEnemy1->GetRightBound()) {

            mEnemy1->SetRight(false);
            mEnemy1->SetLeft(true);
            
        }

        if (mEnemy1->GetCurXPos() <= mEnemy1->GetLeftBound()) {

            mEnemy1->SetLeft(false);
            mEnemy1->SetRight(true);

        }
    }

    /*
    if (mEnemy2->GetStatus() != false) {

        if (mEnemy2->GetLeftMoveStat() == true) {

            mEnemy2->move(deltaTime, -5.0f, 0.0f);
            mEnemy2->UpdatePosition(-5.0f, 0.0f);
        }
        else if (mEnemy2->GetRightMoveStat() == true) {

            mEnemy2->move(deltaTime, 5.0f, 0.0f);
            mEnemy2->UpdatePosition(5.0f, 0.0f);
        }

        if (mEnemy2->GetCurXPos() >= mEnemy2->GetRightBound()) {

            mEnemy2->SetRight(false);
            mEnemy2->SetLeft(true);

        }

        if (mEnemy2->GetCurXPos() <= mEnemy2->GetLeftBound()) {

            mEnemy2->SetLeft(false);
            mEnemy2->SetRight(true);

        }
    }

    if (mEnemy3->GetStatus() != false) {

        if (mEnemy3->GetLeftMoveStat() == true) {

            mEnemy3->move(deltaTime, -5.0f, 0.0f);
            mEnemy3->UpdatePosition(-5.0f, 0.0f);
        }
        else if (mEnemy3->GetRightMoveStat() == true) {

            mEnemy3->move(deltaTime, 5.0f, 0.0f);
            mEnemy3->UpdatePosition(5.0f, 0.0f);
        }

        if (mEnemy3->GetCurXPos() >= mEnemy3->GetRightBound()) {

            mEnemy3->SetRight(false);
            mEnemy3->SetLeft(true);

        }

        if (mEnemy3->GetCurXPos() <= mEnemy3->GetLeftBound()) {

            mEnemy3->SetLeft(false);
            mEnemy3->SetRight(true);

        }
    }

    if (mEnemy4->GetStatus() != false) {

        if (mEnemy4->GetLeftMoveStat() == true) {

            mEnemy4->move(deltaTime, -5.0f, 0.0f);
            mEnemy4->UpdatePosition(-5.0f, 0.0f);
        }
        else if (mEnemy4->GetRightMoveStat() == true) {

            mEnemy4->move(deltaTime, 5.0f, 0.0f);
            mEnemy4->UpdatePosition(5.0f, 0.0f);
        }

        if (mEnemy4->GetCurXPos() >= mEnemy4->GetRightBound()) {

            mEnemy4->SetRight(false);
            mEnemy4->SetLeft(true);

        }

        if (mEnemy4->GetCurXPos() <= mEnemy4->GetLeftBound()) {

            mEnemy4->SetLeft(false);
            mEnemy4->SetRight(true);

        }
    }
    */


}

void GameState::update(const float& deltaTime)
{
    this->updateInput(deltaTime);
    mPlayer->update(deltaTime);
    mEnemy1->update(deltaTime);
}

void GameState::render(sf::RenderTarget* target)
{
    if (!target) {
        target = mStateWindow;
    }
    mPlayer->render(mStateWindow);
    mEnemy1->render(mStateWindow);
    mEnemy2->render(mStateWindow);
    mEnemy3->render(mStateWindow);
    mEnemy4->render(mStateWindow);

    //Ashton work
    auto* window = static_cast<sf::RenderWindow*>(mStateWindow);
    worldLayout.draw(*window); 
}

bool GameState::checkJump()
{
    return this->mPlayer->getJumpUsed();
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
//    sf::Texture temp;
//    temp.loadFromFile("Sprites/WarriorMan-Sheet.png");//File Input for Sprite Texture
//
//    mTextures["PLAYER_IDLE"] = temp;

    if (!mTextures["PLAYER_SHEET"].loadFromFile("Sprites/WarriorMan-Sheet.png")) {
        throw "ERROR::GAME_STATE::COULD_NOT_LOAD_PLAYER_TEXTURE";
    }


    //File Input for Enemy Instances to be imported to game
    sf::Texture tempEnemy1;
    tempEnemy1.loadFromFile("Sprites/flipper.png"); 

    mTextures["First Enemy Idle"] = tempEnemy1;

    sf::Texture tempEnemy2;
    tempEnemy2.loadFromFile("Sprites/saw_enemy.png");

    mTextures["Second Enemy Idle"] = tempEnemy2;

    sf::Texture tempEnemy3;
    tempEnemy3.loadFromFile("Sprites/timer_enemy.png");

    mTextures["Third Enemy Idle"] = tempEnemy3;

    sf::Texture tempEnemy4;
    tempEnemy4.loadFromFile("Sprites/toaster_move.png");

    mTextures["Fourth Enemy Idle"] = tempEnemy4;

}

//Initalizes Importing Classes into window
void GameState::initPlayers()
{
    mPlayer = new Player(200.0f, 200.0f, mTextures["PLAYER_SHEET"]);
}

void GameState::initEnemies() {

                    //Sets Position (0,-500), Set Texture 
    mEnemy1 = new Enemy(150.0f, 500.0f, mTextures["First Enemy Idle"]); 
    mEnemy1->SetLeftBound(145.0f);
    mEnemy1->SetRightBound(200.0f);
    mEnemy1->SetRight(true);


    //Move Enemies Back And Forth
   //NEED TO BE POSITIONED/POLISHED WHEN SETTING (Enviroment) IS FINAL
    mEnemy2 = new Enemy(0.0f, 550.0f, mTextures["Second Enemy Idle"]);
    //mEnemy2->SetLeftBound(145.0f);
    //mEnemy2->SetRightBound(200.0f);
    //mEnemy2->SetRight(true);


    mEnemy3 = new Enemy(0.0f, 600.0f, mTextures["Third Enemy Idle"]);
    //mEnemy3->SetLeftBound(145.0f);
    //mEnemy3->SetRightBound(200.0f);
    //mEnemy3->SetRight(true);

    mEnemy4 = new Enemy(0.0f, 650.0f, mTextures["Fourth Enemy Idle"]);
    //mEnemy4->SetLeftBound(145.0f);
    //mEnemy4->SetRightBound(200.0f);
    //mEnemy4->SetRight(true);

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