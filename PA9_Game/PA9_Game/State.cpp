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

