#pragma once

#include <SFML/Graphics.hpp>

/**
 * @brief Paddle floating on the screen, it's job is to knock the floating ball.
 * 
 */
class Paddle: public sf::Drawable {
    const float _paddleVelocity=6.f;
    sf::RectangleShape _shape;
    sf::Vector2f _size;
    sf::Vector2f _velocity;
    sf::Vector2f _position;
    sf::Color _color = sf::Color::Blue;
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

public:
    sf::Vector2f leftSidePosition() const;
    sf::Vector2f rightSidePosition() const;
    sf::Vector2f bottomSidePosition() const;
    sf::Vector2f topSidePosition() const;
    void manageCollisionWithTheBox(sf::Vector2f boxDimensions);

    Paddle() = delete;
    Paddle(sf::Vector2f size, float velocity, sf::Vector2f position);
    ~Paddle() = default;
    void update(sf::Vector2f boxDimensions);
    void setColor(sf::Color color){ _color=color; _shape.setFillColor(color);}
};