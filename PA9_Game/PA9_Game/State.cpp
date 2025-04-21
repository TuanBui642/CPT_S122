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

#pragma once
#include "State.hpp"

State::State(sf::RenderWindow* window)
{
    mStateWindow = window;
    mQuit = false;
    //mSupportedKeys = supportedKeys;
}

const bool& State::getQuit() const
{
    return mQuit;
}

void State::endState()
{
    mQuit = true;
}