/*
*	Program: PA9 (Group Game Project)
*	Date: 4/12/25
*	Group:
*		Tuan Bui
*		Ashton Palma
*		Tyler Simmons
*		Brandon Weirth
*
*	File Programmer: Ashton Palma
*/

#ifndef PORTALS
#define PORTALS

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <stack>

using std::cout;
using std::endl;
using std::string;
using std::cin;
using std::ostream;
using std::ifstream;
using std::ofstream;
using std::vector;
using std::stack;
using sf::CircleShape;

#include <SFML/Graphics.hpp>

class Portal : public sf::CircleShape
{
private:

public:
	//default constructor
	Portal() : Portal(25.f, sf::Vector2f(0.f, 0.f)) {}

	//constructor 
	Portal(float size, const sf::Vector2f& pos) : CircleShape(size) {
		this->setPosition(pos);
		this->setFillColor(sf::Color::Blue);
		this->setOutlineColor(sf::Color::Magenta);
		this->setPointCount(6);
		this->setOrigin(this->getGeometricCenter());
	}

	~Portal() {};

};
#endif
