#pragma once

#include "Animation.hpp"

class AnimationComponent {
	public:
		//constructor & destructor
		AnimationComponent(sf::Sprite& sprite, sf::Texture& textureSheet);
		virtual ~AnimationComponent();

		//member functions
		void play(const std::string key, const float& deltaTime);
		void addAnimation(const std::string key, int startFrameX, int startFrameY, int frames_x, 
			int frames_y, int width, int height, float animationTimer);

	private:
		std::map<std::string, Animation*> mAnimations;
		sf::Sprite& mSprite;
		sf::Texture& mTextureSheet;
};