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

#ifndef PLATFORM
#define PLATFORM

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
using sf::RectangleShape;

#include <SFML/Graphics.hpp>

class Platform : public RectangleShape
{
private:

public:
	//constructor 
	Platform(const sf::Vector2f& size, const sf::Vector2f& pos) : RectangleShape(size){
		this->setFillColor(sf::Color::Green);
		this->setPosition(pos);
	}

};

#endif