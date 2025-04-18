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

Player::Player(float x_pos, float y_pos, sf::Texture& texture) : Entity(mpSprite, texture)
{
    //initialize stuff
    this->initVariables();
    this->initComponents();

    //set stuff
    this->setTexture(texture);
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
    this->createMovementComponent(100.0f, 20.0f, 20.0f);
}