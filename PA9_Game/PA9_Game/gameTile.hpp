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

#pragma once
#include "Entity.hpp"
#include "gameWorld.hpp"
#include <string>

class gameTile : public Entity {
private:
	sf::RectangleShape object;
	std::string objectType;

public:
	//constructor
	gameTile(std::string ObjectName, const sf::Vector2f& size, const sf::Vector2f& pos, sf::Sprite& sprite, sf::Texture& texture) : Entity(sprite, texture), objectType(ObjectName)
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
		object.setPosition({x, y});
	}

	//getters
	//globalbound
	sf::FloatRect getGlobalBound() const
	{
		return object.getGlobalBounds();
	}

	void render(sf::RenderTarget* target) override
	{
		target->draw(object);
	}

	bool collisionStatus(sf::RectangleShape& person, float& velocityY, bool& isJumping, int boundary_or_respawn); 

};
