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

#include "Entity.hpp"


Entity::Entity(sf::Sprite sprite, sf::Texture texture) : mpSprite(texture)
{
	this->initVariables();
}

Entity::~Entity()
{
	delete mpHitboxComponent;
	delete mpMovementComponent;
	delete mpAnimationComponent;
}

//set position of entity
void Entity::setPosition(const float x_pos, const float y_pos)
{
	mpSprite.setPosition(sf::Vector2f(x_pos, y_pos));
}

//set texture of entity
void Entity::setTexture(sf::Texture& texture)
{
	mpSprite.setTexture(texture);
}

//create a hitbox for the entity
void Entity::createHitboxComponent(sf::Sprite& sprite, float offsetX, float offsetY,
	float width, float height)
{
	mpHitboxComponent = new HitboxComponent(sprite, offsetX, offsetY, width, height);
}

//create a movement component for the entity
void Entity::createMovementComponent(const float maxVelocity, const float acceleration,
	const float deceleration)
{
	mpMovementComponent = new MovementComponent(mpSprite, acceleration,deceleration);
}

//create an animation component for the entity
void Entity::createAnimationComponent(sf::Texture& textureSheet)
{
	mpAnimationComponent = new AnimationComponent(mpSprite, textureSheet);
}

//move the entity
void Entity::move(const float deltaTime, const float dir_x, const float dir_y)
{
	if (mpMovementComponent != nullptr) {
		mpMovementComponent->move(dir_x, dir_y, deltaTime);
	}
}

//update the entity
void Entity::update(const float& deltaTime)
{
	if (mpMovementComponent != nullptr) {
		mpMovementComponent->update(deltaTime);
	}
}

//render the entity
void Entity::render(sf::RenderTarget& target)
{
	target.draw(mpSprite);

	if (mpHitboxComponent) {
		mpHitboxComponent->render(target);
	}
}

//return sprite pointer for entity
sf::Sprite Entity::getmpSprite()
{
	return mpSprite;
}

//initialize entity variables
void Entity::initVariables()
{
	mpHitboxComponent = nullptr;
	mpMovementComponent = nullptr;
	mpAnimationComponent = nullptr;
}

//get the position of the entity
const sf::Vector2f& Entity::getPosition() const
{
	if (mpHitboxComponent)
	{
		return mpHitboxComponent->getPosition();
	}

	return this->mpSprite.getPosition();
}

//get the global bounds of the entity
const sf::FloatRect Entity::getGlobalBounds() const
{
	if (mpHitboxComponent)
	{
		return mpHitboxComponent->getGlobalBounds();
	}

	return this->mpSprite.getGlobalBounds();
}

//Stops Respected Velocity of X,Y, or Velocity
void Entity::stopVelocity()
{
	if (mpMovementComponent)
	{
		mpMovementComponent->stopVelocity();
	}
}

void Entity::stopVelocityY()
{
	if (mpMovementComponent)
	{
		mpMovementComponent->stopVelocityY();
	}
}

void Entity::stopVelocityX()
{
	if (mpMovementComponent)
	{
		mpMovementComponent->stopVelocityX();
	}
}