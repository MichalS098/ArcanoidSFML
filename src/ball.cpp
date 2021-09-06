#include "../inc/ball.hh"
#include <exception>

constexpr int END_OF_GAME=1024;

/**
 * @brief Construct a new Ball:: Ball object
 * 
 * @param x horizontal position on screen
 * @param y vertical position on screen
 * @param radius radius of ball (filled circle)
 * @param velocity velocity vector of a ball
 * @param color filling color of a ball
 */
Ball::Ball(float x=0.f, float y=0.f, float radius=0.f, sf::Vector2f velocity={0.f, 0.f}, sf::Color color=sf::Color::White)
:  _position{x,y}, _radius{radius}, _velocityVec{velocity}
{
    if(x<0 || y<0 || radius<0)
        throw std::invalid_argument("Invalid arguments for Ball object (ctor).");
    //initializing shape
    _shape.setRadius(radius);
    _shape.setPosition(x, y);
    _shape.setFillColor(color);

    //setting metal texture to the ball
    sf::Texture* ballTexture = new sf::Texture;
    ballTexture->loadFromFile("img/metalTexture.jpg");
    ballTexture->setRepeated(true);
    _shape.setTexture(ballTexture);
}

/**
 * @brief Draws a shape and allows you to use better-to-read syntax "window.draw(shape)"
 * 
 * @param target target of drawing ex. window
 * @param states states used for drawing
 */
void Ball::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    target.draw(this->_shape, states);
}


int Ball::update(sf::Vector2f boxDimensions){
    int sideCollisionNumber = manageCollisionWithTheBox(boxDimensions);
    if(sideCollisionNumber==END_OF_GAME){
        return END_OF_GAME;
    }
    _shape.move(this->_velocityVec);
    return 0;
}


//////////////////////////////////
//            topSide           //
//             |                //
//       Pos   \/               //
//           #***               //
//leftSide-> *   * <-rightSide  //
//            ***               //
//             /\               //
//              |               //
//          bottomSide          //
//////////////////////////////////
//These functions returns position vectors of centers of each wall
sf::Vector2f Ball::leftSidePosition() const{
    return _shape.getPosition()+sf::Vector2f{0.f, _radius};
}
sf::Vector2f Ball::rightSidePosition() const{
    return _shape.getPosition()+sf::Vector2f{2*_radius, _radius};
}
sf::Vector2f Ball::bottomSidePosition() const{
    return _shape.getPosition()+sf::Vector2f{_radius, 2*_radius};
}
sf::Vector2f Ball::topSidePosition() const{
    return _shape.getPosition()+sf::Vector2f{_radius, 0.f};
}


/**
 * @brief Function checks if there is a collision between box and a ball in this box
 *        and if there is a collision it changes the ball velocity.
 * 
 * @param boxDimensions Dimension of the box that the ball is in
 * @return true 
 * @return false 
 */
int Ball::manageCollisionWithTheBox(sf::Vector2f boxDimensions){
    if(this->leftSidePosition().x <= 0.f){
        _velocityVec.x = -_velocityVec.x;
        return 0;
    }
    else if(this->rightSidePosition().x >= boxDimensions.x){
        _velocityVec.x = -_velocityVec.x;
        return 0;
    }
    else if(this->topSidePosition().y <= 0.f){
        _velocityVec.y = -_velocityVec.y;
        return 0;
    }
    else if(this->bottomSidePosition().y >= boxDimensions.y){
        _velocityVec.y = -_velocityVec.y;
        return END_OF_GAME;
    }
    return 0;
}