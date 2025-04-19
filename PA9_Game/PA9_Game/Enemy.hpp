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
    bool GetRightMoveStat();
    bool GetLeftMoveStat();
    float GetRightBound();
    float GetLeftBound();
    float GetCurXPos();
    float GetCurYPos();

    //Setters
    void SetHealth(int NewInt);
    void SetDamageDelt(int NewInt);
    void SetStatus(bool NewBool);
    void SetRight(bool NewRight);
    void SetLeft(bool NewLeft);
    void SetRightBound(float NewBound);
    void SetLeftBound(float NewBound);
    void SetCurXPos(float NewFloat);
    void SetCurYPos(float NewFloat);

    //Member Functions Below
    void UpdatePosition(float x, float y);

private:
    //Functions to initalize private data members rather than calling this->(set respective)
    void initVariables();
    void initComponents();

    int health;
    int DamageDelt;
    bool Status; // True = Alive, False = Dead

    //False = No their not moving in that direction, True = Yes they are moving in that direction
    bool MovingRight;
    bool MovingLeft;

    //Would be both representative of x position as it would be like a line 1---------2, where 1 represents left bound, 2 represents right bound
    float RightBound;
    float LeftBound;

    //Representative of the Enemies position at window
    float CurrXPos;
    float CurrYPos;

};



#endif
