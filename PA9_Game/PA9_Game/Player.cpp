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

Player::Player(float x_pos, float y_pos, sf::Texture& textureSheet) : Entity(mpSprite, textureSheet)
{
	//initialize stuff
	this->initVariables();

	//set stuff
	this->setPosition(x_pos, y_pos);

	//need to do this after texture sheet is available
	this->createMovementComponent(100.0f, 20.0f, 20.0f);
	this->createAnimationComponent(textureSheet);

	mpAnimationComponent->addAnimation("IDLE_RIGHT", 0, 0, 7, 0, 80, 64, 12.0f);	//starts at row 1 on sheet
	mpAnimationComponent->addAnimation("WALK_RIGHT", 0, 2, 7, 2, 80, 64, 12.0f);	//starts at row 3 on sheet
	mpAnimationComponent->addAnimation("JUMP_RIGHT", 0, 4, 10, 4, 80, 64, 12.0f);	//starts at row 5 on sheet
	mpAnimationComponent->addAnimation("ATTACK_RIGHT", 0, 5, 5, 5, 80, 64, 12.0f);	//starts at row 6 on sheet
}

Player::~Player()
{

}

bool Player::getJumpUsed() const
{
	return mJumpUsed;
}

void Player::update(const float& deltaTime)
{
	mpMovementComponent->update(deltaTime);

	mJumpUsed = mpMovementComponent->getJumpUsed();

	if (mpMovementComponent->isIdle()) {
		mpAnimationComponent->play("IDLE_RIGHT", deltaTime);
	}
	else if (mpMovementComponent->isMovingRight()) {
		mpAnimationComponent->play("WALK_RIGHT", deltaTime);
	}
	else if (mpMovementComponent->isJumping()) {
		mpAnimationComponent->play("JUMP_RIGHT", deltaTime);
	}
	else if (mpMovementComponent->isAttacking()) {
		mpAnimationComponent->play("ATTACK_RIGHT", deltaTime);
	}
}

void Player::initVariables()
{
}

void Player::initComponents()
{

}