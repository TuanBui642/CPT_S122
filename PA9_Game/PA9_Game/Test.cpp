/*
*	Program: PA9 (Group Game Project)
*	Date: 4/12/25
*	Group:
*		Tuan Bui
*		Ashton Palma
*		Tyler Simmons
*		Brandon Weirth
*
*/

#include "Test.hpp"

//Test Functions Below:

void TestEnemyMovement() {

    
    sf::RenderWindow window(sf::VideoMode({ 200, 200 }), "Test Enemy Movement");
    
 
        while (window.isOpen())
        {
            while (const std::optional event = window.pollEvent())
            {
                if (event->is<sf::Event::Closed>())
                    window.close();

                
            }

         
            window.display();
        }
    
}