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

#ifndef ANIMATIONCOMPONENT
#define ANIMATIONCOMPONENT

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

#endif