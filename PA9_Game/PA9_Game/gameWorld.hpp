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
*	Purpose: Calls in classes from gameTile, Portal and Hazard. This class has member functions containing instruction to create the game layout and environment
*/


#ifndef GAMEWORLDHEADER
#define GAMEWORLDHEADER

#include <vector>
#include <string>
#include <SFML/Graphics.hpp>

#include "HitBoxComponent.hpp"
#include "Player.hpp"
#include "gameTile.hpp"
#include "Portal.hpp"
#include "Hazard.hpp"

class gameWorld
{
private:

	float gridSizeF;
	unsigned gridSizeU;
	sf::Vector2u maxSize;
	unsigned layers;
	std::vector< std::vector< std::vector<gameTile > > > map;

	std::vector<gameTile> tiles;

	//Portal
	Portal portal1;
	Portal portal2;
	Portal exit;
	bool justTeleported;
	Entity* playerRef;

	//Hazard
	std::vector<Hazard> deadZone;

public:
	//Constructor
	gameWorld();
	//Destructor
	virtual ~gameWorld() {};

	//Memberfunction
	void update();
	void render(sf::RenderTarget& target);
	void updateCollision(Entity* entity, const sf::Vector2u& window, sf::RenderWindow* rwindow);
	void generateBlock(sf::Vector2f posStr, sf::Vector2f posEnd, sf::Vector2f tileSize, sf::Texture& texture);
	void setPlayerReference(Entity* player);
	void generatePortal(sf::Vector2f pos1, sf::Vector2f pos2, sf::Vector2f pos3);
	void generateHazard(sf::Vector2f posStr, sf::Vector2f posEnd, sf::Vector2f tileSize);

	//getters
	Portal getPortal1();
	Portal getPortal2();
	Portal getExit();

};

#endif