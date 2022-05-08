#pragma once
#include "SFML/Graphics.hpp"

class Back61 {
private:
	sf::Texture texture;
	sf::Sprite sprite;
	static std::string back61_anim_files[];
	size_t frame = 0;
	size_t frame_delay = 42;
	sf::Vector2f position;
	bool del = false;
	sf::Clock back61_clock;
public:
	Back61();
	void update();
	void draw(sf::RenderWindow&);
	bool getDel();
};