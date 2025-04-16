/*
*	Program: PA9 (Group Game Project)
*	Date: 4/12/25
*	Group:
*		Tuan Bui
*		Ashton Palma
*		Tyler Simmons
*		Brandon Weirth
* 
*	Outside Contributers
*		Connin Molo
*			ANY AND ALL CREDIT OF SPRITE DESIGN GOES TO CONNIN MOLO
*/

#include "Functions.hpp"

void PollEvents(sf::RenderWindow& window, bool& isJumping) {
	while (const std::optional event = window.pollEvent()) {
		if (event->is<sf::Event::Closed>()) {
			window.close();
		}
		else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
			if (keyPressed->scancode == sf::Keyboard::Scancode::Escape) {
				window.close();
			}
		}
		else if (event->is<sf::Event::KeyReleased>()) {
			isJumping = false;
		}
	}
}

void RunGame() {

}

void GameInformation() {
	system("cls"); //Clears Menu Screen

	cout << "\tDevelopers:\n\tTuan Bui\n\tAshton Palma\n\tTyler Simmons\n\tBrandon Weirth\n" << endl;
	cout << "\n\tGame Instructions: " << endl; //Add more when we have more ideas/structure of Game

	system("pause");

}

void Settings() {

	system("cls");//Clears Menu Screen

	//Add stuff in here when we have ideas for setting configurations

	system("pause");
	
}