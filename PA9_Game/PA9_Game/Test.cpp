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

void TestMovementBackNForthVerticallyNHorizontally() {

    //Instantiate Enemy
    Enemy Test;

    //Sets Positionings and conditions for testing
    Test.SetCurXPos(100.0f);
    Test.SetCurYPos(100.0f);
    Test.SetLeftBound(0.0f);
    Test.SetRightBound(200.0f);
    Test.SetLeft(true);
    Test.SetMovingUp(true);

    float Speed = 5.0f;

    Test.MoveEnemyHorizontal(Speed, 0.0f);

    cout << "X position: " << Test.GetCurXPos() << "Y position: " << Test.GetCurYPos() << endl;

    if (Test.GetCurXPos() == 95.0f) {

        cout << "Has Correctly Moved Horizontally: " << Speed << "Going Left" << endl;
    }
    else {

        cout << "Has Incorrectly Moved Horizontally: " << Speed << "Going Left" << endl;
    }

    Test.MoveEnemyVertically(0.0f, Speed);

    cout << "X position: " << Test.GetCurXPos() << "Y position: " << Test.GetCurYPos() << endl;

    if (Test.GetCurYPos() == 95.0f) { //It's 95 as if it goes up, it's negative in the y direction

        cout << "Has Correctly Moved Horizontally: " << Speed << "Going Up" << endl;
    }
    else {

        cout << "Has Incorrectly Moved Horizontally: " << Speed << "Going Up" << endl;
    }

    

}

void TestMovementBounds() {

    //Instantiate Enemy
    Enemy Test;

    //Sets Positionings and conditions for testing
    Test.SetCurXPos(100.0f);
    Test.SetCurYPos(100.0f);
    Test.SetLeftBound(0.0f);
    Test.SetRightBound(200.0f);
    Test.SetUpperBound(200.0f);
    Test.SetLowerBound(0.0f);
    Test.SetLeft(true);
    Test.SetMovingUp(true);

    //Constant Speed Initalization
    float Speed = 5.0f;
     
    for (int i = 0; i < 50; i++) { //Loops 50 times to see if it'll function movement wise and too see if it'll go outside of bounds

        Test.MoveEnemyHorizontal(Speed, 0.0f);

        cout << "X position: " << Test.GetCurXPos() << "Y position: " << Test.GetCurYPos() << endl;

        if (Test.GetCurXPos() <= 200.0f && Test.GetCurXPos() >= 0.0f) {
            cout << "Is Correctly Within Bounds" << endl;
        }

        if (Test.GetCurXPos() == 200.0f) {
            cout << "Has Hit Upper x bound" << endl;
        }
        if (Test.GetCurXPos() == 0.0f) {

            cout << "Has Hit Lower x bound" << endl;
        }
        
        if (Test.GetCurXPos() > 200.0f) {
            cout << "Has Broken Out of Upper Bound" << endl;
        }
        if (Test.GetCurXPos() < 0.0f) {

            cout << "Has Broken Out of Lower Bound" << endl;
        }
    }

    //System pause and clear between loops for reading cout lines time
    system("pause");
    system("cls");

    for (int i = 0; i < 50; i++) {//Loops 50 times to see if it'll function movement wise and too see if it'll go outside of bounds

        Test.MoveEnemyVertically(0.0f, Speed);

        cout << "X position: " << Test.GetCurXPos() << "Y position: " << Test.GetCurYPos() << endl;

        if (Test.GetCurYPos() <= 200.0f && Test.GetCurYPos() >= 0.0f) {
            cout << "Is Correctly Within Bounds" << endl;
        }

        if (Test.GetCurYPos() == 200.0f) {
            cout << "Has Hit Upper x bound" << endl;
        }
        if (Test.GetCurYPos() == 0.0f) {

            cout << "Has Hit Lower x bound" << endl;
        }

        if (Test.GetCurYPos() > 200.0f) {
            cout << "Has Broken Out of Upper Bound" << endl;
        }
        if (Test.GetCurYPos() < 0.0f) {

            cout << "Has Broken Out of Lower Bound" << endl;
        }
    }

    //System pause and clear between loops for reading cout lines time
    system("pause");
    system("cls");
}