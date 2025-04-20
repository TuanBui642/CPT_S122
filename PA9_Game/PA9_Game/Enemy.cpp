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

	this->SetCurXPos(x_pos);
	this->SetCurYPos(y_pos);
	//this->createAnimationComponent(CharTexture);
	//												// 0, 0, 5, 3, 80, 64,12.0f);
	//mpAnimationComponent->addAnimation("Moving Right", 0, 0, 1, 1, 80, 32, 32.0f);

}

void Enemy::Update(const float& deltaTime) {

	//mpMovementComponent->update(deltaTime);

	//if (mpMovementComponent->isMovingRight()) {
	//	mpAnimationComponent->play("Moving Right", deltaTime);
	//}

}

Enemy::Enemy() : Entity(mpSprite, CharTexture){




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

bool Enemy::GetRightMoveStat() {

	return this->MovingRight;
}

bool Enemy::GetLeftMoveStat() {

	return this->MovingLeft;
}

float Enemy::GetRightBound() {

	return this->RightBound;
}

float Enemy::GetLeftBound() {

	return this->LeftBound;
}

float Enemy::GetCurXPos() {

	return this->CurrXPos;
}

float Enemy::GetCurYPos() {

	return this->CurrYPos;
}

sf::Texture Enemy::GetCurTexture() {

	return this->CharTexture;
}

float Enemy::GetUpperBound() {

	return this->UpperBound;
}

float Enemy::GetLowerBound() {

	return this->LowerBound;
}

bool Enemy::GetMovingUp() {

	return this->MovingUp;
}

bool Enemy::GetMovingDown() {

	return this->MovingDown;
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

void Enemy::SetRight(bool NewRight) {

	this->MovingRight = NewRight;
}

void Enemy::SetLeft(bool NewLeft) {

	this->MovingLeft = NewLeft;
}

void Enemy::SetRightBound(float NewBound) {

	this->RightBound = NewBound;
}

void Enemy::SetLeftBound(float NewBound) {

	this->LeftBound = NewBound;
}

void Enemy::SetCurXPos(float NewFloat) {

	this->CurrXPos = NewFloat;
}

void Enemy::SetCurYPos(float NewFloat) {

	this->CurrYPos = NewFloat;
}

void Enemy::SetCharTexture(sf::Texture Texture) {

	this->CharTexture = Texture;
}

void Enemy::SetUpperBound(float NewUpper) {

	this->UpperBound = NewUpper;
}

void Enemy::SetLowerBound(float NewLower) {

	this->LowerBound = NewLower;
}

void Enemy::SetMovingUp(bool NewBool) {

	this->MovingUp = NewBool;
}

void Enemy::SetMovingDown(bool NewBool) {

	this->MovingDown = NewBool;
}

void Enemy::UpdatePosition(float x, float y) {

	float Curx = this->GetCurXPos();

	Curx += x;

	this->SetCurXPos(Curx);

	float Cury = this->GetCurYPos();

	Cury += y;

	this->SetCurYPos(Cury);

}

void Enemy::MoveEnemy(const float x, const float y) {

	float CurrentXPos = this->GetCurXPos() + x;
	float CurrentYPos = this->GetCurYPos() + y;

	this->setPosition(CurrentXPos, CurrentYPos);
}

Enemy::~Enemy() {


}

void Enemy::initVariables() {

	bool Stat = true;

	this->SetHealth(100);
	this->SetDamageDelt(25);
	this->SetStatus(Stat);

	this->MovingRight = false;
	this->MovingLeft = false;

	this->MovingDown = false;
	this->MovingUp = false;

}

void Enemy::initComponents(){

	this->createMovementComponent(100.0f, 20.0f, 20.0f);
}
