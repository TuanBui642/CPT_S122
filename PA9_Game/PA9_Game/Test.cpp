/*
*	Program: PA9 (Group Game Project)
*	Date: 4/12/25
*	Group:
*		Tuan Bui
*		Ashton Palma
*		Tyler Simmons
*		Brandon Weirth
*
*/

#include "Test.hpp"
#include "Game.hpp"

//Test Functions Below:

void TestEnemyMovement() {

    Enemy Test; //Default constructor sets it to (0.0,0.0) position
    
    float NewXCor = 10.0f;
    float NewYCor = 10.0f;

    Test.MoveEnemy(NewXCor, NewYCor);
    Test.UpdatePosition(NewXCor, NewYCor);

    cout << "X position: " << Test.GetCurXPos() << "Y position: " << Test.GetCurYPos() << endl;

    if (Test.GetCurXPos() == NewXCor && Test.GetCurYPos() == NewYCor) {

        cout << "Sprite (Enemy) has Correctly Moved from (0,0) to (10,10)" << endl;
    }
    else {

        cout << "Sprite (Enemy) has moved incorrectly" << endl;
    }

}