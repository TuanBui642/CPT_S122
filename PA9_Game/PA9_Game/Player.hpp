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

class Player : public Entity {
public:
    Player(float x_pos, float y_pos, sf::Texture& texture);
    virtual ~Player();

private:
    void initVariables();
    void initComponents();
};