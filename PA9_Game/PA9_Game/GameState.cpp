#pragma once
#include "GameState.hpp"

GameState::GameState(sf::RenderWindow* window) : State(window)
{
	this->initKeyBindings();
	this->initTextures();
	this->initPlayers();

	//Ashton work
	this->initWorld();
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

void GameState::initTextures()
{
	sf::Texture temp;
	temp.loadFromFile("Resources/Images/Sprites/Player/test.png");

	mTextures["PLAYER_IDLE"] = temp;
}

void GameState::initPlayers()
{
	mPlayer = new Player(0.0f, 0.0f, &mTextures["PLAYER_IDLE"]);
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
