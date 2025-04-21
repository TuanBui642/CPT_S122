#include "Animation.hpp"

Animation::Animation(sf::Sprite& sprite, sf::Texture& textureSheet, int startFrameX, int startFrameY,
	int frames_x, int frames_y, int width, int height, float animationTimer)
	: mSprite(sprite), mTextureSheet(textureSheet), mAnimationTimer(animationTimer), mWidth(width), mHeight(height), 
	mTimer(0.0f), mDone(false)
{
	//these rectangles will be used to cut sprites from a sprite sheet which
	//is going to be useful for animating
	mStartRect = sf::IntRect(sf::Vector2i(startFrameX * width, startFrameY * height), 
		sf::Vector2i(width, height));

	mCurrentRect = mStartRect;

	mEndRect = sf::IntRect(sf::Vector2i(frames_x * width, frames_y * height),
		sf::Vector2i(width, height));

	mSprite.setTexture(mTextureSheet, true); //true resets the rectangle
	mSprite.setTextureRect(mStartRect);		 

}

Animation::~Animation()
{
}

const bool& Animation::getDone() const
{
	return mDone;
}

void Animation::reset()
{
	mTimer = mAnimationTimer;
	mCurrentRect = mStartRect;
}

const bool& Animation::play(const float& deltaTime)
{
	//update timer
	mDone = false;
	mTimer += 100.0f * deltaTime;

	if (mTimer >= mAnimationTimer) {
		//reset timer
		mTimer = 0.0f;

		//Animate
		if (mCurrentRect != mEndRect) {
			mCurrentRect.position = mCurrentRect.position + sf::Vector2i(mWidth, 0.0f);	//move rectangle to the right one width
		}

		//reset
		else {
			mCurrentRect.position = mStartRect.position;
			mDone = true;
		}

		mSprite.setTextureRect(mCurrentRect);
	}
	return mDone;
}
