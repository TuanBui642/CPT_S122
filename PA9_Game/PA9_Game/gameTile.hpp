#pragma once
#include "Entity.hpp"
#include "gameWorld.hpp"

class gameTile : public Entity {
private:
	sf::RectangleShape object;
	std::string objectType;

public:
	//constructor
	gameTile(std::string ObjectName, const sf::Vector2f& size, const sf::Vector2f& pos)
	{
		object.setSize(size);
		object.setPosition(pos);
		object.setFillColor(sf::Color::White);
	}

	//destructor
	~gameTile() override {};

	//setter
	void setPosition(float x, float y) override
	{
		object.setPosition(sf::Vector2f(x, y));
	}

	//getters
	//globalbound
	sf::FloatRect getGlobalBound() const
	{
		return this->object.getGlobalBounds();
	}

	void render(sf::RenderTarget* target) override
	{
		target->draw(object);
	}

	bool collisionStatus(sf::RectangleShape& person, float& velocityY, bool& isJumping, int boundary_or_respawn)
	{
		if (object.getGlobalBounds().findIntersection(person.getGlobalBounds()))
		{
			if (boundary_or_respawn == 0) //0 is for boundary. Meaning that person can't phase through objects
			{
				if (person.getPosition().y <= this->object.getPosition().y)
				{
					person.setPosition({ person.getPosition().x, this->object.getPosition().y - person.getSize().y });
					velocityY = 0;
					isJumping = false;
					return true;
				}
				if (person.getPosition().y >= this->object.getPosition().y + this->object.getSize().y + velocityY)
				{
					person.setPosition({ person.getPosition().x, this->object.getPosition().y + this->object.getSize().y });
					return true;
				}
				if (person.getPosition().x >= this->object.getPosition().x)
				{
					person.setPosition({ this->object.getPosition().x + this->object.getSize().x, person.getPosition().y });
					return true;
				}
				if (person.getPosition().x <= this->object.getPosition().x + this->object.getSize().x)
				{
					person.setPosition({ this->object.getPosition().x - person.getSize().y, person.getPosition().y });
					return true;
				}
			}
			if (boundary_or_respawn == 1) //1 is for respawn. Meaning that if a person walk through, then he respawn to coordinate (10,10). Trying to create deathzone
			{
				if (person.getPosition().y <= this->object.getPosition().y)
				{
					person.setPosition({ 10, 10 });
					velocityY = 0;
					isJumping = false;
					return true;
				}
				if (person.getPosition().y >= this->object.getPosition().y + this->object.getSize().y + velocityY)
				{
					person.setPosition({ 10, 10 });
					return true;
				}
				if (person.getPosition().x >= this->object.getPosition().x)
				{
					person.setPosition({ 10, 10 });
					return true;
				}
				if (person.getPosition().x <= this->object.getPosition().x + this->object.getSize().x)
				{
					person.setPosition({ 10, 10 });
					return true;
				}
			}
		}
		return false;
	}

};