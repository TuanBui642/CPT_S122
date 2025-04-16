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

#include <vector>
#include <stack>
#include <map>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

class Entity {

public:
    //core constructor
    Entity();
    //destructor
    virtual ~Entity();

    //setters
    virtual void setPosition(const float x_pos, const float y_pos);
    //member functions
    void createSprite(sf::Texture* texture);

    virtual void move(const float deltaTime, const float dir_x, const float dir_y);
    virtual void update(const float& deltaTime);
    virtual void render(sf::RenderTarget* target);

protected:
    sf::Texture* mpTexture;
    sf::Sprite* mpSprite;

    float mVelocity;

private:
    void initVariables();
};
