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

#include "MovementComponent.hpp"

class Entity{

public:
    //core constructor
    Entity(sf::Sprite sprite, sf::Texture texture);
    //destructor
    virtual ~Entity();

    //setters
    virtual void setPosition(const float x_pos, const float y_pos);
    //member functions
    void setTexture(sf::Texture& texture);
    void createMovementComponent(const float maxVelocity,
        const float acceleration, const float deceleration);

    virtual void move(const float deltaTime, const float dir_x, const float dir_y);
    virtual void update(const float& deltaTime);
    virtual void render(sf::RenderTarget* target);

protected:
    sf::Sprite mpSprite;
    MovementComponent* mpMovementComponent;

private:
    void initVariables();
};
