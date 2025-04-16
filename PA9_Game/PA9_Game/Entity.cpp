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

Entity::Entity()
{
    this->initVariables();
}

Entity::~Entity()
{
    delete mpSprite;
}

void Entity::setPosition(const float x_pos, const float y_pos)
{
    if (mpSprite != nullptr) {
        mpSprite->setPosition(sf::Vector2f(x_pos, y_pos));
    }
}

void Entity::createSprite(sf::Texture* texture)
{
    mpTexture = texture;
    mpSprite = new sf::Sprite(*mpTexture);
}

void Entity::move(const float deltaTime, const float dir_x, const float dir_y)
{
    if (mpSprite != nullptr) {
        mpSprite->move({ dir_x * mVelocity * deltaTime, dir_y * mVelocity * deltaTime });
    }
}

void Entity::update(const float& deltaTime)
{
}

void Entity::render(sf::RenderTarget* target)
{
    if (mpSprite != nullptr) {
        target->draw(*mpSprite);
    }
}

void Entity::initVariables()
{
    mpTexture = nullptr;
    mpSprite = nullptr;
    mVelocity = 100.0f;
}