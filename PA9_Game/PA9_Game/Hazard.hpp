///*
//*	Program: PA9 (Group Game Project)
//*	Date: 4/12/25
//*	Group:
//*		Tuan Bui
//*		Ashton Palma
//*		Tyler Simmons
//*		Brandon Weirth
//*
//*	File Programmer: Ashton Palma
//* Purpose: Contains all necessary attributes to create a tile specifically for hazardous object. Will be called in gameWorld

#ifndef HAZARD_H
#define HAZARD_H

#include <SFML/Graphics.hpp>
#include "gameTile.hpp"

class Hazard : public sf::RectangleShape
{
private:

public:
	// Constructor 
	Hazard() : Hazard({ 20.f,20.f }, { 0.f, 0.f }) {};
	
	Hazard(sf::Vector2f size, const sf::Vector2f& pos) : RectangleShape(size)
	{
		this->setPosition(pos);
		this->setFillColor(sf::Color::White);
	}
	~Hazard() {};

};

#endif