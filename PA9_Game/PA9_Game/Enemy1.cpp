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

#include "Enemy1.hpp"

Enemy1::Enemy1(float x, float y, sf::Texture& CharTexture) : Enemy(x, y, CharTexture) {

	this->setTexture(CharTexture);
	this->setPosition(x, y);
	this->initComponents();
	this->initVariables();
}

Enemy1::~Enemy1() {


}

//Setters and Getters
bool Enemy1::getStatus() {

	return this->Status;
}

void Enemy1::setStatus(bool NewStatus) {

	this->Status = NewStatus;
}

void Enemy1::initVariables() {

	this->Status = true; //Set to Alive when instantiated
	this->Health = 100;
	this->DamageDealt = 50;
}

void Enemy1::initComponents() {

	this->createMovementComponent(100.0f, 20.0f, 20.0f);
}
