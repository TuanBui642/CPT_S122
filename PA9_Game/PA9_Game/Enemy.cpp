#include "Enemy.hpp"
#pragma once

Enemy::Enemy(float x_pos, float y_pos, sf::Texture& texture)
	: Entity(mSprite, texture)
{
	//initialize stuff
	this->initVariables();
	//this->initComponents();

	//set stuff
	this->setTexture(texture);
	this->setPosition(x_pos, y_pos);
}

Enemy::~Enemy()
{

}

void Enemy::initVariables()
{
}

//void Enemy::initComponents()
//{
//	this->createMovementComponent(100.0f, 20.0f, 20.0f);
//}