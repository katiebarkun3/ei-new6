#pragma once
#include "SFML/Graphics.hpp"

class Back12 {
private:
	sf::Texture texture;
	sf::Sprite sprite;
	static std::string back12_anim_files[];
	size_t frame = 0;
	size_t frame_delay = 42;
	sf::Vector2f position;
	bool del = false;
	sf::Clock back12_clock;
public:
	Back12();
	void update();
	void draw(sf::RenderWindow&);
	bool getDel();
};