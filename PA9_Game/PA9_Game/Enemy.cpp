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

#include "Enemy.hpp"

Enemy::Enemy(float x_pos, float y_pos, sf::Texture& CharTexture) : Entity(mpSprite, CharTexture) {

	this->setPosition(x_pos, y_pos);
	this->setTexture(CharTexture);

	this->initVariables();
	this->initComponents();

}

Enemy::~Enemy() {


}

void Enemy::initVariables() {


}

void Enemy::initComponents(){

}