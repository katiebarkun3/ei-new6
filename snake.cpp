#include "snake.h"
#include "settings.h"
	
/*std::string Snake::snake_file_names[] = {
	"rightsnakef1.png"
};*/

Snake::Snake() {
	//size_t num = rand() % ;
	//texture.loadFromFile(IMAGES_FOLDER + snake_file_names[num]);
	texture.loadFromFile(IMAGES_FOLDER + "rightsnakef1.png");
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(147 * 0, 0, 147, 128));

	spawn();
}
void Snake::update() {
	sprite.move(2.f, 0.f);

	float time = snake_clock.getElapsedTime().asMicroseconds();
	snake_clock.restart();
	time = time / 800;
	sprite.setTextureRect(sf::IntRect(0, 0, 147, 128));
	CurrentFrame += 0.015 * time;
	if (sprite.getPosition().x >= 1200) {
		texture.loadFromFile(IMAGES_FOLDER + SNAKE_RIGHT_FILE_NAME);
		sprite.setTexture(texture);
		spawn();
	}
	if (CurrentFrame > 9) CurrentFrame -= 9;
	sprite.setTextureRect(sf::IntRect(147 * int(CurrentFrame), 0, 147, 128));
}
void Snake::draw(sf::RenderWindow& window) { window.draw(sprite); }
void Snake::spawn() {
	sf::FloatRect g_bound = sprite.getGlobalBounds();
	float x = -200;
	float y = 801;
	sprite.setPosition(x, y);
	speedx = 2.f;
	speedy = 0.f;
}
sf::FloatRect Snake::getHitBox() { return sprite.getGlobalBounds(); }
sf::Vector2f Snake::getPosition() { return sprite.getPosition(); }
void Snake::setDel(bool a) { del = a; }
bool Snake::getDel() { return del; }