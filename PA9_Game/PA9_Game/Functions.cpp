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
#include "Portal.hpp"
#include "Platform.hpp"
#include "Enemies.hpp"

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

	system("cls");//Clears Menu Screen

	unsigned int width = 1280;
	unsigned int height = 720;

	sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode({ width,height }), "Tutorials");
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

		system("cls");

		//Display Window
		window->display();
	}

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