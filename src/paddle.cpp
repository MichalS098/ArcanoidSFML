#include "../inc/paddle.hh"


Paddle::Paddle(sf::Vector2f size={10.f, 10.f}, sf::Vector2f velocity={10.f, 0.f}, sf::Vector2f position={500, 550})
: _shape{size}, _size{size}, _velocity{velocity}, _position{position}
{
    _shape.setPosition(position);
    _shape.setFillColor(_color);
}


void Paddle::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    target.draw(this->_shape, states);
}


void Paddle::update(sf::Vector2f boxDimensions){
    manageCollisionWithTheBox(boxDimensions);
    _shape.move(this->_velocity);
}


sf::Vector2f Paddle::leftSidePosition() const{
    return _shape.getPosition()+sf::Vector2f{0.f, _size.y/2};
}
sf::Vector2f Paddle::rightSidePosition() const{
    return _shape.getPosition()+sf::Vector2f{_size.x, _size.y/2};
}
sf::Vector2f Paddle::bottomSidePosition() const{
    return _shape.getPosition()+sf::Vector2f{_size.x/2, _size.y};
}
sf::Vector2f Paddle::topSidePosition() const{
    return _shape.getPosition()+sf::Vector2f{_size.x/2, 0.f};
}


/**
 * @brief Function checks if there is a collision between box and a Paddle in this box
 *        and if there is a collision it changes the Paddle velocity.
 * 
 * @param boxDimensions Dimension of the box that the Paddle is in
 * @return true 
 * @return false 
 */
void Paddle::manageCollisionWithTheBox(sf::Vector2f boxDimensions){
    if(this->leftSidePosition().x <= 0.f){
        _velocity.x = -_velocity.x;
    }
    else if(this->rightSidePosition().x >= boxDimensions.x){
        _velocity.x = -_velocity.x;
    }
    else if(this->topSidePosition().y <= 0.f){
        _velocity.y = -_velocity.y;
    }
    else if(this->bottomSidePosition().y >= boxDimensions.y){
        _velocity.y = -_velocity.y;
    }
}