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

#ifndef ENEMIES
#define ENEMIES

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

#include <SFML/Graphics.hpp>

class Enemy : public sf::Sprite {

public:
	Enemy(const sf::Texture& CharTexture) : sf::Sprite(CharTexture){//Constructor

		this->setTexture(CharTexture);
	}; 



	~Enemy(); //Destructor

private:
	int Health;
	int DamageDealt;



protected:


};

#endif