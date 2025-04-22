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

void printa() {
    cout << "\n-Main Menu-\n"
        << "(1) Play the Game\n"
        << "(2) Instruction on Game\n"
        << /*"(3) Settings \n"
        <<*/ "(3) Test Cases\n"
        << "(4) Additional Information\n"
        << "(5) Exit Game\n";
}

void InstructionsOnGame() {

    cout << "Game Instrutions!" << endl << endl;

    cout << "Due to the incomplete progress of the second floor, the main goal will be to pass the first floor" <<
        " and enter the blue portal at the end of the first floor, while doing so, your goal will also be to avoid " <<
        "the enemies present on the first level" << endl;
    cout << endl << "Configured Controls:\n(D) Move Right\n(A) Move Left\n(Space) Attack [Just animation, no interaction]\n(Shift) Run/Sprint" << endl;

    cout << "Good Luck and have fun! Be aware of the flipper!" << endl;

    system("pause");
    system("cls");

}

void Settings() {

    cout << "Wasn't able to configure settings for game" << endl;

    system("pause");
    system("cls");
}

void AdditionalInformation() {

    cout << "Game/Project Additional Information" << endl << endl;

    cout << "Inspired/Concepted off of a 2d platformer idea" << endl;
    cout << "Our main idea was to have three level/floors with a portal at the end of each with respected obstacles and enemies on each level" << endl;
    cout << "At the end, we were unable to configure gravity for player when player interacts with platforms and it would stop the animation of the player" << endl;
    cout << "So the only complete level currently is the first floor (the floor that the player starts on), where we didn't apply jumping bridges or any obstacle " <<
        "utilize the jump mechanic" << endl;

    system("pause");
    system("cls");
}

//Test Functions Below:
void TestGameApplication() {

    Game TestGame;

    TestGame.run();
}

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



void TestChangePositionViaPortal() {

    sf::Texture CharTexture;
    CharTexture.loadFromFile("Sprites/Protag_.png");

    Player Test(CharTexture);

    Test.SetCurXPos(100.0f);
    Test.SetCurYPos(100.0f);
    
    sf::Sprite sprite(CharTexture);

    sprite.setPosition(sf::Vector2f({ 70,100}));
  
    gameWorld TestPortal;
    TestPortal.generatePortal(sf::Vector2f({ 80,100 }), sf::Vector2f({ 200,200 }));

    // portal1 portal2
    

    const float DeltaTime = 1.0f;

    Test.setPosition(100.0f, 100.0f);

    cout << "Sprites Position Before Moving" << sprite.getPosition().x << sprite.getPosition().y << endl;

        sprite.move(sf::Vector2f({ 10,0 })); //Moves ten x coordinates to Right to portal to test interaction

        cout << "Sprites Position" << sprite.getPosition().x << sprite.getPosition().y << endl;
        cout << "Portal Position: " << TestPortal.GetPortal1().getPosition().x << endl;
     
        if (sprite.getGlobalBounds().findIntersection(TestPortal.GetPortal1().getGlobalBounds())) {

            cout << "Player Has Interacted with Portal 1 and respawned" << endl;
           
        }
        else {
            cout << "Player Has not been able to interact with Portal and didn't respawn" << endl;
        }

  //  TestPortal.GetPortal1().getPosition();
    
}

void TestEnemyPlayerInteraction() {

    sf::Texture CharTexture;
    Player TestPlayer(CharTexture);
    Enemy TestEnemy;

    TestPlayer.SetCurXPos(100.0f);
    TestPlayer.SetCurYPos(100.0f);

    TestEnemy.SetUpperBound(80.0f);
    TestEnemy.SetLowerBound(130.0f);
    TestEnemy.SetMovingDown(true);
    TestEnemy.SetCurXPos(100.0f);
    TestEnemy.SetCurYPos(120.0f);

    
    for (int i = 0; i < 4; i++) {

        TestEnemy.MoveEnemyVertically(0.0f, 10.0f);

        cout << "Enemy Position: " << TestEnemy.GetCurXPos() << TestEnemy.GetCurYPos() << endl;

        if (TestEnemy.GetCurXPos() == TestPlayer.GetCurXPos() && TestEnemy.GetCurYPos() == TestPlayer.GetCurYPos()) {

            cout << "Test Player Has been able to Interact with portal" << endl;

            TestPlayer.setPosition(0.0f, 130.0f);

            if (TestPlayer.getPosition().x == 0.0 && TestPlayer.getPosition().y == 130) {

                cout << "Test Player has respawned at Correct Position (0.0,130.0)" << endl;
            }
            else {

                cout << "Test Player has incorrectly respawned at Position: (" << TestPlayer.getPosition().x << 
                    TestPlayer.getPosition().y << ")" << endl;
            }
        }
        else {

            cout << "Either\n1: Yet to Interact\n2: Didn't Or Can't Iteract" << endl;
        }

    }
}