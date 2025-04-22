#include "gameTile.hpp"
//
//bool gameTile::collisionStatus(Player& player, int boundary_or_respawn)
//{
//    
//        sf::FloatRect playerBounds = player.getHitboxComponent()->getmHitBox().getGlobalBounds();
//        sf::FloatRect tileBounds = object.getGlobalBounds();
//		sf::Vector2f playerSize = player.getHitboxComponent()->getmHitBox().getSize();
//
//		if (object.getGlobalBounds().findIntersection(playerBounds))
//		{
//			if (boundary_or_respawn == 0) // Block the player
//			{
//
//				if (player.getPosition().y <= object.getPosition().y) 
//				{
//					if (player.getPosition().y <= object.getPosition().y)
//					{
//						player.setPosition(player.getPosition().x, (object.getPosition().y - 22) - playerSize.y);
//						player.getVelocity().y = 0;
//						//player.setJumpUsed(false);
//						return true;
//					}
//
//				}
//				if (player.getPosition().x >= object.getPosition().x || player.getPosition().x <= object.getPosition().x)
//				{
//					if (player.getPosition().y >= object.getPosition().y + this->object.getSize().y) //+ player.getVelocity().y)
//					{
//						player.setPosition(player.getPosition().x, object.getPosition().y + 22);// + this->object.getSize().y);
//						return true;
//					}
//
//					if (player.getPosition().x >= object.getPosition().x)
//					{
//						player.setPosition(object.getPosition().x + 50, player.getPosition().y);
//						return true;
//					}
//					if (player.getPosition().x <= this->object.getPosition().x + this->object.getSize().x)
//					{
//						player.setPosition(this->object.getPosition().x - 30, player.getPosition().y);
//						return true;
//					}
//				}
//
//			}
//			if (boundary_or_respawn == 1)
//			{
//				if (player.getPosition().y <= this->object.getPosition().y)
//				{
//					player.setPosition(10, 10);
//					player.getVelocity().y = 0;
//					//player.setJumpUsed(false);
//					return true;
//				}
//				if (player.getPosition().y >= this->object.getPosition().y + this->object.getSize().y + player.getVelocity().y)
//				{
//					player.setPosition(10, 10);
//					return true;
//				}
//				if (player.getPosition().x >= this->object.getPosition().x)
//				{
//					player.setPosition(10, 10);
//					return true;
//				}
//				if (player.getPosition().x <= this->object.getPosition().x + this->object.getSize().x)
//				{
//					player.setPosition(10, 10);
//					return true;
//				}
//			}
//
//			
//		}
//		return false;
//};

gameTile::gameTile()
{
}

gameTile::gameTile(float x, float y, float gridSizeF)
{
	this->shape.setSize(sf::Vector2f(gridSizeF, gridSizeF));
	this->shape.setFillColor(sf::Color::White);
	this->shape.setPosition({ x, y });
}


void gameTile::update()
{

}

void gameTile::render(sf::RenderTarget& target)
{
	target.draw(this->shape);
}


//not part of tutor
sf::RectangleShape& gameTile::getShape()
{
	return this->shape;
}
