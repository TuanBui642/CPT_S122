/*
*	Program: PA9 (Group Game Project)
*	Date: 4/12/25
*	Group:
*		Tuan Bui
*		Ashton Palma
*		Tyler Simmons
*		Brandon Weirth
*
*	File Programmer: Tuan Bui
*/

#include "Enemies.hpp"

Enemy::Enemy(float x_pos, float y_pos, sf::Texture* texture)
{
    //initialize stuff
    this->initVariables();
    this->initComponents();

    //set stuff
    this->createSprite(texture);
    this->setPosition(x_pos, y_pos);
}

Enemy::~Enemy()
{

}

void Enemy::initVariables()
{
}

void Enemy::initComponents()
{

}

void Enemy::initAnimations() {


}