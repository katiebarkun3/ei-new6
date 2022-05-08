#pragma once
#include "SFML/Graphics.hpp"

class Back56 {
private:
	sf::Texture texture;
	sf::Sprite sprite;
	static std::string back56_anim_files[];
	size_t frame = 0;
	size_t frame_delay = 42;
	sf::Vector2f position;
	bool del = false;
	sf::Clock back56_clock;
public:
	Back56();
	void update();
	void draw(sf::RenderWindow&);
	bool getDel();
};