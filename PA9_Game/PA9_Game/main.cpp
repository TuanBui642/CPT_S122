/*
*	Program: PA9 (Group Game Project)
*	Date: 4/12/25
*	Group:
*		Tuan Bui
*		Ashton Palma
*		Tyler Simmons
*		Brandon Weirth
*/

#include "Game.hpp"

int main(void) {

	//// Platform
	//Platform platform(sf::Vector2f(width, 20.0f), { 0, 200 });


	//// Character
	//sf::RectangleShape person({ 30.0f, 30.0f });
	//person.setPosition({ 320.0f, 200.0f - 30.0f });

	//// Door/Portal
	//// Portal 1
	//Portal portal1(32.0f, { 50.0f, 200.0f - 35.0f });

	//// Portal 2
	//Portal portal2(32.0f, { 600, 200 - 35 });

	//sf::CircleShape test(30.0f);

	Game thisGame;

	thisGame.run();

	return 0;
}