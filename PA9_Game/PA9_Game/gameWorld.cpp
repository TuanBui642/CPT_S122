#include "gameWorld.hpp"
#include "gameTile.hpp"

gameWorld::gameWorld(const int width, const int height)
{
	this->windowHeight = height;
	this->windowWidth = width;
}

gameWorld::~gameWorld()
{
	for (int i = 0; i < tiles.size(); i++)
	{
		delete tiles[i];
	}
}

//Functions that generate different objects
//parameter( start coord (x,y), end coord (x,y), tile size (x,y)
//void generatePlatform(sf::Vector2f posStr, sf::Vector2f posEnd, sf::Vector2f tileSize)
//{
//	for (float i = posStr.x; i <= posEnd.x; i += tileSize.x)
//	{	//insert a new tile after the previous

//		sf::Vector2f newPos = { i, posStr.y };
//		tiles.push_back(new gameTile("platform", tileSize, newPos));
//	}
//}

//void generateWall(sf::Vector2f posStr, sf::Vector2f posEnd, sf::Vector2f tileSize)
//{
//	for (float i = posStr.y; i <= posEnd.y; i += tileSize.y)
//	{	//insert a new tile after the previous

//		sf::Vector2f newPos = { posStr.x, i };
//		tiles.push_back(new gameTile("wall", tileSize, newPos));
//	}
//}

void gameWorld::generateBlock(sf::Vector2f posStr, sf::Vector2f posEnd, sf::Vector2f tileSize, sf::Texture& texture)
{

	for (float i = posStr.y; i <= posEnd.y; i += tileSize.y)
	{
		for (float k = posStr.x; k <= posEnd.x; k += tileSize.x)
		{
			sf::Vector2f newPos = { k, i };
			sf::Sprite sprite(texture);

			tiles.push_back(new gameTile("Block", tileSize, { k, i }, sprite, texture));

		}
	}
}

void gameWorld::checkCollisions(sf::RectangleShape& person, float& velocityY, bool& isJumping)
{
	for (int i = 0; i < tiles.size(); i++)
	{
		if (tiles[i])
		{
			tiles[i]->collisionStatus(person, velocityY, isJumping, 0);
		}
	}
}

void gameWorld::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < tiles.size(); ++i)
	{
		tiles[i]->render(&window);
	}
}