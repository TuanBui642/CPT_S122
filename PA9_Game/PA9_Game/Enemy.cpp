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

Enemy::Enemy(float x_pos, float y_pos, sf::Texture& CharTexture) : Entity(mpSprite, CharTexture) { //Constructor

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

void Enemy::Update(const float& deltaTime) { //Update Movement Animations (Didn't use it at end)

	//mpMovementComponent->update(deltaTime);

	//if (mpMovementComponent->isMovingRight()) {
	//	mpAnimationComponent->play("Moving Right", deltaTime);
	//}

}

Enemy::Enemy() : Entity(mpSprite, CharTexture){ //Constructor

	this->setPosition(0.0f,0.0f);
	this->SetCurXPos(0.0f);
	this->SetCurYPos(0.0f);
	this->initComponents();
	this->initVariables();
}

int Enemy::GetHealth() { //Getter

	return this->health;
}

int Enemy::GetDamageDelt() { //Getter

	return this->DamageDelt;
}

bool Enemy::GetStatus() { //Getter

	return this->Status;
}

bool Enemy::GetRightMoveStat() { //Getter

	return this->MovingRight;
}

bool Enemy::GetLeftMoveStat() { //Getter

	return this->MovingLeft;
}

float Enemy::GetRightBound() { //Getter

	return this->RightBound;
}

float Enemy::GetLeftBound() { //Getter

	return this->LeftBound;
}

float Enemy::GetCurXPos() { //Getter

	return this->CurrXPos;
}

float Enemy::GetCurYPos() { //Getter

	return this->CurrYPos;
}

sf::Texture Enemy::GetCurTexture() { //Getter

	return this->CharTexture;
}

float Enemy::GetUpperBound() { //Getter

	return this->UpperBound;
}

float Enemy::GetLowerBound() { //Getter

	return this->LowerBound;
}

bool Enemy::GetMovingUp() { //Getter

	return this->MovingUp;
}

bool Enemy::GetMovingDown() { //Getter

	return this->MovingDown;
}

void Enemy::SetHealth(int NewInt) { //Setter

	this->health = NewInt;
}

void Enemy::SetDamageDelt(int NewInt) {//Setter

	this->DamageDelt = NewInt;
}

void Enemy::SetStatus(bool NewBool) {//Setter

	this->Status = NewBool;
}

void Enemy::SetRight(bool NewRight) {//Setter

	this->MovingRight = NewRight;
}

void Enemy::SetLeft(bool NewLeft) {//Setter

	this->MovingLeft = NewLeft;
}

void Enemy::SetRightBound(float NewBound) {//Setter

	this->RightBound = NewBound;
}

void Enemy::SetLeftBound(float NewBound) {//Setter

	this->LeftBound = NewBound;
}

void Enemy::SetCurXPos(float NewFloat) {//Setter

	this->CurrXPos = NewFloat;
}

void Enemy::SetCurYPos(float NewFloat) {//Setter

	this->CurrYPos = NewFloat;
}

void Enemy::SetCharTexture(sf::Texture Texture) {//Setter

	this->CharTexture = Texture;

}

void Enemy::SetUpperBound(float NewUpper) {//Setter

	this->UpperBound = NewUpper;
}

void Enemy::SetLowerBound(float NewLower) {//Setter

	this->LowerBound = NewLower;
}

void Enemy::SetMovingUp(bool NewBool) {//Setter

	this->MovingUp = NewBool;
}

void Enemy::SetMovingDown(bool NewBool) {//Setter

	this->MovingDown = NewBool;
}

void Enemy::UpdatePosition(float x, float y) { //Updates the position after each movement

	float Curx = this->GetCurXPos();

	Curx += x;

	this->SetCurXPos(Curx);

	float Cury = this->GetCurYPos();

	Cury += y;

	this->SetCurYPos(Cury);

}

void Enemy::MoveEnemy(const float x, const float y) { //Moves Enemy in position passed in 

	float CurrentXPos = this->GetCurXPos() + x;
	float CurrentYPos = this->GetCurYPos() + y;

	this->setPosition(CurrentXPos, CurrentYPos);
}

Enemy::~Enemy() { //Destructor

	delete this;
}

//Moves an Enemy Sprite Horizontally dependent on setPosition, and setting Right/Left bounds for it to move back and forth of those bounds
void Enemy::MoveEnemyHorizontal(const float x, const float y) {

	if (this->GetStatus() != false) { //Conditions to check if the enemhy sprite is alive before it may move

		if (this->GetLeftMoveStat() == true) {

			this->MoveEnemy(-x, y);
			this->UpdatePosition(-x, y);
		}
		else if (this->GetRightMoveStat() == true) {

			this->MoveEnemy(x, y);
			this->UpdatePosition(x, y);
		}

		if (this->GetCurXPos() >= this->GetRightBound()) {

			this->SetRight(false);
			this->SetLeft(true);

		}

		if (this->GetCurXPos() <= this->GetLeftBound()) {

			this->SetLeft(false);
			this->SetRight(true);

		}
	}
}

//Moves an Enemy Sprite Vertically dependent on setPosition, and setting upper/lower bounds for it to move back and forth of those bounds
void Enemy::MoveEnemyVertically(const float x, const float y) { 

	if (this->GetStatus() != false) { //Conditions to check if the enemhy sprite is alive before it may move

		if (this->GetMovingUp() == true) {

			this->MoveEnemy(x, -y);
			this->UpdatePosition(x, -y);
		}
		else if (this->GetMovingDown() == true) {

			this->MoveEnemy(x, y);
			this->UpdatePosition(x, y);
		}

		if (this->GetCurYPos() >= this->GetLowerBound()) {

			this->SetMovingDown(false);
			this->SetMovingUp(true);

		}

		if (this->GetCurYPos() <= this->GetUpperBound()) {

			this->SetMovingUp(false);
			this->SetMovingDown(true);

		}
	}
}

sf::RectangleShape Enemy::GetEnemyShape() { //Getter

	return this->CharShape;
}

//Initializes attributes of Enemy
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

//Initializes components of attributes of Enemy such as it's movement component
void Enemy::initComponents(){

	this->createMovementComponent(100.0f, 20.0f, 20.0f);
}