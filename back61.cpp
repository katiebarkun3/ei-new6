#include "settings.h"
#include "back61.h"

std::string Back61::back61_anim_files[] = {
	"num61back01.jpg",  "num61back02.jpg",
	"num61back03.jpg",  "num61back04.jpg",
	"num61back05.jpg",  "num61back06.jpg"
};

Back61::Back61() {
	texture.loadFromFile(IMAGES_FOLDER + BACK61_IMAGES_FOLDER + back61_anim_files[0]);
	sprite.setTexture(texture);

}
void Back61::update() {
	sf::Time now = back61_clock.getElapsedTime();
	if (now.asMilliseconds() > frame_delay) {
		frame++;
		if (frame < 6) {
			back61_clock.restart();
			texture.loadFromFile(IMAGES_FOLDER + BACK61_IMAGES_FOLDER + back61_anim_files[frame]);
			sprite.setTexture(texture);
		}
		else {
			del = true;
		}

	}
}
bool Back61::getDel() { return del; }
void Back61::draw(sf::RenderWindow& window) { window.draw(sprite); }