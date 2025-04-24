/*
*	Program: PA9 (Group Game Project)
*	Date: 4/12/25
*	Group:
*		Tuan Bui
*		Ashton Palma
*		Tyler Simmons
*		Brandon Weirth
*
*	File Programmer: Tyler Simmons
*/

#pragma once
#include "AnimationComponent.hpp"

AnimationComponent::AnimationComponent(sf::Sprite& sprite, sf::Texture& textureSheet)
	: mSprite(sprite), mTextureSheet(textureSheet), mpLastAnimation(nullptr), mpPriorityAnimation(nullptr)
{

}

AnimationComponent::~AnimationComponent()
{
	for (auto& i : mAnimations) {
		delete i.second;
	}
}

//return if animation is done
const bool& AnimationComponent::getDone(const std::string key)
{
	return mAnimations[key]->getDone();
}

//play animation and play priority animations before switching to new animations
const bool& AnimationComponent::play(const std::string key, const float& deltaTime, const bool priority)
{
    //set priority animation
    if (priority) {
        mpPriorityAnimation = mAnimations[key];
    }

    //play priority animation
    if (mpPriorityAnimation != nullptr) {
        if (mpPriorityAnimation == mAnimations[key]) {
            if (mpLastAnimation != mAnimations[key]) {
                if (mpLastAnimation == nullptr) {
                    mpLastAnimation = mAnimations[key];
                }
                else {
                    mpLastAnimation->reset();
                    mpLastAnimation = mAnimations[key];
                }
            }

            //if animation is done remove it
            if (mAnimations[key]->play(deltaTime)) {
                mpPriorityAnimation = nullptr;
            }
        }

    }
    //play non-prioity animations
    else {
        //reset previous animation
        if (mpLastAnimation != mAnimations[key]) {
            if (mpLastAnimation == nullptr) {
                mpLastAnimation = mAnimations[key];
            }
            else {
                mpLastAnimation->reset();
                mpLastAnimation = mAnimations[key];
            }
        }

        //play animation
        mAnimations[key]->play(deltaTime);
    }

    return mAnimations[key]->getDone();
}

void AnimationComponent::addAnimation(const std::string key, int startFrameX, int startFrameY, int frames_x, int frames_y,
	int width, int height, float animationTimer)
{
	mAnimations[key] = new Animation(this->mSprite, this->mTextureSheet, startFrameX, startFrameY, frames_x,
		frames_y, width, height, animationTimer);
}