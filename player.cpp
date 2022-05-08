#include "player.h"
#include "settings.h"

Player::Player() {
	texture.loadFromFile(IMAGES_FOLDER + PLAYER_FILE_NAME);
	sprite.setTexture(texture);
	sf::FloatRect g_bounds = sprite.getGlobalBounds();
	sprite.setPosition(WINDOW_WIDTH / 2 - g_bounds.width / 2,
		WINDOW_HEIGHT - g_bounds.height - PLAYER_OFFSET_Y);
}
void Player::update() {

	sf::Vector2f position = sprite.getPosition();
	sf::FloatRect g_bounds = sprite.getGlobalBounds();

	float time = player_clock.getElapsedTime().asMicroseconds();
	player_clock.restart();
	time = time / 800;
	sprite.setTextureRect(sf::IntRect(0, 0, 128, 128));
	CurrentFrame += 0.005 * time;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) &&
		position.x < WINDOW_WIDTH - g_bounds.width) {

		texture.loadFromFile(IMAGES_FOLDER + RIGHT_ANIMATION_PLAYER_FILE_NAME);
	
		if (CurrentFrame > 3) CurrentFrame -= 3;
		sprite.setTextureRect(sf::IntRect(128 * int(CurrentFrame), 0, 128, 128));
		sprite.move(PLAYER_SPEED_X, 0.f);
	}



	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) &&
		position.x > 0) {

		texture.loadFromFile(IMAGES_FOLDER + LEFT_ANIMATION_PLAYER_FILE_NAME);

		if (CurrentFrame > 3) CurrentFrame -= 3;
		sprite.setTextureRect(sf::IntRect(128 * int(CurrentFrame), 0, 128, 128)); 
		sprite.move(-PLAYER_SPEED_X, 0.f);



	}
	else
	{  texture.loadFromFile(IMAGES_FOLDER + PLAYER_FILE_NAME);	}
}
void Player::draw(sf::RenderWindow& window) { window.draw(sprite); }
void Player::decreaseHp(size_t dmg) { hp -= dmg; }
void Player::increaseHp(size_t add_hp) { hp += add_hp; }
int Player::getHp() { return hp; }
sf::FloatRect Player::getHitBox() { return sprite.getGlobalBounds(); }
sf::Vector2f Player::getPosition() { return sprite.getPosition(); }

//void Player::reduceLife() {
//	texture.loadFromFile(IMAGES_FOLDER + GIRLS3_FILE_NAME);
//	sprite.setPosition(10.f, 40.f);
//	if (hp <= 0) {
//		hp += 20;
//		lives--;
//	}
//	if (lives == 2) {
//		texture.loadFromFile(IMAGES_FOLDER + GIRLS2_FILE_NAME);
//	}
//	if (lives == 1) {
//		texture.loadFromFile(IMAGES_FOLDER + GIRLS1_FILE_NAME);
//	}
//	sprite.setTexture(texture);
//}