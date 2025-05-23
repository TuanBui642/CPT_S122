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
	Player(sf::Texture CharTexture);

	//getters and setters
	bool getJumpUsed() const;
	//member functions
	virtual void update(const float& deltaTime);

	//Ashton work
	HitboxComponent* getHitboxComponent() const;
	sf::Vector2f& getVelocity();
	const sf::Vector2f& getPosition() const override;
	//void setJumpUsed(bool TorF); 

	//Tuan Work For Test Cases
	float GetCurXPos();
	float GetCurYPos();

	void SetCurXPos(float NewFloat);
	void SetCurYPos(float NewFloat);

	void MoveByPos(float const x, float const y);


private:
	bool mJumpUsed;
	bool mIsFalling;
	bool mIsAttacking;

	float CurXPos;
	float CurYPos;

	//member functions
	void initVariables();
	void initComponents();
};

#endif