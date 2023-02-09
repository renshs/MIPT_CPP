#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "slider.hpp"

int main()
{
    int result;

    sf::RenderWindow window(sf::VideoMode(800, 600), "Slider");
    window.setFramerateLimit(60);

    sf::Font font;
    if (!font.loadFromFile("consolas.ttf")) {
        std::cout << "Can't load button font" << std::endl;
    }

    Slider slider(window, font);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            result = slider.handleEvent(event);
            std::cout << result << std::endl;
        }
        window.clear(sf::Color::Black);

        slider.draw();
        window.display();
    }
    return 0;
}
