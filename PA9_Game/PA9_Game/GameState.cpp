#pragma once
#include "GameState.hpp"

GameState::GameState(sf::RenderWindow* window) : State(window)
{
	this->initKeyBindings();
	this->initTextures();
	this->initPlayers();
	this->initEnemies();
}

GameState::~GameState()
{
	delete mPlayer;
	delete mEnemy;
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
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {	//jump
		mPlayer->move(deltaTime, 0.0f, -2.5f);					//up is negative
	}
}

void GameState::update(const float& deltaTime)
{
	this->updateInput(deltaTime);
	mPlayer->update(deltaTime);
	mEnemy->update(deltaTime);
}

void GameState::render(sf::RenderTarget* target)
{
	if (!target) {
		target = mStateWindow;
	}
	mPlayer->render(mStateWindow);
	mEnemy->render(mStateWindow);
}

void GameState::initKeyBindings()
{
	//mKeyBindings.emplace("MOVE_LEFT", this->mSupportedKeys->at("A"));
	//mKeyBindings.emplace("MOVE_RIGHT", this->mSupportedKeys->at("D"));
	//mKeyBindings.emplace("JUMP", this->mSupportedKeys->at(" "));
}

void GameState::initTextures()
{
	sf::Texture temp;
	sf::Texture tempEnemy;

	temp.loadFromFile("Resources/Images/Sprites/Player/test.png");
	tempEnemy.loadFromFile("Resources/Images/Sprites/Enemies/test.png");

	mTextures["PLAYER_IDLE"] = temp;
	mTextures["ENEMY_TEST"] = tempEnemy;
}

void GameState::initPlayers()
{
	mPlayer = new Player(200.0f, 200.0f, mTextures["PLAYER_IDLE"]);
}

void GameState::initEnemies()
{
	mEnemy = new Enemy(0.0f, 500.0f, mTextures["ENEMY_TEST"]);
}
