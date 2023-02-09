#include <iostream>
#include <cmath>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

float distance(sf::Vector2f start, sf::Vector2f finish)
{
    return std::sqrt((start.x - finish.x)*(start.x - finish.x) + (start.y - finish.y)*(start.y - finish.y));
}


int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Draggable");
    window.setFramerateLimit(60);

    sf::Font consolas_font;
    if (!consolas_font.loadFromFile("consolas.ttf"))
    {
        std::cout << "Can't load button font consolas.txt" << std::endl;
    }
    sf::Text title;
    title.setFont(consolas_font);
    title.setString("Draggable rectangle");
    title.setCharacterSize(28);

    sf::RectangleShape rect({200, 150});
    rect.setPosition({300, 300});
    rect.setFillColor(sf::Color(95, 164, 143));
    bool isPressed;

  

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            sf::Vector2f mousePosition = window.mapPixelToCoords({event.mouseMove.x, event.mouseMove.y});
            //std::cout << "x: " << mousePosition.x << ' ' << "y " << mousePosition.y << std::endl;

            if (event.type == sf::Event::MouseMoved)
            {
                
                // Вам нужно дописать поведение прямоугольника ниже
                if (isPressed) {
                   rect.setPosition(mousePosition);
                   std::cout << mousePosition.x << std::endl;
                }


            }

            if (event.type == sf::Event::MouseButtonPressed)
            {
                std::cout << "right pressed" << std::endl;
                sf::Vector2f clickPos = ({(float)event.mouseButton.x, (float)event.mouseButton.y});
                // Вам нужно дописать поведение прямоугольника ниже
                if (event.mouseButton.button == sf::Mouse::Right) {
                    if (rect.getGlobalBounds().contains(clickPos)) {
                        std::cout << "yes" << std::endl;
                        isPressed = 1;
                    }
                }


            }

            if (event.type == sf::Event::MouseButtonReleased)
            {
                // Вам нужно дописать поведение прямоугольника ниже
                if (event.mouseButton.button == sf::Mouse::Right) {
                    isPressed = 0;
                }


            }
        }
        
        window.clear(sf::Color::Black);
        window.draw(rect);
        window.draw(title);
        window.display();
    }

    return 0;
}
