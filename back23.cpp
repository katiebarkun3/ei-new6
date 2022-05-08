#include "settings.h"
#include "back23.h"

std::string Back23::back23_anim_files[] = {
	"num23back01.jpg",  "num23back02.jpg",
	"num23back03.jpg",  "num23back04.jpg",
	"num23back05.jpg",  "num23back06.jpg"
};

Back23::Back23() {
	texture.loadFromFile(IMAGES_FOLDER + BACK23_IMAGES_FOLDER + back23_anim_files[0]);
	sprite.setTexture(texture);

}
void Back23::update() {
	sf::Time now = back23_clock.getElapsedTime();
	if (now.asMilliseconds() > frame_delay) {
		frame++;
		if (frame < 6) {
			back23_clock.restart();
			texture.loadFromFile(IMAGES_FOLDER + BACK23_IMAGES_FOLDER + back23_anim_files[frame]);
			sprite.setTexture(texture);
		}
		else {
			del = true;
		}

	}
}
bool Back23::getDel() { return del; }
void Back23::draw(sf::RenderWindow& window) { window.draw(sprite); }