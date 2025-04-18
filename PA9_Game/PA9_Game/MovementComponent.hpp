#pragma once

#include <vector>
#include <stack>
#include <map>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

class MovementComponent {
public:
    MovementComponent(sf::Sprite& sprite, float maxVelocity, float acceleration,
        float deceleration);
    virtual ~MovementComponent();

    //getters
    const sf::Vector2f getVelocity() const;

    //member functions
    void move(const float dir_x, const float dir_y, const float deltaTime);
    void update(const float& deltaTime);

private:
    float mMaxVelocity;
    sf::Sprite& mSprite;
    sf::Vector2f mVelocity;
    float mAcceleration;
    float mDeceleration;
};
