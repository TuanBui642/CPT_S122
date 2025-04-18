#include "Animation.hpp"

Animation::Animation(sf::Texture& textureSheet, int start_x, int start_y,
    int end_x, int end_y, int width, int height, float speed)
    : mTextureSheet(textureSheet), mSpeed(speed), mWidth(width), mHeight(height)
{
    mStartRect = sf::IntRect(sf::Vector2i(start_x, start_y),
        sf::Vector2i(width, height));
    mEndRect = sf::IntRect(sf::Vector2i(end_x, end_y),
        sf::Vector2i(width, height));
}

Animation::~Animation()
{
}

void Animation::update(const float& deltaTime)
{

}