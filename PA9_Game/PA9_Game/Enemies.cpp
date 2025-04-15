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

int Enemy::GetHealth() {

	return this->Health;
}

int Enemy::GetDamageDealt() {

	return this->DamageDealt;
}

bool Enemy::GetAliveOrDead() {

	return this->AliveORDead;
}

float Enemy::GetMovementSpeed() {

	return this->MovementSpeed;
}

void Enemy::SetHealth(int NewNum) {

	this->Health = NewNum;
}

void Enemy::SetDamageDealt(int NewNum) {

	this->DamageDealt = NewNum;
}

void Enemy::SetAliveORDead(bool NewBool) {

	this->AliveORDead = NewBool;
}

void Enemy::SetMovementSpeed(float NewSpeed) {

	this->MovementSpeed = NewSpeed;
}


Enemy::~Enemy() {//Destructor

	cout << "Destructor: Enemy" << endl;
}