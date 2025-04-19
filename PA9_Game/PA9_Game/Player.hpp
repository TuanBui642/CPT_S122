#pragma once
#include "Entity.hpp"

class Player : public Entity {
	public:
		Player(float x_pos, float y_pos, sf::Texture& textureSheet);
		virtual ~Player();

		//getters and setters
		bool getJumpUsed() const;
		//member functions
		virtual void update(const float& deltaTime);
		

	private:
		bool mJumpUsed;
		bool mIsFalling;

		//member functions
		void initVariables();
		void initComponents();
};