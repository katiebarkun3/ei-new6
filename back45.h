#pragma once
#include "SFML/Graphics.hpp"

class Back45 {
private:
	sf::Texture texture;
	sf::Sprite sprite;
	static std::string back45_anim_files[];
	size_t frame = 0;
	size_t frame_delay = 42;
	sf::Vector2f position;
	bool del = false;
	sf::Clock back45_clock;
public:
	Back45();
	void update();
	void draw(sf::RenderWindow&);
	bool getDel();
};