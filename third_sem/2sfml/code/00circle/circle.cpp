#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <vector>

// Программа, которая рисует круг

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 600), "Draw Circle");
    
    sf::CircleShape circle(100);
    circle.setOrigin(100, 100);
    circle.setFillColor(sf::Color{123, 55, 211});
    circle.setPosition(sf::Vector2f{900, 500});
    for (auto i = 0; i < 1000; i++) {
        sf::CircleShape 
    }
    window.clear(sf::Color::Black);
    window.draw(circle);

    window.display();

    sf::sleep(sf::seconds(100));
    return 0;
}
