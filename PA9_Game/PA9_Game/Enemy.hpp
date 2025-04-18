/*
*	Program: PA9 (Group Game Project)
*	Date: 4/12/25
*	Group:
*		Tuan Bui
*		Ashton Palma
*		Tyler Simmons
*		Brandon Weirth
*
*	File Programmer: Tuan Bui
*/

#pragma once
#include "Entity.hpp"

class Enemy : public Entity {
public:
	Enemy(float x_pos, float y_pos, sf::Texture& texture);
	virtual ~Enemy();

private:
	void initVariables();
	//void initComponents();
};