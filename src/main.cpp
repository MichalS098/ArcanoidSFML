#include <iostream>
#include <SFML/Graphics.hpp>
#include "../inc/ball.hh"
#include "../inc/paddle.hh"
#include "../inc/menu.hh"

constexpr int END_OF_GAME=1024;

template<typename T1, typename T2>
bool isIntersecting(const T1& a, const T2& b){
    return a.rightSidePosition().x >= b.leftSidePosition().x && a.leftSidePosition().x <= b.rightSidePosition().x
        && a.bottomSidePosition().y >= b.topSidePosition().y && a.topSidePosition().y <= b.bottomSidePosition().y;
}

int main(){
    sf::RenderWindow window(sf::VideoMode(1000, 700), "First Game!", sf::Style::Titlebar | sf::Style::Close);
    window.setPosition(sf::Vector2i{200, 200});
    window.setFramerateLimit(60); 
    
    sf::Sprite sprite;
    makeBackground(sprite, window.getPosition());
    
    Ball ball(10.0, 10.0, 13.0, sf::Vector2f{6.0, 6.0}, sf::Color(22, 215, 129));
    Paddle paddle(sf::Vector2f{55, 20}, 6, sf::Vector2f{500, 550});

    sf::Event event;
    showMainMenu(window, event);

    while (window.isOpen())
    {
        window.clear();
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) window.close();            
        }
        if(ball.update(sf::Vector2f{1000,700}) == END_OF_GAME)     //If ball hit the bottom of the screen
        {                                                          //function "update" returns END_OF_GAME int value
            endOfGame(window, event);                               
        }
        paddle.update(sf::Vector2f{1000,700});
        window.draw(sprite);
        window.draw(ball);
        window.draw(paddle);
        if(isIntersecting(paddle, ball)){
            sf::Vector2f newVelocity = ball.getVelocity();
            newVelocity.y = -newVelocity.y;
            ball.setVelocity(newVelocity);
        }
        window.display();
    }
    return 0;
}