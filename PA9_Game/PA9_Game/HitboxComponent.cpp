#include "HitboxComponent.hpp"

HitboxComponent::HitboxComponent(sf::Sprite& sprite, float offsetX, float offsetY, float width,
    float height) : mSprite(sprite), mOffsetX(offsetX), mOffsetY(offsetY)
{
    mHitbox.setPosition(mSprite.getPosition() + sf::Vector2f(mOffsetX, mOffsetY));	//set the hitbox on top of the sprite then apply offset
    mHitbox.setSize(sf::Vector2f(width, height));
    mHitbox.setFillColor(sf::Color::Transparent);
    mHitbox.setOutlineThickness(1.0f);
    mHitbox.setOutlineColor(sf::Color::Green);

    //Ashton work//////
    this->nextPosition.position.x = 0.f;
    this->nextPosition.position.y = 0.f;
    this->nextPosition.size.x = width;
    this->nextPosition.size.y = height;
    //////////////////
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


///Ashton work/////////////////
sf::RectangleShape HitboxComponent::getmHitBox()
{
    return mHitbox;
}

const sf::Vector2f& HitboxComponent::getPosition() const
{
    return mHitbox.getPosition();
}
const sf::FloatRect HitboxComponent::getGlobalBounds() const
{
    return mHitbox.getGlobalBounds();
}
const sf::FloatRect& HitboxComponent::getNextPosition(const sf::Vector2f& velocity)
{
    this->nextPosition.position.x = this->mHitbox.getPosition().x + velocity.x;
    this->nextPosition.position.y = this->mHitbox.getPosition().y + velocity.y;

    return nextPosition;
}
////////////////////////////////

