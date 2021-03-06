#pragma once

#include <SFML/Graphics.hpp>


/**
 * @brief Class defining a drawable and being able to move ball
 *        with choosable colorfill and position.
 * 
 */
class Ball: public sf::Drawable{
    sf::Vector2f       _position;
    float              _radius;
    sf::Vector2f       _velocityVec;
    sf::CircleShape    _shape;
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

public:
    sf::Vector2f leftSidePosition() const;
    sf::Vector2f rightSidePosition() const;
    sf::Vector2f bottomSidePosition() const;
    sf::Vector2f topSidePosition() const;
    int manageCollisionWithTheBox(sf::Vector2f boxDimensions);

    Ball() = delete;
    explicit Ball(float x, float y, float radius, sf::Vector2f velocity, sf::Color color);
    ~Ball() = default;

    int update(sf::Vector2f boxDimensions);
    sf::Vector2f getPosition() const {return _position;}
    sf::Vector2f getVelocity() const {return _velocityVec;}
    float getRadius() const {return _radius;}
    void setVelocity(sf::Vector2f velocity){_velocityVec = velocity;}
};