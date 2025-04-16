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