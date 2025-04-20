///*
//*	Program: PA9 (Group Game Project)
//*	Date: 4/12/25
//*	Group:
//*		Tuan Bui
//*		Ashton Palma
//*		Tyler Simmons
//*		Brandon Weirth
//*
//*	File Programmer: Ashton Palma
//*/
//
//#ifndef HARZARD_H
//#define HAZARD_H
//
//#include <SFML/Graphics.hpp>  
//#include "Entity.hpp"
//#include "gameTile.hpp"
//#include "gameWorld.hpp"
//
//class Hazard : public sf::RectangleShape
//{
//private:
//	std::vector<gameTile*> tiles;
//	int windowWidth;
//	int windowHeight;
//
//public:
//	//constructor
//	Hazard(const int width, const int height)
//	{
//		this->windowHeight = height;
//		this->windowWidth = width;
//	}
//
//	//destructor
//	~Hazard()
//	{
//		for (int i = 0; i < tiles.size(); ++i)
//		{
//			delete tiles[i];
//		}
//	}
//
//	void generateBlock(sf::Vector2f posStr, sf::Vector2f posEnd, sf::Vector2f tileSize)
//	{
//		for (float i = posStr.y; i <= posEnd.y; i += tileSize.y)
//		{
//			for (float k = posStr.x; k <= posEnd.x; k += tileSize.x)
//			{
//				sf::Vector2f newPos = { k, i };
//				tiles.push_back(new gameTile("Block", tileSize, newPos));
//			}
//		}
//	}
//
//	void deathzone(sf::RectangleShape& person, float& velocityY, bool& isJumping)
//	{
//		for (int i = 0; i < tiles.size(); i++)
//		{
//			if (tiles[i])
//			{
//				tiles[i]->collisionStatus(person, velocityY, isJumping, 1);
//			}
//		}
//	}
//
//	void draw(sf::RenderWindow& window)
//	{
//		for (int i = 0; i < tiles.size(); i++)
//		{
//			tiles[i]->render(&window);
//		}
//	}
//
//
//};
//
//#endif
