#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

void makeBackground(sf::Sprite& sprite, const sf::Vector2i& position);

void endOfGame(sf::RenderWindow& window, sf::Event& event);

void showMainMenu(sf::RenderWindow& window, sf::Event& event);
