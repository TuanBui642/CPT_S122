#pragma once

#include <vector>
#include <stack>
#include <map>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

class HitboxComponent {
public:
    HitboxComponent(sf::Sprite& sprite, float offsetX, float offsetY, float width,
        float height);
    virtual ~HitboxComponent();

    //member functions
    void update();
    void render(sf::RenderTarget& target);
    bool checkIntersect(const sf::FloatRect& rect);

    ///Ashton work///
    sf::RectangleShape getmHitBox();
    const sf::Vector2f& getPosition() const;
    const sf::FloatRect getGlobalBounds() const;
    const sf::FloatRect& getNextPosition(const sf::Vector2f& velocity);
    /////////////


private:
    sf::RectangleShape mHitbox;
    sf::Sprite& mSprite;
    float mOffsetX,
        mOffsetY;

    //Ashton work
    sf::FloatRect nextPosition;
    ////////////
};