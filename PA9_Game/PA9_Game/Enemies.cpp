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

Enemy::~Enemy(){

}

void Enemy::initVariables(){

}

void Enemy::initComponents(){

}

void Enemy::initAnimations() {


}

int Enemy::GetHealth() {

    return this->Health;
}

int Enemy::GetDamageDelt() {

    return this->DamageDealt;
}

void Enemy::SetHealth(int NewInt) {

    this->Health = NewInt;
}

void Enemy::SetDamage(int Newint) {

    this->DamageDealt = Newint;
}