#pragma once
#include "AnimationComponent.hpp"

AnimationComponent::AnimationComponent(sf::Sprite& sprite, sf::Texture& textureSheet) : mSprite(sprite), mTextureSheet(textureSheet)
{

}

AnimationComponent::~AnimationComponent()
{
}

void AnimationComponent::play(const std::string key, const float& dt)
{

}

void AnimationComponent::addAnimation(const std::string key)
{

}