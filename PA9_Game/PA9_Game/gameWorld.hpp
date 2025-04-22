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
	//Attempted to create map base on tutorial
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
	gameWorld();
	virtual ~gameWorld() {};

	void update();
	void render(sf::RenderTarget& target);

	void updateCollision(Entity* entity, const sf::Vector2u& window);

	void generateBlock(sf::Vector2f posStr, sf::Vector2f posEnd, sf::Vector2f tileSize, sf::Texture& texture);

	void setPlayerReference(Entity* player);

	void generatePortal(sf::Vector2f pos1, sf::Vector2f pos2);


	void generateHazard(sf::Vector2f posStr, sf::Vector2f posEnd, sf::Vector2f tileSize);

	Portal GetPortal1();
	Portal GetPortal2();

};

#endif