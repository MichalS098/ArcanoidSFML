#include <SFML/Graphics.hpp>
#include "../inc/ball.hh"
#include "../inc/paddle.hh"


int main(){
    sf::RenderWindow window(sf::VideoMode(1000, 700), "First Game!", sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(60); 
    sf::Event event;

    //        x     y     radius    velocity
    Ball ball(10.0, 10.0, 10.0, sf::Vector2f{6.0, 6.0}, sf::Color::White);

    //                size                  velocity              position
    Paddle paddle(sf::Vector2f{35, 10}, sf::Vector2f{0, 0.f}, sf::Vector2f{500, 550});

    while (window.isOpen())
    {
        window.clear();
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) window.close();            
        }
        ball.update(sf::Vector2f{1000,700});
        paddle.update(sf::Vector2f{1000,700});
        window.draw(ball);
        window.draw(paddle);
        window.display();
    }
    return 0;
}