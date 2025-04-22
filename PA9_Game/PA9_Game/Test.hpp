/*
*	Program: PA9 (Group Game Project)
*	Date: 4/12/25
*	Group:
*		Tuan Bui
*		Ashton Palma
*		Tyler Simmons
*		Brandon Weirth
*
*   File Programmer: Tuan Bui
*/

#ifndef TESTHEADERFILE
#define TESTHEADERFILE

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <stack>

#include <SFML/Graphics.hpp>

using std::cout;
using std::endl;
using std::string;
using std::cin;
using std::ostream;
using std::ifstream;
using std::ofstream;
using std::vector;
using std::stack;

//File Includes Below:


//Test Functions Declaration Below:
void TestEnemyMovement();

void TestMovementBackNForthVerticallyNHorizontally();

void TestMovementBounds();

void TestChangePositionViaPortal();

void TestEnemyPlayerInteraction();

void TestGameApplication();

#endif