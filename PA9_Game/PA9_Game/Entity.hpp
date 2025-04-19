#pragma once

#include "MovementComponent.hpp"
#include "AnimationComponent.hpp"

class Entity {

	public:
		//core constructor
		Entity(sf::Sprite sprite, sf::Texture textureSheet);
		//destructor
		virtual ~Entity();

		//setters
		virtual void setPosition(const float x_pos, const float y_pos);
		//member functions
		void setTexture(sf::Texture& texture);
		void createMovementComponent(const float maxVelocity,
			const float acceleration, const float deceleration);
		void createAnimationComponent(sf::Texture& textureSheet);

		virtual void move(const float deltaTime, const float dir_x, const float dir_y);
		virtual void update(const float& deltaTime);
		virtual void render(sf::RenderTarget* target);

	protected:
		sf::Sprite mSprite;
		
		MovementComponent* mpMovementComponent;
		AnimationComponent* mpAnimationComponent;

	private:
		void initVariables();
};