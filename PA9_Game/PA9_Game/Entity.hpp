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

#ifndef ENTITY
#define ENTITY

#include "MovementComponent.hpp"
#include "AnimationComponent.hpp"
#include "HitboxComponent.hpp"

class Entity{

public:
   // Entity();
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
    void createHitboxComponent(sf::Sprite& sprite, float offsetX, float offsetY,
        float width, float height);
    void createAnimationComponent(sf::Texture& textureSheet);

    virtual void move(const float deltaTime, const float dir_x, const float dir_y);
    virtual void update(const float& deltaTime);
    virtual void render(sf::RenderTarget& target);

    sf::Sprite getmpSprite();

protected:
    sf::Sprite mpSprite;

    HitboxComponent* mpHitboxComponent;
    MovementComponent* mpMovementComponent;
    AnimationComponent* mpAnimationComponent;

private:
    void initVariables();
};

#endif
