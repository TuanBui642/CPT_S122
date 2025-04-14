/*
*	Program: PA9 (Group Game Project)
*	Date: 4/12/25
*	Group:
*		Tuan Bui
*		Ashton Palma
*		Tyler Simmons
*		Brandon Weirth
*/

#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include <fstream>
#include <vector>
#include <stack>

using std::cout;
using std::endl;
using std::string;
using std::cin;
using std::ostream;
using std::ifstream;
using std::ofstream;
using std::vector;
using std::stack;

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