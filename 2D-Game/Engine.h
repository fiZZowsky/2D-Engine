#pragma once
#include "Headers.h"
#include "Player.h"
#include "PrimitiveRender.h"

using namespace sf;

class Engine {

public:
	Engine();
	virtual ~Engine();

	sf::RenderWindow* window;

	//Functions
	void run();

private:	
	sf::Clock clock;

	//Player
	Player* player;

	PrimitiveRender primitiveRender;

	//Private functions
	void initWindow();
	void initPlayer();

	void update();
	void render();

	//Unused functions
	/*void input();*/
};