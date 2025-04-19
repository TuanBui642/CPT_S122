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

#ifndef ENEMY
#define ENEMY

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
    //Constructor
    Enemy(float x_pos, float y_pos, sf::Texture& texture);
    virtual ~Enemy(); //Destructor

    //Getters
    int GetHealth();
    int GetDamageDelt();
    bool GetStatus();

    //Setters
    void SetHealth(int NewInt);
    void SetDamageDelt(int NewInt);
    void SetStatus(bool NewBool);

    //Member Functions Below


private:
    void initVariables();
    void initComponents();

    int health;
    int DamageDelt;
    bool Status; // True = Alive, False = Dead

};



#endif
