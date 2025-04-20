#include "HitboxComponent.hpp"

HitboxComponent::HitboxComponent(sf::Sprite& sprite, float offsetX, float offsetY, float width,
	float height) : mSprite(sprite), mOffsetX(offsetX), mOffsetY(offsetY)
{
	mHitbox.setPosition(mSprite.getPosition() + sf::Vector2f(mOffsetX, mOffsetY));	//set the hitbox on top of the sprite then apply offset
	mHitbox.setSize(sf::Vector2f(width, height));
	mHitbox.setFillColor(sf::Color::Transparent);
	mHitbox.setOutlineThickness(1.0f);
	mHitbox.setOutlineColor(sf::Color::Green);
}

HitboxComponent::~HitboxComponent()
{
}

void HitboxComponent::update()
{
	mHitbox.setPosition(mSprite.getPosition() + sf::Vector2f(mOffsetX, mOffsetY));
}

void HitboxComponent::render(sf::RenderTarget& target)
{
	target.draw(mHitbox);	//draw the hitbox
}

bool HitboxComponent::checkIntersect(const sf::FloatRect& rect)
{
	if (mHitbox.getGlobalBounds().findIntersection(rect)) {
		return true;
	}
	else {
		return false;
	}
}
