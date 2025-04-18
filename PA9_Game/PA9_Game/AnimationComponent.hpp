#pragma once

#include "Animation.hpp"

class AnimationComponent {
public:
    AnimationComponent(sf::Sprite& sprite, sf::Texture& textureSheet);
    virtual ~AnimationComponent();

    void play(const std::string key, const float& dt);
    void addAnimation(const std::string key);

private:
    std::map<std::string, Animation> mAnimations;
    sf::Sprite& mSprite;
    sf::Texture& mTextureSheet;

};
