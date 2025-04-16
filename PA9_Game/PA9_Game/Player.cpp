#pragma once
#include "Player.hpp"

Player::Player(float x_pos, float y_pos, sf::Texture* texture)
{
	//initialize stuff
	this->initVariables();
	this->initComponents();

	//set stuff
	this->createSprite(texture);
	this->setPosition(x_pos, y_pos);
}

Player::~Player()
{

}

void Player::initVariables()
{
}

void Player::initComponents()
{
	
}
