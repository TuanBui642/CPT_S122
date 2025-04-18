#include "MovementComponent.hpp"

MovementComponent::MovementComponent(sf::Sprite& sprite, float maxVelocity,
    float acceleration, float deceleration)
    : mSprite(sprite), mMaxVelocity(maxVelocity), mAcceleration(acceleration),
    mDeceleration(deceleration)
{

}

MovementComponent::~MovementComponent()
{
}

const sf::Vector2f MovementComponent::getVelocity() const
{
    return mVelocity;
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
    if (mVelocity.y < 0.0f) {
        //acceleration
        if (mVelocity.y > mMaxVelocity) {
            mVelocity.y = mMaxVelocity;
        }
        if (mVelocity.y < -mMaxVelocity) {
            mVelocity.y = -mMaxVelocity;
        }

        //deceleration
        mVelocity.y += mDeceleration;
        if (mVelocity.y > mMaxVelocity) {
            mVelocity.y = mMaxVelocity;
        }
    }
    //final move
    mSprite.move(mVelocity * deltaTime);
}