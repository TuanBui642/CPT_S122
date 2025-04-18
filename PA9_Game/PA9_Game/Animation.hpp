#pragma once

#include <map>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

class Animation {
	public:
		Animation(sf::Sprite& sprite, sf::Texture& textureSheet, int startFrameX, int startFrameY,
			int frames_x, int frames_y, int width, int height, float animationTimer);
		virtual ~Animation();

		//member functions
		void reset();
		void play(const float& deltaTime);

	private:
		std::map<std::string, Animation> mAnimations;
		sf::Texture& mTextureSheet;
		float mAnimationTimer;
		float mTimer;
		sf::IntRect mStartRect;
		sf::IntRect mCurrentRect;
		sf::IntRect mEndRect;
		int mWidth;
		int mHeight;
		sf::Sprite& mSprite;
};