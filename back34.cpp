#include "settings.h"
#include "back34.h"

std::string Back34::back34_anim_files[] = {
	"num34back01.jpg",  "num34back02.jpg",
	"num34back03.jpg",  "num34back04.jpg",
	"num34back05.jpg",  "num34back06.jpg"
};

Back34::Back34() {
	texture.loadFromFile(IMAGES_FOLDER + BACK34_IMAGES_FOLDER + back34_anim_files[0]);
	sprite.setTexture(texture);

}
void Back34::update() {
	sf::Time now = back34_clock.getElapsedTime();
	if (now.asMilliseconds() > frame_delay) {
		frame++;
		if (frame < 6) {
			back34_clock.restart();
			texture.loadFromFile(IMAGES_FOLDER + BACK34_IMAGES_FOLDER + back34_anim_files[frame]);
			sprite.setTexture(texture);
		}
		else {
			del = true;
		}

	}
}
bool Back34::getDel() { return del; }
void Back34::draw(sf::RenderWindow& window) { window.draw(sprite); }