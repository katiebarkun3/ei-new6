#include "hpbar.h"

Hpbar::Hpbar()
{
	image.loadFromFile(IMAGES_FOLDER + HPBAR_FILE_NAME);
	texture.loadFromImage(image);
	sprite.setTexture(texture);
	bar.setFillColor(sf::Color(0, 0, 0));//115, 224, 253));
	max = 100;
}

void Hpbar::update(int k)// k-текущее здоровье

{
	if (k > 0)
		if (k < max)
		bar.setSize(sf::Vector2f(((max - k) * 126 / max), 22));//если не отрицательно и при этом меньше максимума, то устанавливаем новое значение (новый размер) для черного прямоугольника
	if (k >= 100) {
		bar.setSize(sf::Vector2f(0, 0));
	}
	if (k <= 100 && k > 70) {
		image.loadFromFile(IMAGES_FOLDER + HPBAR_FILE_NAME);
		texture.loadFromImage(image);
		sprite.setTexture(texture);
	}
	if (k < 70 && k > 50) {
		image.loadFromFile(IMAGES_FOLDER + HPBAR_YELLOW_FILE_NAME);
		texture.loadFromImage(image);
		sprite.setTexture(texture);
	}
	if (k < 50 && k > 30) {
		image.loadFromFile(IMAGES_FOLDER + HPBAR_ORANGE_FILE_NAME);
		texture.loadFromImage(image);
		sprite.setTexture(texture);
	}
	if (k < 30 && k > 0) {
		image.loadFromFile(IMAGES_FOLDER + HPBAR_RED_FILE_NAME);
		texture.loadFromImage(image);
		sprite.setTexture(texture);
	}
	
}

void Hpbar::draw(sf::RenderWindow& window)
{

	sprite.setPosition(0, 0);//позиция на экране
	bar.setPosition(13, 9);

	window.draw(sprite);//сначала рисуем полоску здоровья
	window.draw(bar);//поверх неё уже черный прямоугольник, он как бы покрывает её
}

