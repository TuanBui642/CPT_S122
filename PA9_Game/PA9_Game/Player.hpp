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

#ifndef PLAYER
#define PLAYER


#include "Entity.hpp"

class Player : public Entity {
public:
	Player(float x_pos, float y_pos, sf::Texture& textureSheet);
	virtual ~Player();

	//getters and setters
	bool getJumpUsed() const;
	//member functions
	virtual void update(const float& deltaTime);


private:
	bool mJumpUsed;
	bool mIsFalling;

	//member functions
	void initVariables();
	void initComponents();
};

#endif