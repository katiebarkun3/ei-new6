#pragma once
#include "SFML/Graphics.hpp"
#include "settings.h"
class Hpbar
{
public:
	sf::Image image;
	sf::Texture texture;
	sf::Sprite sprite;
	int max;
	sf::RectangleShape bar;
	Hpbar();
	void update(int k = PLAYER_HP);
	void draw(sf::RenderWindow& window);
};