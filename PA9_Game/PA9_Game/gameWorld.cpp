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

void gameWorld::checkCollisions(Player& player)
{
	for (auto tile : tiles)
	{
		if (tile)
		{
			tile->collisionStatus(player, 0);
		}
	}
}

void gameWorld::mapBoundary(sf::Window& window, Player& person)
{
	sf::Vector2f pos = person.getPosition();
	sf::Vector2f size = person.getHitboxComponent()->getmHitBox().getSize();

	if (pos.x + size.x >= window.getSize().x - 32)
	{
		person.setPosition(window.getSize().x - size.x - 32, pos.y);
	}

	if (pos.x <= -30)
	{
		person.setPosition(-30.f, pos.y);
	}

	if (pos.y + size.y >= window.getSize().y)
	{
		person.setPosition(pos.x, window.getSize().y - size.y - 30);
	}

	if (pos.y <= 0)
	{
		person.setPosition(pos.x, 0.f);
	}
}



void gameWorld::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < tiles.size(); ++i)
	{
		tiles[i]->render(window);
	}
}