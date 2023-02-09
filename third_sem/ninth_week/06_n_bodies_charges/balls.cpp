#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

const int min_distance = 5;
const float K = 25;

struct Ball
{
    float radius;
    float charge;
    sf::Vector2f position;
    sf::Vector2f velocity;
};


int main()
{
    srand(time(0));
    
    const int width = 1000;
    const int height = 800;
    int n_balls = 4;

    const float delta_t = 0.1;
    sf::RenderWindow window(sf::VideoMode(width, height), "My window");
    window.setFramerateLimit(60);
    sf::CircleShape circle(50.0f);

    std::vector<Ball> balls;
    balls.resize(n_balls);
    for (int i = 0; i < n_balls; i++)
    {
        balls[i].radius = 4 + rand() % 8;
        balls[i].charge = (rand() % 8 - rand() % 8) * balls[i].radius * balls[i].radius;
        while (!balls[i].charge) {
            balls[i].charge = (rand() % 8 - rand() % 8) * balls[i].radius * balls[i].radius;
        }
        balls[i].position = {(float)(rand() % width), (float)(rand() % height)};
        balls[i].velocity = {(float)(rand() % 100 - 50), (float)(rand() % 100 - 50)};
    }
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);

        for (int i = 0; i < n_balls; i++)
        {
            
            balls[i].position += balls[i].velocity * delta_t;
            for (int j = 0; j < n_balls; ++j) {
                if (i == j)
                        continue;
                float distance = std::sqrt((balls[j].position.x - balls[i].position.x) * (balls[j].position.x - balls[i].position.x) + (balls[j].position.y - balls[i].position.y) * (balls[j].position.y - balls[i].position.y)); 
                if (distance < min_distance)
                        continue;
                auto direction = balls[j].position - balls[i].position;
                if (balls[i].charge * balls[j].charge > 0)
                        balls[i].velocity -= (direction * K * delta_t * std::abs(balls[j].charge)) / (distance * distance);
                else
                        balls[i].velocity += (direction * K * delta_t * std::abs(balls[j].charge)) / (distance * distance);
                }
            
            if (((balls[i].position.x - balls[i].radius) < 0) || (balls[i].position.x + balls[i].radius> width)) {
                balls[i].velocity.x = -balls[i].velocity.x;
                balls[i].position.x = (balls[i].position.x - balls[i].radius < 0 ? balls[i].radius : width - balls[i].radius);
            }
            if ((balls[i].position.y - balls[i].radius < 0) || (balls[i].position.y + balls[i].radius > height)) {
                balls[i].velocity.y = -balls[i].velocity.y;
                balls[i].position.y = (balls[i].position.y - balls[i].radius < 0 ? balls[i].radius : height - balls[i].radius);
            }

            circle.setRadius(balls[i].radius);
            circle.setOrigin(balls[i].radius, balls[i].radius);
            circle.setPosition(balls[i].position);
            
            if (balls[i].charge > 0)
                   circle.setFillColor({static_cast<unsigned char>(balls[i].charge/1152 * 255 + 100), 0, 0}); 
            else
                   circle.setFillColor({0, 0, static_cast<unsigned char>(std::abs(balls[i].charge)/1152 * 255 + 100)}); 
            window.draw(circle);
        }

        window.display();
    }

    return 0;
}
