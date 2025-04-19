#pragma once
#include "AnimationComponent.hpp"

AnimationComponent::AnimationComponent(sf::Sprite& sprite, sf::Texture& textureSheet)
	: mSprite(sprite), mTextureSheet(textureSheet)
{

}

AnimationComponent::~AnimationComponent()
{
	for (auto &i : mAnimations)
	{
		delete i.second;
	}
}

void AnimationComponent::play(const std::string key, const float& deltaTime)
{
	mAnimations[key]->play(deltaTime);
}

void AnimationComponent::addAnimation(const std::string key, int startFrameX, int startFrameY, int frames_x, int frames_y, 
	int width, int height, float animationTimer)
{
	mAnimations[key] = new Animation(this->mSprite, this->mTextureSheet, startFrameX, startFrameY, frames_x,
		frames_y, width, height, animationTimer);
}
