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

#include "MovementComponent.hpp"
#include <iostream>
using std::cout;
using std::endl;

MovementComponent::MovementComponent(sf::Sprite& sprite, float acceleration, float deceleration)
	: mSprite(sprite), mAcceleration(acceleration),
	mDeceleration(deceleration)
{
	mMaxVelocity = 100.0f; //assume low initial max velocity
	mOnGround = true;	//assume player starts out on ground
	mGravity = 0.0f;
	mFaceRight = true;	//assume player starts out facing right
	mFaceLeft = false;
}

MovementComponent::~MovementComponent()
{
}

const sf::Vector2f& MovementComponent::getVelocity() const
{
	return mVelocity;
}

bool MovementComponent::getJumpUsed() const
{
	return !mOnGround;
}

sf::Vector2f& MovementComponent::getVelocity()
{
	return mVelocity;
}

const float& MovementComponent::getMaxVelocity() const
{
	return mMaxVelocity;
}

bool MovementComponent::getState(const short unsigned state)
{
	switch (state) {
	case IDLE:
		if (mVelocity.x == 0.0f && mVelocity.y == 0.0f) {
			return true;
		}
		break;
	case MOVING:
		if (mVelocity.x != 0.0f || mVelocity.y != 0.0f) {
			return true;
		}
		break;
	case WALK_RIGHT:
		if (mVelocity.x > 0.0f && mVelocity.y == 0.0f
			&& !sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LShift)) {
			mMaxVelocity = 100.0f;
			mFaceLeft = false;
			mFaceRight = true;
			return true;
		}
		break;
	case WALK_LEFT:
		if (mVelocity.x < 0.0f && mVelocity.y == 0.0f
			&& !sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LShift)) {
			mMaxVelocity = 100.0f;
			mFaceRight = false;
			mFaceLeft = true;
			return true;
		}
		break;
	case RUN_RIGHT:
		if (mVelocity.x > 0.0f && mVelocity.y == 0.0f
			&& sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LShift)) {
			mFaceLeft = false;
			mFaceRight = true;
			return true;
		}
		break;
	case RUN_LEFT:
		if (mVelocity.x < 0.0f && mVelocity.y == 0.0f
			&& sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LShift)) {
			mFaceRight = false;
			mFaceLeft = true;
			return true;
		}
		break;
	case JUMP_RIGHT:
		if (mFaceRight == true && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
			mOnGround = false;
			return true;
		}
		break;
	case JUMP_LEFT:
		if (mFaceLeft == true && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
			mOnGround = false;
			return true;
		}
		break;
	case ATTACK_RIGHT:
		if (mFaceRight == true && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {
			return true;
		}
		break;
	case ATTACK_LEFT:
		if (mFaceLeft == true && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {
			return true;
		}
		break;
	default:
		break;
	}
	return false;
}

void MovementComponent::move(const float dir_x, const float dir_y, const float deltaTime)
{
	//acceleration
	mVelocity.x += mAcceleration * dir_x;

	mVelocity.y += mAcceleration * dir_y;	//TO DO: flagged for needing to be used in jump or fall
}

void MovementComponent::update(const float& deltaTime)
{
	//deceleration

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LShift)) {
		mMaxVelocity = 400.0f;
	}

	else {
		mMaxVelocity = 200.0f;
	}
	//speed cap x
	if (mVelocity.x > 0.0f) {
		//acceleration
		if (mVelocity.x > mMaxVelocity) {
			mVelocity.x = mMaxVelocity;
		}
		if (mVelocity.x < -mMaxVelocity) {
			mVelocity.x = -mMaxVelocity;
		}
		//deceleration
		mVelocity.x -= mDeceleration;
		if (mVelocity.x < 0.0f) {
			mVelocity.x = 0.0f;
		}
	}
	else if (mVelocity.x < 0.0f) {
		//acceleration
		if (mVelocity.x < -mMaxVelocity) {
			mVelocity.x = -mMaxVelocity;
		}
		if (mVelocity.x > mMaxVelocity) {
			mVelocity.x = mMaxVelocity;
		}
		//deceleration
		mVelocity.x += mDeceleration;
		if (mVelocity.x > 0.0f) {
			mVelocity.x = 0.0f;
		}
	}

	//speed cap y
	if (mOnGround) {
		mGravity = 0.0f;
	}

	if (!mOnGround && mVelocity.y < 0.0f) {
		mGravity = 100.0f;
	}

	mVelocity.y += mGravity;

	//final move
	mSprite.move(mVelocity * deltaTime);
}