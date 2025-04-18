#pragma once
#include <iostream>
using std::cout;
using std::endl;
#include "State.hpp"	//this is a derived class of State

class GameState : public State {
	public:
		GameState(sf::RenderWindow* window);
		virtual ~GameState();

		//member functions
		void updateInput(const float& deltaTime);
		void update(const float& deltaTime);
		void render(sf::RenderTarget* target = nullptr);

	private:
		Player* mPlayer;
		Enemy* mEnemy;

		//member functions
		void initKeyBindings();
		void initTextures();
		void initPlayers();
		void initEnemies();
};