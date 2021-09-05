#include "../inc/menu.hh"

void endOfGame(sf::RenderWindow& window, sf::Event& event){
    window.clear();
    window.setTitle("Game Over");
    sf::Text txt;
    sf::Font font;
    font.loadFromFile("fonts/Betterlove.ttf");
    txt.setFont(font);
    txt.setString("Game Over");
    txt.setFillColor(sf::Color::White);
    txt.setPosition(sf::Vector2f({250,250}));
    txt.setCharacterSize(128);
    window.draw(txt);
    window.display();
    while (true){
        window.pollEvent(event);
        if (event.type == sf::Event::Closed) {
            window.close();
            exit(0);
        }
    }
}

void showMainMenu(sf::RenderWindow& window, sf::Event& event){
    window.clear();
    window.setTitle("Menu");
    sf::Text txt;
    sf::Font font;
    font.loadFromFile("fonts/Betterlove.ttf");
    txt.setFont(font);
    txt.setString("Click space to start!");
    txt.setFillColor(sf::Color::White);
    txt.setPosition(sf::Vector2f({250,250}));
    txt.setCharacterSize(64);
    window.draw(txt);
    window.display();
    while (true){
        window.pollEvent(event);
        if (event.type == sf::Event::KeyPressed){
            if (event.key.code == sf::Keyboard::Space){
                break;
            }
        }
    }
}