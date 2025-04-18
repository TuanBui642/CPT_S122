#pragma once
#include "Entity.hpp"

class Player : public Entity {
	public:
		Player(float x_pos, float y_pos, sf::Texture& texture);
		virtual ~Player();

	private:
		void initVariables();
		void initComponents();
};