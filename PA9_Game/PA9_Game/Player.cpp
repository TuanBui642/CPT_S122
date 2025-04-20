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
	this->createHitboxComponent(mpSprite, 34.0f, 20.0f, 17.0f, 27.0f);
	this->createMovementComponent(100.0f, 20.0f, 20.0f);
	this->createAnimationComponent(textureSheet);

	mpAnimationComponent->addAnimation("IDLE", 0, 0, 7, 0, 80, 64, 12.0f);		//starts at row 1 on sheet
	mpAnimationComponent->addAnimation("WALK", 0, 2, 7, 2, 80, 64, 12.0f);		//starts at row 3 on sheet
	mpAnimationComponent->addAnimation("JUMP", 0, 4, 10, 4, 80, 64, 12.0f);		//starts at row 5 on sheet
	mpAnimationComponent->addAnimation("ATTACK", 0, 5, 5, 5, 80, 64, 12.0f);	//starts at row 6 on sheet
	mpAnimationComponent->addAnimation("RUN", 0, 3, 7, 3, 80, 64, 12.0f);		//starts at row 4 on sheet
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
    float reverseOffset = 85.0f;				//pushes the hitbox back over when moving left
    mpMovementComponent->update(deltaTime);

    mJumpUsed = mpMovementComponent->getJumpUsed();

   
        if (mpMovementComponent->getState(IDLE)) {
            mpAnimationComponent->play("IDLE", deltaTime);
        }
        else if (mpMovementComponent->getState(WALK_RIGHT)) {
            mpSprite.setScale(sf::Vector2f(1.0f, 1.0f));
            mpSprite.setOrigin(sf::Vector2f(0.0f, 0.0f));
            mpAnimationComponent->play("WALK", deltaTime);
        }
        else if (mpMovementComponent->getState(WALK_LEFT)) {
            mpSprite.setScale(sf::Vector2f(-1.0f, 1.0f));
            mpSprite.setOrigin(sf::Vector2f(reverseOffset, 0.0f));
            mpAnimationComponent->play("WALK", deltaTime);
        }
        else if (mpMovementComponent->getState(JUMP_RIGHT)) {
            mpSprite.setScale(sf::Vector2f(1.0f, 1.0f));
            mpSprite.setOrigin(sf::Vector2f(0.0f, 0.0f));
            mpAnimationComponent->play("JUMP", deltaTime);
        }
        else if (mpMovementComponent->getState(JUMP_LEFT)) {
            mpSprite.setScale(sf::Vector2f(-1.0f, 1.0f));
            mpSprite.setOrigin(sf::Vector2f(reverseOffset, 0.0f));
            mpAnimationComponent->play("JUMP", deltaTime);
        }
        else if (mpMovementComponent->getState(ATTACK_RIGHT)) {
            mpSprite.setScale(sf::Vector2f(1.0f, 1.0f));
            mpSprite.setOrigin(sf::Vector2f(0.0f, 0.0f));
            mpAnimationComponent->play("ATTACK", deltaTime);
        }
        else if (mpMovementComponent->getState(ATTACK_LEFT)) {
            mpSprite.setScale(sf::Vector2f(-1.0f, 1.0f));
            mpSprite.setOrigin(sf::Vector2f(reverseOffset, 0.0f));
            mpAnimationComponent->play("ATTACK", deltaTime);
        }
        else if (mpMovementComponent->getState(RUN_RIGHT)) {
            mpSprite.setScale(sf::Vector2f(1.0f, 1.0f));
            mpSprite.setOrigin(sf::Vector2f(0.0f, 0.0f));
            mpAnimationComponent->play("RUN", deltaTime);
        }
        else if (mpMovementComponent->getState(RUN_LEFT)) {
            mpSprite.setScale(sf::Vector2f(-1.0f, 1.0f));
            mpSprite.setOrigin(sf::Vector2f(reverseOffset, 0.0f));
            mpAnimationComponent->play("RUN", deltaTime);
        }

        //update hitbox component, needs to be done after movement component
        mpHitboxComponent->update();
}

void Player::initVariables()
{
}

void Player::initComponents()
{

}