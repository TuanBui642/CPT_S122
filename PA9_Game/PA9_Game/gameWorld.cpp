#include "gameWorld.hpp"
#include "gameTile.hpp"
#include "hazard.hpp"


gameWorld::gameWorld()
{
	//Attempted map base on tutorial
	//this->gridSizeF = 50.f;
	//this->gridSizeU = static_cast<unsigned>(this->gridSizeF);
	//this->maxSize.x = 10;
	//this->maxSize.y = 10;
	//this->layers = 1;

	//// Resize 3D vector properly: map[x][y][z]
	//this->map.resize(this->maxSize.x); // x-dimension
	//for (size_t x = 0; x < this->maxSize.x; x++)
	//{
	//	this->map[x].resize(this->maxSize.y); // y-dimension
	//	for (size_t y = 0; y < this->maxSize.y; y++)
	//	{
	//		this->map[x][y].resize(this->layers); // z-dimension (layers)

	//		for (size_t z = 0; z < this->layers; z++)
	//		{
	//			this->map[x][y][z] = gameTile(x * this->gridSizeF, y * this->gridSizeF, this->gridSizeF);
	//		}
	//	}
	//}

	portal1 = Portal(25.f, sf::Vector2f(1400, 150));
	portal2 = Portal(25.f, sf::Vector2f(1450, 470));
	exit = Portal(25.f, sf::Vector2f(260, 470));
	justTeleported = false;
	playerRef = nullptr;

}

void gameWorld::update()
{
}

void gameWorld::render(sf::RenderTarget& target)
{
	for (auto& x : this->map)
	{
		for (auto& y : x)
		{
			for (auto& z : y)
			{
				z.render(target);
			}
		}
	}

	for (auto& tile : this->tiles)
	{
		tile.render(target);
	}

	for (auto& hazardBlock : deadZone)
	{
		target.draw(hazardBlock);
	}

	target.draw(portal1);
	target.draw(portal2);
	target.draw(exit);
}

void gameWorld::updateCollision(Entity* entity, const sf::Vector2u& window)
{
	//window collision logic
	if (entity->getPosition().x < -20)
	{
		entity->setPosition(-20.f, entity->getPosition().y);
		entity->stopVelocityX();
	}
	else if (entity->getPosition().x  /*+ entity->getGlobalBounds().*/ > (window.x - 50))
	{
		entity->setPosition(window.x - 50 /*- entity->getGlobalBounds().size.x*/, entity->getPosition().y);
		entity->stopVelocityX();
	}
	if (entity->getPosition().y < 0.f)
	{
		entity->setPosition(entity->getPosition().x, 0.f);
		entity->stopVelocityX();
	}
	else if (entity->getPosition().y + entity->getGlobalBounds().size.y > window.y)
	{
		entity->setPosition(entity->getPosition().x, window.y - entity->getGlobalBounds().size.y);
		entity->stopVelocityX();
	}

	//Block collision logic
	for (auto& tile : tiles)
	{
		if (entity->getGlobalBounds().findIntersection(tile.getShape().getGlobalBounds()))
		{
			sf::Vector2f tilePos = tile.getShape().getPosition();
			sf::Vector2f tileSize = tile.getShape().getSize();
			sf::FloatRect entityBounds = entity->getGlobalBounds();
			sf::Vector2f size = entity->getGlobalBounds().size;//getHitboxComponent()->getmHitBox().getSize();

			// Landing on top of the tile
			if ((entity->getPosition().y - size.y) /*+ entityBounds.size.y*/ <= (tilePos.y - tileSize.y))//+ 10.f) // add tolerance
			{
				entity->setPosition(entity->getPosition().x, (tilePos.y - tileSize.y - 31)  /*- entityBounds.size.y*/);
				entity->stopVelocityY();
				/*  entity->setJumping(false);*/
			}
			// Hitting the bottom of the tile
			if (entity->getPosition().y >= tilePos.y + tileSize.y - 10.f)
			{
				entity->setPosition(entity->getPosition().x, tilePos.y + tileSize.y);
				entity->stopVelocityY();
			}

			//// Hitting the right side of the tile
			/*if (entity->getPosition().x >= tilePos.x + tileSize.x - 5.f)
			{
				entity->setPosition(tilePos.x + tileSize.x, entity->getPosition().y);
				entity->stopVelocityX();
			}*/

			//// Hitting the left side of the tile
			//if (entity->getPosition().x /*+ entityBounds.size.x*/ <= tilePos.x - 10 )
			//{
			//	entity->setPosition(tilePos.x - 10/*entityBounds.size.x*/, entity->getPosition().y);
			//	entity->stopVelocityX();
			//}

			// Handle respawn if needed
		   /* if (boundary_or_respawn == 1)
			{
				entity->setPosition(10.f, 10.f);
				entity->stopVelocityX();
				entity->stopVelocityY();
			}*/
		}
	}

	//Portal logic & Hazard logic
	if (playerRef)
	{
		sf::FloatRect playerBounds = playerRef->getGlobalBounds();

		if (!justTeleported)
		{
			if (playerBounds.findIntersection(portal1.getGlobalBounds()))
			{
				playerRef->setPosition(portal2.getPosition().x - 130, portal2.getPosition().y);
				justTeleported = true;
			}
			else if (playerBounds.findIntersection(portal2.getGlobalBounds()))
			{
				playerRef->setPosition(portal1.getPosition().x - 100, portal1.getPosition().y);
				justTeleported = true;
			}
		}
		else
		{
			if (!playerBounds.findIntersection(portal1.getGlobalBounds()) && !playerBounds.findIntersection(portal2.getGlobalBounds()))
			{
				justTeleported = false;
			}
		}

		for (auto& hazard : deadZone)
		{
			if (playerBounds.findIntersection(hazard.getGlobalBounds()))
			{
				playerRef->setPosition(0.f, 0.f);
				playerRef->stopVelocityX();
				playerRef->stopVelocity();
				break;
			}
		}
	}


}


//not part of tutor
void gameWorld::generateBlock(sf::Vector2f posStr, sf::Vector2f posEnd, sf::Vector2f tileSize, sf::Texture& texture)
{
	for (float y = posStr.y; y <= posEnd.y; y += tileSize.y)
	{
		for (float x = posStr.x; x <= posEnd.x; x += tileSize.x)
		{
			gameTile tile(x, y, tileSize.x); // Assuming square tiles
			tile.getShape().setTexture(&texture); // Apply texture
			this->tiles.push_back(tile);
		}
	}
}

void gameWorld::generatePortal(sf::Vector2f pos1, sf::Vector2f pos2)
{
	portal1.setPosition(pos1);
	portal2.setPosition(pos2);
}

void gameWorld::setPlayerReference(Entity* player)
{
	playerRef = player;
}

void gameWorld::generateHazard(sf::Vector2f posStr, sf::Vector2f posEnd, sf::Vector2f tileSize)
{
	for (float y = posStr.y; y <= posEnd.y; y += tileSize.y)
	{
		for (float x = posStr.x; x <= posEnd.x; x += tileSize.x)
		{
			Hazard hazardBlock(tileSize, { x,y });
			hazardBlock.setFillColor(sf::Color::Red);
			this->deadZone.push_back(hazardBlock);
		}
	}
}