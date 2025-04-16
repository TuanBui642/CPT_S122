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

int main(void) {


		unsigned int width = 1280;
		unsigned int height = 720;

		sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode({ width,height }), "Game Window!");
		window->setFramerateLimit(60);

		// Platform									
		Platform platform(sf::Vector2f(width, 20.0f), { 0, 200 });

		//Seconds Usage
		sf::Clock Clock;

		// Character
		sf::RectangleShape person({ 30.0f, 30.0f });
		person.setPosition({ 320.0f, 200 - 30 });

		// Door/Portal
		// Portal 1
		Portal portal1(32.0, { 50, 200 - 35 });

		// Portal 2
		Portal portal2(32.0, { 600, 200 - 35 });


		// Game physics
		bool isJumping = false;
		bool justTeleported = false;
		float velocityY = 0.0f;
		const float gravity = 0.5f;
		const float jumpStrength = -10.0f;

		while (window->isOpen()) {
			PollEvents(*window, isJumping);

			// Controls
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
			{
				person.move({ 5, 0 });
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
			{
				person.move({ -5, 0 });
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && !isJumping)
			{
				velocityY = jumpStrength;
				isJumping = true;
			}

			// Apply gravity
			velocityY += gravity;
			person.move({ 0, velocityY });

			//Collision with platform
			sf::FloatRect platformBounds = platform.getGlobalBounds();
			if (person.getGlobalBounds().findIntersection(platformBounds)) {
				person.setPosition({ person.getPosition().x, platform.getPosition().y - 30 });
				velocityY = 0;
				isJumping = false;
			}

			// Teleport logic
			if (!justTeleported) {
				if (person.getGlobalBounds().findIntersection(portal1.getGlobalBounds())) {
					person.setPosition({ portal2.getPosition().x, portal2.getPosition().y });
					justTeleported = true;
				}
				else if (person.getGlobalBounds().findIntersection(portal2.getGlobalBounds())) {
					person.setPosition({ portal1.getPosition().x, portal1.getPosition().y });
					justTeleported = true;
				}
			}
			else {
				// Reset teleport flag when character is not interacting portal
				if (!person.getGlobalBounds().findIntersection(portal1.getGlobalBounds()) &&
					!person.getGlobalBounds().findIntersection(portal2.getGlobalBounds())) {
					justTeleported = false;
				}
			}

			// Rotate portals
			portal1.rotate(sf::degrees(1));
			portal2.rotate(sf::degrees(1));

			// Rendering
			window->clear();

			// Draw Shape
			window->draw(platform);
			window->draw(portal1);
			window->draw(portal2);
			window->draw(person);

			//Prints Elapsed Time to Terminal
			//sf::Time TimePassed = Clock.getElapsedTime();
			//int seconds = TimePassed.asSeconds();
			//cout << "Time Passed (Sec):" << seconds << endl;

			//system("cls");

			//Display Window
			window->display();
		}

	return 0;
}

/* Menu Implementation Later On

	int MenuOption = 0;
	cout << "Welcome To Our Game!" << endl;
	while (MenuOption != 4) { //Current Issue, if we use a while Loop, any and all input done by the player while running the game will transmit to the terminal when their done

		cout << "Menu:\n\t1:Play Game\n\t2:Game Information / Instructions\n\t3:Settings\n\t4:Exit" << endl;
		cin >> MenuOption;
		cin.clear();

		if (MenuOption == 1){
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
			return 0;
		}



	}


*/