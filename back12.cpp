#include "settings.h"
#include "back12.h"

std::string Back12::back12_anim_files[] = {
	"num12back01.jpg",  "num12back02.jpg", 
	"num12back03.jpg",  "num12back04.jpg", 
	"num12back05.jpg",  "num12back06.jpg"
};

Back12::Back12() {
	texture.loadFromFile(IMAGES_FOLDER + BACK12_IMAGES_FOLDER + back12_anim_files[0]);
	sprite.setTexture(texture);
	
}
void Back12::update() {
	sf::Time now = back12_clock.getElapsedTime();
	if (now.asMilliseconds() > frame_delay) {
		frame++;
		if (frame < 6) {
			back12_clock.restart();
			texture.loadFromFile(IMAGES_FOLDER + BACK12_IMAGES_FOLDER + back12_anim_files[frame]);
			sprite.setTexture(texture);
		}
		else {
			del = true;
		}

	}
}
bool Back12::getDel() { return del; }
void Back12::draw(sf::RenderWindow& window) { window.draw(sprite); }