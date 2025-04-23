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
*	Purpose: Contains all necessary attributes to create a tile that'll be use to generate all type of objects. Will be called in gameWorld
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

	//member function
	void update();
	void render(sf::RenderTarget& target);

	//getters
	sf::RectangleShape& getShape();

};


#endif