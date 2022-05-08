#include "game.h"
#include "settings.h"
#include <iostream>

Game::Game() :
	window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT),
		WINDOW_TITLE,
		sf::Style::Titlebar | sf::Style::Close),
	splash_screen(IMAGES_FOLDER + SPLASH_FILE_NAME),
	rules_screen(IMAGES_FOLDER + RULES_SCREEN),
	back1(IMAGES_FOLDER + BACKGROUND1_FILE_NAME),
	back2(IMAGES_FOLDER + BACKGROUND2_FILE_NAME),
	back3(IMAGES_FOLDER + BACKGROUND3_FILE_NAME),
	back4(IMAGES_FOLDER + BACKGROUND4_FILE_NAME),
	back5(IMAGES_FOLDER + BACKGROUND5_FILE_NAME),
	back6(IMAGES_FOLDER + BACKGROUND6_FILE_NAME),
	player_hp("images/kenvector_future.ttf", 18, 13, 28, sf::Color::Yellow),
	score_text("images/kenvector_future.ttf", 24, 420, 5, sf::Color::Yellow),
	final_score_text("images/kenvector_future.ttf", 40, 70, 550, sf::Color(128, 0, 0)),
	snake_text("images/kenvector_future.ttf", 100, 250, 650, sf::Color(255 ,0 ,0)),
	game_over_screen(IMAGES_FOLDER + GAME_OVER_FILE_NAME)
      {
	window.setVerticalSyncEnabled(true);
	for (size_t i = 0; i < FOODS_QTY; i++) {
		Food* food = new Food();
		foods.push_back(food);
	}
	for (size_t i = 0; i < INEDIBLES_QTY; i++) {
		Inedible* inedible = new Inedible();
		inedibles.push_back(inedible);
	}
	
}

void Game::play() {
	while (window.isOpen()) {
		check_events();
		update();
		draw();
		check_collisions();
	}
}

void Game::check_events() {
	sf::Event event;
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			window.close();
		}
		if (event.type == sf::Event::KeyPressed) {
			if (game_state == INTRO && event.key.code == sf::Keyboard::Space) {
				game_state = RULES;
			}
			if (game_state == RULES && event.key.code == sf::Keyboard::Num1) {
				game_state = PLAY;
			}
		}
	}
}
	
void Game::update() {
	size_t num = 10;
	size_t numdeath = 34;
	sf::Time now_potion = potion_clock.getElapsedTime();
	sf::Time now_death = death_clock.getElapsedTime();
	switch (game_state) {
	case INTRO:
		break;
	case RULES:
		break;
	case PLAY:
		player.update();
		hpbar.update(player.getHp());
		for (size_t i = 0; i < FOODS_QTY; i++) {
			foods[i]->update();
		}
		for (size_t i = 0; i < INEDIBLES_QTY; i++) {
			inedibles[i]->update();
		}
		if (now_potion.asSeconds() > num) {
			potion_clock.restart();
			Potion* potion = new Potion();
			potions.push_back(potion);
		}
		for (auto i = potions.begin(); i != potions.end(); i++) {
			(*i)->update();
		}
		if (now_death.asSeconds() > numdeath) {
			death_clock.restart();
			Death* death = new Death();
			deaths.push_back(death);
		}
    	for (auto i = deaths.begin(); i != deaths.end(); i++) {
			(*i)->update();	
		}

		
		snake.update();
		
		player_hp.update("HP: " + std::to_string(player.getHp()));
		score_text.update("Score: " + std::to_string(score));
				if (player.getHp() <= 0) {
					game_state = GAME_OVER;
				}
			
		//back12
		if (score >= 20 && !back12.getDel()) { back12.update(); }
		if (back12.getDel()) { window.draw(back2.getSprite()); }// << смена фона на новый

		//back23
		if (score >= 50 && !back23.getDel()) { back23.update(); }
		if (back23.getDel()) { window.draw(back3.getSprite()); }

		//back34
		if (score >= 100 && !back34.getDel()) { back34.update(); }
		if (back34.getDel()) { window.draw(back4.getSprite()); }

		//back45
		if (score >= 120 && !back45.getDel()) { back45.update(); }
		if (back45.getDel()) { window.draw(back5.getSprite()); }

		//back56
		if (score >= 150 && !back56.getDel()) { back56.update(); }
		if (back56.getDel()) { window.draw(back6.getSprite()); }

		//back61
		if (score >= 200 && !back61.getDel()) { back61.update(); }
		if (back61.getDel()) { window.draw(back1.getSprite()); }

		break;
	case GAME_OVER:
		final_score_text.update("Your score is: " + std::to_string(score));
		break;
	}
}

void Game::draw() {
	switch (game_state) {
	case INTRO:
		window.clear(sf::Color::White);
		window.draw(splash_screen.getSprite());
		break;
	case RULES:
		window.clear(sf::Color(150, 150, 150));
		window.draw(rules_screen.getSprite());
		break;
	case PLAY:
		window.clear(sf::Color(150, 150, 150));
		window.draw(back1.getSprite());
		back12.draw(window);
		if (score >= 50) {
			back23.draw(window);
		}
		if (score >= 100) {
			back34.draw(window);
		}
		if (score >= 120) {
			back45.draw(window);
		}
		if (score >= 150) {
			back56.draw(window);
		}
		if (score >= 200) {
			back61.draw(window);
		}
		player.draw(window);
		for (size_t i = 0; i < FOODS_QTY; i++) {
			foods[i]->draw(window);
		}
		for (size_t i = 0; i < INEDIBLES_QTY; i++) {
			inedibles[i]->draw(window);
		}
		for (auto i = potions.begin(); i != potions.end(); i++) {
			(*i)->draw(window);
		}
		
		for (auto i = deaths.begin(); i != deaths.end(); i++) {
			(*i)->draw(window);
		}
		snake.draw(window);
	    window.draw(player_hp.getText());
		window.draw(score_text.getText());
		hpbar.draw(window);
		break;
	case GAME_OVER:
		window.clear(sf::Color(150, 150, 150));
		window.draw(game_over_screen.getSprite());
		window.draw(final_score_text.getText());
		break;
	}
	window.display();
}

void Game::check_collisions() {

	for (auto iter = foods.begin(); iter != foods.end(); iter++) {
		if (player.getHitBox().intersects((*iter)->getHitBox())) {
			(*iter)->spawn();
			player.increaseHp(2);
			score += 1;
		}
		if ((*iter)->getPosition().y > WINDOW_HEIGHT) {
			player.decreaseHp(6);
		}
	}
	for (auto iter = inedibles.begin(); iter != inedibles.end(); iter++) {
		if (player.getHitBox().intersects((*iter)->getHitBox())) {
			(*iter)->spawn();
			player.decreaseHp(4);
		}
	}
	for (auto iter = potions.begin(); iter != potions.end(); iter++) {
		if (player.getHitBox().intersects((*iter)->getHitBox())) {
			(*iter)->notspawn();
			player.increaseHp(10);
			score += 5;
		}
	}
	for (auto iter = deaths.begin(); iter != deaths.end(); iter++) {
		if (player.getHitBox().intersects((*iter)->getHitBox())) {
			(*iter)->notspawn();
			player.decreaseHp(20);
		}
	}

	if (player.getHitBox().intersects(snake.getHitBox())) {
			snake.spawn();
			player.decreaseHp(40);
			snake_text.update("-40 HP");
	}
	

}