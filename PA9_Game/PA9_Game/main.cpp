/*
*	Program: PA9 (Group Game Project)
*	Date: 4/12/25
*	Group:
*		Tuan Bui
*		Ashton Palma
*		Tyler Simmons
*		Brandon Weirth
*/

#include "Functions.hpp"

int main(void) {

	int MenuOption = 0;

	//while (MenuOption != 4) { //Current Issue, if we use a while Loop, any and all input done by the player while running the game will transmit to the terminal when their done

		system("cls");
		cout << "Welcome To Our Game!\nMenu:\n\t1:Play Game\n\t2:Game Information/Instructions\n\t3:Settings\n\t4:Exit" << endl;
		cin >> MenuOption;

		if (MenuOption == 1) {

			RunGame();
		}
		else if (MenuOption == 2) {

			GameInformation();
		}
		else if (MenuOption == 3) {

			Settings();
		}
		else {

			system("cls");
			cout << "Exited Game" << endl;
			cout << "Thanks For Playing!" << endl;
		}

	
		
	//}



	return 0;
}