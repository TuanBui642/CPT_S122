#ifndef GAMEWORLD_H
#define GAMEWORLD_H

#include "gameTile.hpp"

class gameWorld
{
private:
	std::vector<gameTile*> tiles; //converts tiles to a vector type (shortcut)
	int windowWidth;
	int windowHeight;

public:
	gameWorld(const int width, const int height)
	{
		this->windowHeight = height;
		this->windowWidth = width;
	}

	~gameWorld()
	{
		for (int i = 0; i < tiles.size(); i++)
		{
			delete tiles[i];
		}
	}

	//Functions that generate different objects
	//parameter( start coord (x,y), end coord (x,y), tile size (x,y)
	void generatePlatform(sf::Vector2f posStr, sf::Vector2f posEnd, sf::Vector2f tileSize)
	{
		for (float i = posStr.x; i <= posEnd.x; i += tileSize.x)
		{	//insert a new tile after the previous

			sf::Vector2f newPos = { i, posStr.y };
			tiles.push_back(new gameTile("platform", tileSize, newPos));
		}
	}

	void generateWall(sf::Vector2f posStr, sf::Vector2f posEnd, sf::Vector2f tileSize)
	{
		for (float i = posStr.y; i <= posEnd.y; i += tileSize.y)
		{	//insert a new tile after the previous

			sf::Vector2f newPos = { posStr.x, i };
			tiles.push_back(new gameTile("wall", tileSize, newPos));
		}
	}

	void generateBlock(sf::Vector2f posStr, sf::Vector2f posEnd, sf::Vector2f tileSize)
	{
		for (float i = posStr.y; i <= posEnd.y; i += tileSize.y)
		{
			for (float k = posStr.x; k <= posEnd.x; k += tileSize.x)
			{
				sf::Vector2f newPos = { k, i };
				tiles.push_back(new gameTile("Block", tileSize, newPos));
			}
		}
	}

	void checkCollisions(sf::RectangleShape& person, float& velocityY, bool& isJumping)
	{
		for (int i = 0; i < tiles.size(); i++)
		{
			if (tiles[i])
			{
				tiles[i]->collisionStatus(person, velocityY, isJumping, 0);
			}
		}
	}

	void draw(sf::RenderWindow& window)
	{
		for (int i = 0; i < tiles.size(); ++i)
		{
			tiles[i]->render(&window);
		}
	}


};
#endif