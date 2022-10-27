#pragma once
#include "Headers.h"
#include "Player.h"

using namespace sf;

class Engine {

public:
	Engine();
	virtual ~Engine();

	//Functions
	void run();

private:
	sf::RenderWindow* window;

	//Player
	Player* player;

	//Private functions
	void initWindow();
	void initPlayer();

	void update();
	void render();
};