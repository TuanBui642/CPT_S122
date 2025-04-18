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
using std::fmod;

#include <SFML/Graphics.hpp>
#include "Entity.hpp"

class Enemy{
public:
	Enemy(float x, float y, sf::Texture* CharTexture) {


	}

	virtual ~Enemy(); //Destructor
	
private:
	void initVariables();
	void initAnimations();
	void initComponents();

	virtual int GetHealth();
	virtual int GetDamageDelt();

	virtual void SetHealth(int NewInt);
	virtual void SetDamage(int Newint);


protected:
	int Health;
	int DamageDealt;

};

#endif