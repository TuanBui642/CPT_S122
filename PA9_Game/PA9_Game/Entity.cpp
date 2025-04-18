#pragma once
#include "Entity.hpp"

Entity::Entity(sf::Sprite sprite, sf::Texture texture) : mSprite(texture)
{
	this->initVariables();
}

Entity::~Entity()
{
	delete mpMovementComponent;
}

void Entity::setPosition(const float x_pos, const float y_pos)
{
	mSprite.setPosition(sf::Vector2f(x_pos, y_pos));
}

void Entity::setTexture(sf::Texture& texture)
{
	mSprite.setTexture(texture);
}

void Entity::createMovementComponent(const float maxVelocity, const float acceleration,
	const float deceleration)
{
	mpMovementComponent = new MovementComponent(mSprite, maxVelocity, acceleration,
		deceleration);
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
	target->draw(mSprite);
}

void Entity::initVariables()
{
	mpMovementComponent = nullptr;
}
