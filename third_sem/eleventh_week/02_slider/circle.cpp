#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "slider.hpp"

int main()
{
    int result;
    unsigned char r, g, b;

    sf::RenderWindow window(sf::VideoMode(800, 600), "Slider");
    window.setFramerateLimit(60);

    sf::Font font;
    if (!font.loadFromFile("consolas.ttf")) {
        std::cout << "Can't load button font" << std::endl;
    }

    Slider slider(window, font, sf::Vector2f{200, 100}, 10, 250);
    
    Slider slider_r(window, font, sf::Vector2f{800, 200}, 0, 255);
    Slider slider_g(window, font, sf::Vector2f{800, 300}, 0, 255);
    Slider slider_b(window, font, sf::Vector2f{800, 400}, 0, 255);
    
    sf::CircleShape circle(10);
    circle.setPosition(sf::Vector2f{400, 400});

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            result = slider.handleEvent(event);

            /* Centering of the circle */
            circle.setPosition(circle.getPosition() + sf::Vector2f{circle.getRadius() - result, circle.getRadius() - result});
            circle.setRadius(result);

            r = slider_r.handleEvent(event);
            g = slider_g.handleEvent(event);
            b = slider_b.handleEvent(event);
            circle.setFillColor(sf::Color{r, g, b});
        }
        window.clear(sf::Color::Black);

        slider.draw();
        slider_r.draw();
        slider_g.draw();
        slider_b.draw();

        window.draw(circle);
        window.display();
    }
    return 0;
}
