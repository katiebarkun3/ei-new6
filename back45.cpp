#include "settings.h"
#include "back45.h"

std::string Back45::back45_anim_files[] = {
	"num45back01.jpg",  "num45back02.jpg",
	"num45back03.jpg",  "num45back04.jpg",
	"num45back05.jpg",  "num45back06.jpg"
};

Back45::Back45() {
	texture.loadFromFile(IMAGES_FOLDER + BACK45_IMAGES_FOLDER + back45_anim_files[0]);
	sprite.setTexture(texture);

}
void Back45::update() {
	sf::Time now = back45_clock.getElapsedTime();
	if (now.asMilliseconds() > frame_delay) {
		frame++;
		if (frame < 6) {
			back45_clock.restart();
			texture.loadFromFile(IMAGES_FOLDER + BACK45_IMAGES_FOLDER + back45_anim_files[frame]);
			sprite.setTexture(texture);
		}
		else {
			del = true;
		}

	}
}
bool Back45::getDel() { return del; }
void Back45::draw(sf::RenderWindow& window) { window.draw(sprite); }