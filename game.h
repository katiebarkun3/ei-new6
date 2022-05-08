#pragma once
#include "SFML/Graphics.hpp"
#include "splash.h"
#include "player.h"
#include "food.h"
#include "text.h"
#include "inedible.h"
#include "potion.h"
#include "death.h"
#include "back12.h"
#include "back23.h"
#include "back34.h"
#include "back45.h"
#include "back56.h"
#include "back61.h"
#include "hpbar.h"
#include "snake.h"
#include <list>

class Game {
public:
	sf::RenderWindow window;
	enum GameState { INTRO, RULES, PLAY, GAME_OVER };
	Game();
	void play();
private:
	GameState game_state { INTRO };
	Player player;
	std::vector <Food*> foods;
	std::vector <Inedible*> inedibles;
	std::list <Potion*> potions;
	std::list <Death*> deaths;
	Snake snake;
	sf::Clock potion_clock;
	sf::Clock death_clock;
	sf::Clock greensnake_clock;
	SplashScreen splash_screen, game_over_screen, rules_screen;
	SplashScreen back1;
	SplashScreen back2;
	SplashScreen back3;
	SplashScreen back4;
	SplashScreen back5;
	SplashScreen back6;
	TextObject player_hp;
	TextObject score_text;
	TextObject final_score_text;
	TextObject snake_text;
	size_t score = 0;
	Back12 back12;
	Back23 back23;
	Back34 back34;
	Back45 back45;
	Back56 back56;
	Back61 back61;
	Hpbar hpbar;
	bool animShow = false;
	void check_events();
	void update();
	void draw();
	void check_collisions();
};