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

#ifndef GAMETILEHPP
#define GAMETILEHPP

#include<iostream>
#include<ctime>
#include<cstdlib>
#include<fstream>
#include<sstream>
#include<vector>

#include "SFML\System.hpp"
#include "SFML\Window.hpp"
#include "SFML\Graphics.hpp"

class gameTile {
private:
	sf::RectangleShape object;
	std::string objectType;

protected:
	sf::RectangleShape shape;

public:
	//constructor 
	gameTile();
	//copy constructor
	gameTile(float x, float y, float gridSizeF);
	//destructor
	virtual ~gameTile() {};

	void update();
	void render(sf::RenderTarget& target);


	//not part of tutor
	sf::RectangleShape& getShape();

};


#endif