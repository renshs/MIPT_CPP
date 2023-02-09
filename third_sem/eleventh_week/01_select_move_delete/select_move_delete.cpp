#include <iostream>
#include <cmath>
#include <list>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "context_menu.hpp"

using namespace std;

float distance(sf::Vector2f start, sf::Vector2f finish)
{
    return sqrtf((start.x - finish.x) * (start.x - finish.x) + (start.y - finish.y) * (start.y - finish.y));
}

void drawLine(sf::RenderWindow &window, sf::Vector2f start, sf::Vector2f finish, sf::Color color = sf::Color::White)
{
    sf::Vertex line_vertices[2] = {sf::Vertex(start, color), sf::Vertex(finish, color)};
    window.draw(line_vertices, 2, sf::Lines);
}

struct Ball
{
    sf::Vector2f position;
    float radius;
    bool isChoosen;
    sf::Color color;

    Ball(sf::Vector2f position, float radius, sf::Color color = sf::Color::White) : position(position), radius(radius), color(color)
    {
        isChoosen = false;
    }

    void draw(sf::RenderWindow &window) const
    {
        sf::CircleShape circle(radius);
        circle.setFillColor(color);
        circle.setOrigin({radius, radius});
        circle.setPosition(position);
        window.draw(circle);

        if (isChoosen)
        {
            const float fraction = 0.7;
            drawLine(window, {position.x - radius, position.y + radius}, {position.x - radius, position.y + radius * fraction});
            drawLine(window, {position.x - radius, position.y + radius}, {position.x - fraction * radius, position.y + radius});

            drawLine(window, {position.x + radius, position.y + radius}, {position.x + radius, position.y + radius * fraction});
            drawLine(window, {position.x + radius, position.y + radius}, {position.x + radius * fraction, position.y + radius});

            drawLine(window, {position.x + radius, position.y - radius}, {position.x + radius * fraction, position.y - radius});
            drawLine(window, {position.x + radius, position.y - radius}, {position.x + radius, position.y - radius * fraction});

            drawLine(window, {position.x - radius, position.y - radius}, {position.x - radius * fraction, position.y - radius});
            drawLine(window, {position.x - radius, position.y - radius}, {position.x - radius, position.y - radius * fraction});
        }
    }
    void setColor(sf::Uint8 r, sf::Uint8 g, sf::Uint8 b, sf::Uint8 a = 255)
    {
        color.r = r;
        color.g = g;
        color.b = b;
        color.a = a;
    }
};

void deleteChoosen(list<Ball> &balls)
{
    for (list<Ball>::const_iterator it = balls.begin(); it != balls.end();)
    {
        if (it->isChoosen)
            it = balls.erase(it);
        else
            ++it;
    }
}

void copyBalls(list<Ball> &balls, list<Ball> &buffer)
{
    buffer.clear();
    for (list<Ball>::iterator it = balls.begin(); it != balls.end(); ++it)
        if (it->isChoosen)
            buffer.push_back(*it);
}

void pasteBalls(list<Ball> &balls, list<Ball> &buffer)
{
    for (list<Ball>::iterator it = buffer.begin(); it != buffer.end(); ++it)
        balls.push_back(*it);
}

void recolorChoosen(list<Ball> &balls)
{
    for (Ball &b : balls)
        if (b.isChoosen)
            b.setColor(rand() % 255, rand() % 255, rand() % 255);
}

void resizeChoosen(list<Ball> &balls, double scaling)
{
    for (list<Ball>::iterator it = balls.begin(); it != balls.end(); ++it)
    {
        if (it->isChoosen)
            it->radius += it->radius * scaling;
    }
}

int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(800, 600), "Select, Move, Delete!", sf::Style::Default, settings);
    window.setFramerateLimit(60);

    std::list<Ball> balls;
    balls.push_back(Ball({200, 200}, 26));
    balls.push_back(Ball({400, 300}, 20));
    balls.push_back(Ball({500, 100}, 16));
    balls.push_back(Ball({200, 400}, 18));
    balls.push_back(Ball({350, 150}, 22));
    balls.push_back(Ball({750, 400}, 21));

    list<Ball> buffer{};

    sf::RectangleShape selectionRect;
    selectionRect.setFillColor(sf::Color(150, 150, 240, 50));
    selectionRect.setOutlineColor(sf::Color(200, 200, 255));
    selectionRect.setOutlineThickness(1);

    bool isSelecting = false;
    /* "Режим выделения" */
    bool isMovingMode = false;
    /* Необходимо, чтоб в режиме выделения считать смещение */
    Ball *selected_ball = nullptr;

    bool isContextMenu = false;

    sf::Vector2f mousePosition{};

    sf::Font font;
    if (!font.loadFromFile("consolas.ttf"))
    {
        std::cout << "Can't load button font" << std::endl;
    }

    std::vector<sf::String> contextMenuStrings{"Delete", "Create", "Random Color", "Increase", "Decrease", "Copy", "Cut", "Paste"};
    ContextMenu contextMenu(window, font);
    for (const auto &el : contextMenuStrings)
    {
        contextMenu.addButton(el);
    }

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            int result = contextMenu.handleEvent(event);
            switch (result)
            {
            case 0:
                deleteChoosen(balls);
                break;
            case 1:
                mousePosition = window.mapPixelToCoords({event.mouseButton.x, event.mouseButton.y});
                balls.push_back(Ball(mousePosition, 5 + rand() % 40));
                break;
            case 2:
                recolorChoosen(balls);
                break;
            case 3:
                resizeChoosen(balls, 0.25);
                break;
            case 4:
                resizeChoosen(balls, -0.25);
                break;
            case 5:
                copyBalls(balls, buffer);
                break;
            case 6:
                copyBalls(balls, buffer);
                deleteChoosen(balls);
                break;
            case 7:
                pasteBalls(balls, buffer);
                break;
            }
            if (event.type == sf::Event::MouseMoved)
            {
                mousePosition = window.mapPixelToCoords({event.mouseMove.x, event.mouseMove.y});

                // Если мы находимся в режиме выделения и не попали в уже выделенный шарик, то меняем прямоугольник выделения
                if (isSelecting & !isMovingMode)
                {
                    selectionRect.setSize(mousePosition - selectionRect.getPosition());
                }
                // Если в режиме перемещения, то двигаем все выделенные шарики
                if (isMovingMode)
                {
                    sf::Vector2f direction = selected_ball->position - mousePosition;
                    for (Ball &b : balls)
                    {
                        if (b.isChoosen)
                        {
                            b.position -= direction;
                        }
                    }
                }
            }

            if (event.type == sf::Event::MouseButtonPressed)
            {
                mousePosition = window.mapPixelToCoords({event.mouseButton.x, event.mouseButton.y});
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    for (Ball &b : balls)
                    {
                        /* Если попали в какой-то шарик */
                        if (distance(mousePosition, b.position) < b.radius)
                        {
                            selected_ball = &b;
                            // Если попали в еще не выбранный шарик и не зажат левый Ctrl, то снимаем выделение со всех остальных
                            if (!b.isChoosen && !sf::Keyboard::isKeyPressed(sf::Keyboard::LControl))
                            {
                                for (Ball &ball : balls)
                                {
                                    ball.isChoosen = false;
                                }
                            }
                            b.isChoosen = true; //
                            isMovingMode = true;
                            break;
                        }
                    }
                    // ЛКМ + левый Alt - добавляем новый случайный шарик
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt))
                    {
                        balls.push_back(Ball(mousePosition, 5 + rand() % 40));
                    }
                    // Задаём новое положения прямоугольника выделения
                    if (!isMovingMode)
                    {
                        isSelecting = true;
                        selectionRect.setPosition(mousePosition);
                        selectionRect.setSize({0, 0});
                    }
                }
                if (event.mouseButton.button == sf::Mouse::Right)
                {
                    isContextMenu = true;
                }
            }
            // При отпускании кнопки мыши выходим из режима выделения
            if (event.type == sf::Event::MouseButtonReleased)
            {
                // Если не зажат левый Ctrl и не в режиме перемещения шариков, то все выделения снимаются
                if (!sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) && !isMovingMode && !isContextMenu)
                {
                    for (Ball &b : balls)
                    {
                        b.isChoosen = false;
                    }
                }
                if (isSelecting)
                {
                    sf::Vector2f size = selectionRect.getSize();
                    sf::Vector2f position = selectionRect.getPosition();
                    for (Ball &b : balls)
                    {
                        if (((b.position.x - b.radius > position.x) && (b.position.x + b.radius < position.x + size.x)) ||
                            ((b.position.x + b.radius < position.x) && (b.position.x - b.radius > position.x + size.x)))
                            if (((b.position.y - b.radius > position.y) && (b.position.y + b.radius < position.y + size.y)) ||
                                ((b.position.y + b.radius < position.y) && (b.position.y - b.radius > position.y + size.y)))
                                b.isChoosen = true;
                    }
                }
                isSelecting = false;
                isMovingMode = false;
                isContextMenu = false;
            }

            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::C)
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl))
                        copyBalls(balls, buffer);
                if (event.key.code == sf::Keyboard::V)
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl))
                        pasteBalls(balls, buffer);
                if (event.key.code == sf::Keyboard::X)
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl))
                    {
                        copyBalls(balls, buffer);
                        deleteChoosen(balls);
                    }
                if (event.key.code == sf::Keyboard::Space)
                    recolorChoosen(balls);
                if (event.key.code == sf::Keyboard::Delete)
                {
                    deleteChoosen(balls);
                }
            }
        }

        window.clear(sf::Color::Black);
        // Рисуем все шарики
        for (Ball &b : balls)
        {
            b.draw(window);
        }
        // Рисуем прямоугольник выделения
        if (isSelecting)
        {
            window.draw(selectionRect);
        }
        contextMenu.draw();
        window.display();
    }

    return 0;
}
