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

#ifndef ANIMATION
#define ANIMATION

#include <map>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

class Animation {
public:
	Animation(sf::Sprite& sprite, sf::Texture& textureSheet, int startFrameX, int startFrameY,
		int frames_x, int frames_y, int width, int height, float animationTimer);
	virtual ~Animation();

	const bool& getDone() const;

	//member functions
	void reset();
	const bool& play(const float& deltaTime);

private:
	//map string to a certain animation
	std::map<std::string, Animation> mAnimations;

	//texture sheet for animation
	sf::Texture& mTextureSheet;

	//timers for animation
	float mAnimationTimer;
	float mTimer;

	//rectangles for cutting out sprites from sheet
	sf::IntRect mStartRect;
	sf::IntRect mCurrentRect;
	sf::IntRect mEndRect;

	//sprite parameters
	int mWidth;
	int mHeight;
	sf::Sprite& mSprite;

	bool mDone;
};

#endif