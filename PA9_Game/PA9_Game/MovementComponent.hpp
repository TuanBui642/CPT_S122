#pragma once

#include <vector>
#include <stack>
#include <map>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

enum movementStates {
	IDLE = 0,
	MOVING,
	WALK_RIGHT,
	WALK_LEFT,
	RUN_RIGHT,
	RUN_LEFT,
	JUMP_RIGHT,
	JUMP_LEFT,
	ATTACK_RIGHT,
	ATTACK_LEFT
};

class MovementComponent {
	public:
		MovementComponent(sf::Sprite& sprite, float acceleration, float deceleration);
		virtual ~MovementComponent();

		//getters
		const sf::Vector2f getVelocity() const;
		bool getJumpUsed() const;

		//member functions
		bool getState(const short unsigned state);
		void move(const float dir_x, const float dir_y, const float deltaTime);
		void update(const float& deltaTime);

	private:
		float mMaxVelocity;
		sf::Sprite& mSprite;
		sf::Vector2f mVelocity;
		float mAcceleration;
		float mDeceleration;
		float mGravity;
		float mOnGround;
		bool mFaceLeft,
			mFaceRight;
};