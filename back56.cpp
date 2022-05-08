#include "settings.h"
#include "back56.h"

std::string Back56::back56_anim_files[] = {
	"num56back01.jpg",  "num56back02.jpg",
	"num56back03.jpg",  "num56back04.jpg",
	"num56back05.jpg",  "num56back06.jpg"
};

Back56::Back56() {
	texture.loadFromFile(IMAGES_FOLDER + BACK56_IMAGES_FOLDER + back56_anim_files[0]);
	sprite.setTexture(texture);

}
void Back56::update() {
	sf::Time now = back56_clock.getElapsedTime();
	if (now.asMilliseconds() > frame_delay) {
		frame++;
		if (frame < 6) {
			back56_clock.restart();
			texture.loadFromFile(IMAGES_FOLDER + BACK56_IMAGES_FOLDER + back56_anim_files[frame]);
			sprite.setTexture(texture);
		}
		else {
			del = true;
		}

	}
}
bool Back56::getDel() { return del; }
void Back56::draw(sf::RenderWindow& window) { window.draw(sprite); }