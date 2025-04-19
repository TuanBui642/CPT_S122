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

#ifndef STATE
#define STATE

#include "Player.hpp"
#include "gameWorld.hpp"

#include <map>

//abstract class
class State {
public:
    State(sf::RenderWindow* window);
    virtual ~State() {};

    //getters
    const bool& getQuit() const;

    //member functions
    virtual void endState();
    virtual void updateInput(const float& deltaTime) = 0;
    virtual void update(const float& deltaTime) = 0;
    virtual void render(sf::RenderTarget* target = nullptr) = 0;

protected:

    sf::RenderWindow* mStateWindow;
    bool mQuit;
    /*std::map<std::string, int>* mSupportedKeys;
    std::map<std::string, int> mKeyBindings;*/

    //resources
    std::map<std::string, sf::Texture> mTextures;

    //member functions
    virtual void initKeyBindings() = 0;
};

#endif