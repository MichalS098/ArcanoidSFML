#include "../inc/paddle.hh"


Paddle::Paddle(sf::Vector2f size={10.f, 10.f}, float velocity=6.f, sf::Vector2f position={500, 550})
: _shape{size}, _size{size}, _velocity{velocity, 0.f}, _position{position}
{
    _shape.setPosition(position);
    _shape.setFillColor(_color);

    //setting metal texture to the paddle
    sf::Texture* paddleTexture = new sf::Texture;
    paddleTexture->loadFromFile("img/metalTexture.jpg");
    paddleTexture->setRepeated(true);
    _shape.setTexture(paddleTexture);
}


void Paddle::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    target.draw(this->_shape, states);
}


void Paddle::update(sf::Vector2f boxDimensions){
    manageCollisionWithTheBox(boxDimensions);
    _shape.move(this->_velocity);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)){
        _velocity.x = -_paddleVelocity;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)){
        _velocity.x = _paddleVelocity;
    }
    else{
        _velocity={0.f, 0.f};
    }
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
 */
void Paddle::manageCollisionWithTheBox(sf::Vector2f boxDimensions){
    if(this->leftSidePosition().x <= 0.f){
        _velocity.x = _paddleVelocity;
    }
    else if(this->rightSidePosition().x >= boxDimensions.x){
        _velocity.x = -_paddleVelocity;
    }
}