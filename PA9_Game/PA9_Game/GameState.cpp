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
    mJumpUsed = false;

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

    delete mEnemy5;
    delete mEnemy6;
    delete mEnemy7;
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
            mPlayer->move(deltaTime, 0.0f, -20.0f);			//up is negative
            mJumpUsed = this->checkJump();					//check if apex of jump has happened
        }
    }



    //Move Enemies Back And Forth
    //NEED TO BE POSITIONED/POLISHED WHEN SETTING (Enviroment) IS FINAL

    //mEnemy1->MoveEnemyHorizontal(2.5f, 0.0f);
    mEnemy4->MoveEnemyHorizontal(3.0f, 0.0f);
    //mEnemy2->MoveEnemyHorizontal(2.0f,0.0f);
    mEnemy3->MoveEnemyVertically(0.0f, 2.5f);
    mEnemy5->MoveEnemyVertically(0.0f,2.5f);
    mEnemy6->MoveEnemyVertically(0.0f,2.5f);

    if (mEnemy1->GetStatus() != false) {

        if (mEnemy1->GetLeftMoveStat() == true) {

            mEnemy1->MoveEnemy(-2.0f, 0.0f);
            mEnemy1->UpdatePosition(-2.0f, 0.0f);
        }

        if (mEnemy1->GetCurXPos() == 1300.0f) {

            //1400.0f, 150.0f
            mEnemy1->SetCurXPos(1600.0f);
            mEnemy1->SetCurYPos(150.0f);
        }
    }

    //Saw Sprite
    //if (mEnemy2->GetStatus() != false) {

    //    if (mEnemy2->GetLeftMoveStat() == true) {

    //        mEnemy2->MoveEnemy(-2.0f, 0.0f);
    //        mEnemy2->UpdatePosition(-2.0f, 0.0f);
    //    }

    //    if (mEnemy2->GetCurXPos() == -10.0f) {

    //        //500.0f, 120.0f
    //        mEnemy2->SetCurXPos(500.0f);
    //        mEnemy2->SetCurYPos(120.0f);
    //    }
    //}

    if (mEnemy7->GetStatus() != false) { //Toaster Sprite

        if (mEnemy7->GetLeftMoveStat() == true) {

            mEnemy7->MoveEnemy(-5.0f, 0.0f);
            mEnemy7->UpdatePosition(-5.0f, 0.0f);
        }
        else if (mEnemy7->GetRightMoveStat() == true) {

            mEnemy7->MoveEnemy(5.0f, 0.0f);
            mEnemy7->UpdatePosition(5.0f, 0.0f);
        }

        if (mEnemy7->GetCurXPos() >= mEnemy7->GetRightBound()) {

            mEnemy7->SetRight(false);
            mEnemy7->SetLeft(true);

            sf::Texture NewTexture;
            NewTexture.loadFromFile("Sprites/timer_enemy_Left.png");

           /* mEnemy7->setTexture(NewTexture);*/

            mTextures["Seventh Enemy Idle"] = NewTexture;

        }

        if (mEnemy7->GetCurXPos() <= mEnemy7->GetLeftBound()) {

            mEnemy7->SetLeft(false);
            mEnemy7->SetRight(true);

            sf::Texture NewTexture;
            NewTexture.loadFromFile("Sprites/timer_enemy_Right.png");

            //mEnemy7->setTexture(NewTexture);

            mTextures["Seventh Enemy Idle"] = NewTexture;

        }
    }

    if (mPlayer->getGlobalBounds().findIntersection(mEnemy3->getGlobalBounds()) || 
        mPlayer->getGlobalBounds().findIntersection(mEnemy5->getGlobalBounds()) ||
        mPlayer->getGlobalBounds().findIntersection(mEnemy6->getGlobalBounds()) ||
        mPlayer->getGlobalBounds().findIntersection(mEnemy7->getGlobalBounds()) ||
        mPlayer->getGlobalBounds().findIntersection(mEnemy1->getGlobalBounds()) ||
        mPlayer->getGlobalBounds().findIntersection(mEnemy4->getGlobalBounds())) {

        mPlayer->setPosition(0.0f, 130.0f);
    }

}

void GameState::update(const float& deltaTime)
{
    this->updateInput(deltaTime);
    mPlayer->update(deltaTime);
    mEnemy1->update(deltaTime);
    mEnemy2->update(deltaTime);
    mEnemy3->update(deltaTime);
    mEnemy4->update(deltaTime);

    mEnemy5->update(deltaTime);
    mEnemy6->update(deltaTime);
    mEnemy7->update(deltaTime);

    //worldLayout.mapBoundary(*this->mStateWindow, *mPlayer);
    //worldLayout.checkCollisions(*mPlayer);

    worldLayout.updateCollision(mPlayer, mStateWindow->getSize());
}

void GameState::render(sf::RenderTarget* target)
{
    if (!target) {
        target = mStateWindow;
    }
    mPlayer->render(*target);
    mEnemy1->render(*target);
    mEnemy2->render(*target);
    mEnemy3->render(*target);
    mEnemy4->render(*target);

    mEnemy5->render(*target);
    mEnemy6->render(*target);
    mEnemy7->render(*target);

    //Ashton work
    this->worldLayout.render(*target);
    //auto* window = static_cast<sf::RenderWindow*>(mStateWindow);
    //worldLayout.draw(*window); 
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

    if (!mTextures["PLAYER_SHEET"].loadFromFile("Sprites/WarriorMan-Sheet.png")) {
        throw "ERROR::GAME_STATE::COULD_NOT_LOAD_PLAYER_TEXTURE";
    }

    //File Input for Enemy Instances to be imported to game
    sf::Texture tempEnemy1;
    tempEnemy1.loadFromFile("Sprites/flipper_idle.png"); 

    mTextures["First Enemy Idle"] = tempEnemy1;

    sf::Texture tempEnemy2;
    tempEnemy2.loadFromFile("Sprites/protag_.png");

    mTextures["Second Enemy Idle"] = tempEnemy2;

    sf::Texture tempEnemy3;
    tempEnemy3.loadFromFile("Sprites/timer_enemy_idle.png");

    mTextures["Third Enemy Idle"] = tempEnemy3;

    sf::Texture tempEnemy4;
    tempEnemy4.loadFromFile("Sprites/toaster_idle.png");

    mTextures["Fourth Enemy Idle"] = tempEnemy4;

    //Ashton work (Tile Texture)
    sf::Texture tempBlock;
    tempBlock.loadFromFile("Sprites/stoneBlock.png");

    mTextures["Block_Idle"] = tempBlock;

    sf::Sprite;

    sf::Texture tempEnemy5;
    tempEnemy5.loadFromFile("Sprites/timer_enemy_idle.png");

    mTextures["Fifth Enemy Idle"] = tempEnemy5;

    sf::Texture tempEnemy6;
    tempEnemy6.loadFromFile("Sprites/timer_enemy_idle.png");

    mTextures["Sixth Enemy Idle"] = tempEnemy6;

    sf::Texture tempEnemy7;
    tempEnemy7.loadFromFile("Sprites/timer_enemy_Left.png");

    mTextures["Seventh Enemy Idle"] = tempEnemy7;

}

//Initalizes Importing Classes into window
void GameState::initPlayers()
{
    mPlayer = new Player(0.0f, 130.0f, mTextures["PLAYER_SHEET"]);
}

void GameState::initEnemies() {

    //Move Enemies Back And Forth
                    //Sets Position (0,-500), Set Texture 
    mEnemy4 = new Enemy(600.0f, 535.0f, mTextures["Fourth Enemy Idle"]);  //Toaster 
    mEnemy4->SetLeftBound(500.0f);
    mEnemy4->SetRightBound(1100.0f);
    mEnemy4->SetRight(true);

    mEnemy3 = new Enemy(650.0f, 200.0f, mTextures["Third Enemy Idle"]); //Timer
    mEnemy3->SetUpperBound(75.0f);
    mEnemy3->SetLowerBound(250.0f);
    mEnemy3->SetMovingUp(true);

    mEnemy2 = new Enemy(500.0f, 145.0f, mTextures["Second Enemy Idle"]); //Saw
    mEnemy2->SetLeftBound(0.0f);
    mEnemy2->SetRightBound(520.0f);
    mEnemy2->SetLeft(true);

    mEnemy1 = new Enemy(1400.0f, 150.0f, mTextures["First Enemy Idle"]); //Flipper
    mEnemy1->SetLeftBound(1300.0f);
    mEnemy1->SetRightBound(1450.0f);
    mEnemy1->SetLeft(true);

    mEnemy6 = new Enemy(935.0f, 75.0f, mTextures["Sixth Enemy Idle"]); //Timer
    mEnemy6->SetUpperBound(75.0f);
    mEnemy6->SetLowerBound(250.0f);
    mEnemy6->SetMovingDown(true);

    mEnemy5 = new Enemy(1220.0f, 200.0f, mTextures["Fifth Enemy Idle"]); //Timer
    mEnemy5->SetUpperBound(75.0f);
    mEnemy5->SetLowerBound(250.0f);
    mEnemy5->SetMovingUp(true);

    mEnemy7 = new Enemy(650.0f, 450.0f, mTextures["Seventh Enemy Idle"]); //Timer
    mEnemy7->SetLeftBound(100.0f);
    mEnemy7->SetRightBound(1400.0f);
    mEnemy7->SetLeft(true);
}

void GameState::initWorld()
{
    //level 1 floor
   //parameter (strtPt, endPt, size)
    this->worldLayout.setPlayerReference(this->mPlayer);

    worldLayout.generateBlock(sf::Vector2f(0, 180), sf::Vector2f(550, 270), sf::Vector2f(20, 20), mTextures["Block_Idle"]);
    worldLayout.generateBlock(sf::Vector2f(1350, 180), sf::Vector2f(1500, 270), sf::Vector2f(20, 20), mTextures["Block_Idle"]);
    worldLayout.generateBlock(sf::Vector2f(1320, 180), sf::Vector2f(1400, 240), sf::Vector2f(20, 20), mTextures["Block_Idle"]);
    worldLayout.generateBlock(sf::Vector2f(1300, 180), sf::Vector2f(1320, 220), sf::Vector2f(20, 20), mTextures["Block_Idle"]);
    worldLayout.generateBlock(sf::Vector2f(550, 180), sf::Vector2f(580, 235), sf::Vector2f(20, 20), mTextures["Block_Idle"]);

    //Ashtons Test Block:
  //worldLayout.generateBlock(sf::Vector2f(500, 0), sf::Vector2f(600, 500), sf::Vector2f(20, 20), mTextures["Block_Idle"]);

    //level1 platform
    worldLayout.generateBlock(sf::Vector2f(585, 180), sf::Vector2f(1400, 180), sf::Vector2f(20, 20), mTextures["Block_Idle"]);
    //worldLayout.generateBlock(sf::Vector2f(750, 180), sf::Vector2f(860, 190), sf::Vector2f(20, 20), mTextures["Block_Idle"]);
    worldLayout.generateBlock(sf::Vector2f(1040, 180), sf::Vector2f(1170, 190), sf::Vector2f(20, 20), mTextures["Block_Idle"]);
    //deathzone
    worldLayout.generateHazard(sf::Vector2f(550, 250), sf::Vector2f(1380, 260), sf::Vector2f(5, 5));

    //level2 platform
    worldLayout.generateBlock(sf::Vector2f(1400, 500), sf::Vector2f(1500, 640), sf::Vector2f(20, 20), mTextures["Block_Idle"]);
    worldLayout.generateBlock(sf::Vector2f(1300, 525), sf::Vector2f(1400, 640), sf::Vector2f(22.5, 22.5), mTextures["Block_Idle"]);
    worldLayout.generateBlock(sf::Vector2f(1150, 550), sf::Vector2f(1300, 640), sf::Vector2f(22, 22), mTextures["Block_Idle"]);
    worldLayout.generateBlock(sf::Vector2f(500, 565), sf::Vector2f(1150, 640), sf::Vector2f(23.5, 23.5), mTextures["Block_Idle"]);
    worldLayout.generateBlock(sf::Vector2f(400, 550), sf::Vector2f(500, 640), sf::Vector2f(22, 22), mTextures["Block_Idle"]);
    worldLayout.generateBlock(sf::Vector2f(300, 525), sf::Vector2f(400, 645), sf::Vector2f(19.5, 19.5), mTextures["Block_Idle"]);
    worldLayout.generateBlock(sf::Vector2f(200, 490), sf::Vector2f(300, 645), sf::Vector2f(20, 20), mTextures["Block_Idle"]);
    worldLayout.generateBlock(sf::Vector2f(0, 270), sf::Vector2f(300, 330), sf::Vector2f(20, 20), mTextures["Block_Idle"]);
    worldLayout.generateBlock(sf::Vector2f(300, 270), sf::Vector2f(430, 300), sf::Vector2f(20, 20), mTextures["Block_Idle"]);
    worldLayout.generateBlock(sf::Vector2f(0, 330), sf::Vector2f(90, 380), sf::Vector2f(20, 20), mTextures["Block_Idle"]);
    worldLayout.generateBlock(sf::Vector2f(0, 380), sf::Vector2f(40, 870), sf::Vector2f(15, 15), mTextures["Block_Idle"]);
    //worldLayout.generateBlock(sf::Vector2f(180, 525), sf::Vector2f(200, 630), sf::Vector2f(10, 10), mTextures["Block_Idle"]);

    worldLayout.generateHazard(sf::Vector2f(45, 500), sf::Vector2f(185, 600), sf::Vector2f(20, 20));

}