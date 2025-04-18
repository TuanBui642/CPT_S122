#pragma once

#include <map>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

class Animation {
public:
    Animation(sf::Texture& textureSheet, int start_x, int start_y,
        int end_x, int end_y, int width, int height, float speed);
    virtual ~Animation();

    //member functions
    void play();
    void pause();
    void reset();
    void update(const float& deltaTime);

private:
    std::map<std::string, Animation> mAnimations;
    sf::Texture& mTextureSheet;
    float mSpeed;
    sf::IntRect mStartRect;
    sf::IntRect mEndRect;
    int mWidth;
    int mHeight;
};