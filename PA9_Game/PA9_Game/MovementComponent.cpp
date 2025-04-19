#include "MovementComponent.hpp"
#include <iostream>
using std::cout;
using std::endl;

MovementComponent::MovementComponent(sf::Sprite& sprite, float maxVelocity, 
	float acceleration, float deceleration)
	: mSprite(sprite), mMaxVelocity(maxVelocity), mAcceleration(acceleration),
	mDeceleration(deceleration)
{
	mOnGround = false;
	mGravity = 0.0f;
}

MovementComponent::~MovementComponent()
{
}

const sf::Vector2f MovementComponent::getVelocity() const
{
	return mVelocity;
}

bool MovementComponent::getJumpUsed() const
{
	return !mOnGround;
}

bool MovementComponent::isIdle() const
{
	bool idle = false;

	if (mVelocity.x == 0.0f && mVelocity.y == 0.0f) {
		idle = true;
	}

	return idle;
}

bool MovementComponent::isMoving() const
{
	bool moving = false;

	if (mVelocity.x != 0.0f || mVelocity.y != 0.0f) {
		moving = true;
	}

	return true;
}

bool MovementComponent::isMovingRight() const
{
	bool movingRight = false;

	if (mVelocity.x > 0.0f && mVelocity.y == 0.0f) {
		movingRight = true;
	}

	return movingRight;
}

bool MovementComponent::isMovingLeft() const
{
	bool movingLeft = false;

	if (mVelocity.x < 0.0f && mVelocity.y == 0.0f) {
		movingLeft = true;

	}

	return movingLeft;
}

bool MovementComponent::isJumping()
{
	bool jumping = false;

	if (mVelocity.y < 0.0f) {
		jumping = true;
	}

	return jumping;
}

bool MovementComponent::isAttacking() const
{
	bool attack = false;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {
		attack = true;
	}

	return attack;
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

	if (this->isJumping() && mVelocity.y < 0.0f) {
		mGravity = 100.0f;
	}

	mVelocity.y += mGravity;

	//final move
	mSprite.move(mVelocity * deltaTime);
}
