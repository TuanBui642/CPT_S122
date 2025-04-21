/*
*	Program: PA9 (Group Game Project)
*	Date: 4/12/25
*	Group:
*		Tuan Bui
*		Ashton Palma
*		Tyler Simmons
*		Brandon Weirth
*
*	File Programmer: Ashton Palma
*/

#ifndef GAMEWORLD_H
#define GAMEWORLD_H

#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include "HitBoxComponent.hpp"
#include "Player.hpp"

class gameTile; //forward-declare

class gameWorld
{
private:
	std::vector <gameTile*> tiles; //converts tiles to a vector type (shortcut)
	int windowWidth;
	int windowHeight;

public:
	gameWorld(const int width, const int height);
	~gameWorld();


	void generateBlock(sf::Vector2f posStr, sf::Vector2f posEnd, sf::Vector2f tileSize, sf::Texture& texture);

	void checkCollisions(Player& player);

	void mapBoundary(sf::Window& window, Player& person);

	void draw(sf::RenderWindow& window);



};
#endif