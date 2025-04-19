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

int Enemy::GetHealth() {

	return this->health;
}

int Enemy::GetDamageDelt() {

	return this->DamageDelt;
}

bool Enemy::GetStatus() {

	return this->Status;
}

void Enemy::SetHealth(int NewInt) {

	this->health = NewInt;
}

void Enemy::SetDamageDelt(int NewInt) {

	this->DamageDelt = NewInt;
}

void Enemy::SetStatus(bool NewBool) {

	this->Status = NewBool;
}

Enemy::~Enemy() {


}

void Enemy::initVariables() {

	bool Stat = true;

	this->SetHealth(100);
	this->SetDamageDelt(25);
	this->SetStatus(Stat);

}

void Enemy::initComponents(){

	this->createMovementComponent(100.0f, 20.0f, 20.0f);
}