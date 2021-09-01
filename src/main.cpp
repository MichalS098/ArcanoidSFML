#include <SFML/Graphics.hpp>
#include "../inc/ball.hh"



int main(){
    sf::RenderWindow window(sf::VideoMode(1000, 700), "First Game!");
    window.setFramerateLimit(60); // call it once, after creating the window
    sf::Event event;
    
    Ball ball(10.0, 10.0, 10.0, sf::Vector2f{6.0, 6.0}, sf::Color::White);

    while (window.isOpen())
    {
        window.clear();
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) window.close();            
        }
        ball.update(sf::Vector2f{1000,700});
        window.draw(ball);
        window.display();
    }
    return 0;
}