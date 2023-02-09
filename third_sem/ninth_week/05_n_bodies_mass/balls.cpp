#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

const int min_distance = 5;
const float G = 500;

struct Ball
{
    float radius;
    float mass;
    sf::Vector2f position;
    sf::Vector2f velocity;
};


int main()
{
    srand(time(0));
    
    const int width = 1000;
    const int height = 800;
    const int n_balls = 15;

    // Шаг по времени
    const float delta_t = 0.1;
    sf::RenderWindow window(sf::VideoMode(width, height), "My window");
    window.setFramerateLimit(60);
    sf::CircleShape circle(50.0f);
    circle.setFillColor({200, 216, 200});
    std::vector<Ball> balls;
    balls.resize(n_balls);
    for (int i = 0; i < n_balls; i++)
    {
        balls[i].radius = 4 + rand() % 8;
        balls[i].mass = balls[i].radius * balls[i].radius / 100;
        balls[i].position = {(float)(rand() % width), (float)(rand() % height)};
        balls[i].velocity = {(float)(rand() % 100 - 50), (float)(rand() % 100 - 50)};
    }
/*    balls[0].radius = 15;
    balls[0].mass = 1000;
    balls[0].position = {(float)(rand() % width), (float)(rand() % height)};
    balls[0].velocity = {(float)(rand() % 100 - 50), (float)(rand() % 100 - 50)};
    */
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
                balls[i].velocity += (direction * G * delta_t * balls[j].mass) / (distance * distance);
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
            
            window.draw(circle);
        }

        window.display();
    }

    return 0;
}
