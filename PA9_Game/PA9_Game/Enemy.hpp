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

#ifndef ENEMYTYPE1
#define ENEMYTYPE1

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <stack>

#include <SFML/Graphics.hpp>
#include "Entity.hpp"

using std::cout;
using std::endl;
using std::string;
using std::cin;
using std::ostream;
using std::ifstream;
using std::ofstream;
using std::vector;
using std::stack;

class Enemy : public Entity {

public:
    Enemy(float x_pos, float y_pos, sf::Texture& texture);
    virtual ~Enemy();
private:
    void initVariables();
    void initComponents();
};



#endif
