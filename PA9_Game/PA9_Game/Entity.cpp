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
	delete mpMovementComponent;
}

void Entity::setPosition(const float x_pos, const float y_pos)
{
	mpSprite.setPosition(sf::Vector2f(x_pos, y_pos));
}

void Entity::setTexture(sf::Texture& texture)
{
	mpSprite.setTexture(texture);
}

void Entity::createMovementComponent(const float maxVelocity, const float acceleration,
	const float deceleration)
{
	mpMovementComponent = new MovementComponent(mpSprite, maxVelocity, acceleration,deceleration);
}

void Entity::move(const float deltaTime, const float dir_x, const float dir_y)
{
	if (mpMovementComponent != nullptr) {
		mpMovementComponent->move(dir_x, dir_y, deltaTime);
	}
}

void Entity::update(const float& deltaTime)
{
	if (mpMovementComponent != nullptr) {
		mpMovementComponent->update(deltaTime);
	}
}

void Entity::render(sf::RenderTarget* target)
{
	target->draw(mpSprite);
}

void Entity::initVariables()
{
	mpMovementComponent = nullptr;
}