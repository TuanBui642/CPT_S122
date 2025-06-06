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
    Enemy();
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
    sf::Texture GetCurTexture();
    float GetUpperBound();
    float GetLowerBound();
    bool GetMovingUp();
    bool GetMovingDown();
    sf::RectangleShape GetEnemyShape();

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
    void SetCharTexture(sf::Texture Texture);
    void SetUpperBound(float NewUpper);
    void SetLowerBound(float NewLower);
    void SetMovingUp(bool NewBool);
    void SetMovingDown(bool NewBool);

    //Member Functions Below

    //Updates the Position of the Respected Sprite Based on passed in position, would typically use RIGHT AFTER .move() function to 
    // update it's position each loop when moving
    virtual void UpdatePosition(float x, float y);

    //Update DeltaTime for Enemy (ENDED UP NOT USING)
    virtual void Update(const float& deltaTime);

    //Moves enemy in a certain way
    void MoveEnemy(const float x, const float y);

    //Functions that'll move the enemy back and forth depending on set position, and the bounds passed in
    //Horizontal would have a right and left bound
    //Vertical would have a Upper and Lower Bound
    void MoveEnemyHorizontal(const float x, const float y);
    void MoveEnemyVertically(const float x, const float y);

    

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

    //Representative of Y-axis, similar to Right/Left Bound but Vertical
    float UpperBound;
    float LowerBound;

    //Representative of the Enemies position at window
    float CurrXPos;
    float CurrYPos;

    //False = No their not moving in that direction, True = Yes they are moving in that direction
    bool MovingUp;
    bool MovingDown;

    //Utilizing this allows the use of using getGlobalBounds and other member functions of 
    //RectangleShape for each respected sprite, used to determine if enemy/player interacted
    //with one another to respawn player
    sf::RectangleShape CharShape;

    sf::Texture CharTexture;

};



#endif
