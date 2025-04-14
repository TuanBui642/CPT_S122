/*
*	Program: PA9 (Group Game Project)
*	Date: 4/12/25
*	Group:
*		Tuan Bui
*		Ashton Palma
*		Tyler Simmons
*		Brandon Weirth
*/

#include "Portal.hpp"
#include "Platform.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>

int main(void) {

    unsigned int width = 640;
    unsigned int height = 360;
    sf::RenderWindow window(sf::VideoMode({ width, height }), "Game!");
 
    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent()) 
        {
            if (event->is<sf::Event::Closed>()) { //Close window by red X button (Top right of Window)

                window.close();
            }
            else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) { //Close window by KeyPress ESCAPE (ESC)

                if (keyPressed->scancode == sf::Keyboard::Scancode::Escape) {

                    window.close();
                }
            }
                

            window.display();
        }
    }

	return 0;
}