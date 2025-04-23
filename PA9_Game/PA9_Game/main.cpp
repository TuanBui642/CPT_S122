/*
*Program: PA9 (Group Game Project)
*Date: 4/12/25
*Group:
*Tuan Bui
*Ashton Palma
*Tyler Simmons
*Brandon Weirth
*
*Outside Contributers
*Connin Molo
*ANY AND ALL CREDIT OF SPRITE DESIGN GOES TO CONNIN MOLO
*/

#include "Test.hpp"
#include "Game.hpp"

int main(void) {

	//Please Note that any input in the game will go to the terminal

	int dec = 0;
	int pick = 0;

	while (dec != 5) {

		system("cls");

		printa();
		cin >> dec;
		if (dec == 1)
		{
			system("cls");
			Game thisGame;
			thisGame.run();
		}
		else if (dec == 2)
		{
			system("cls");
			InstructionsOnGame();
		}
		else if (dec == 3)
		{
			system("cls");
			cout << "(1) Test Enemy Movement\n"
				<< "(2) Test Enemy To Move Horizontally and Vertically\n"
				<< "(3) Test Game Application\n"
				<< "(4) Test Movement Bounds\n"
				<< "(5) Test Enemy and Player Interaction\n"
				<< "(6) Test Change Position Via Portal\n" << endl;
			cin >> pick;

			if (pick == 1)
			{
				system("cls");
				TestEnemyMovement();
			}
			else if (pick == 2)
			{
				system("cls");
				TestMovementBackNForthVerticallyNHorizontally();
			}
			else if (pick == 3)
			{
				system("cls");
				TestGameApplication();
			}
			else if (pick == 4)
			{
				system("cls");
				TestMovementBounds();
			}
			else if (pick == 5)
			{
				system("cls");
				TestEnemyPlayerInteraction();
			}
			else if (pick == 6) {
				system("cls");
				TestChangePositionViaPortal();
			}
		}
		else if (dec == 4) {

			system("cls");
			AdditionalInformation();
		}
		else if (dec == 5)
		{
			system("cls");
			cout << "Exiting Game.... Thanks for Playing!";

			return 0;
		}

	}


	return 0;
}



