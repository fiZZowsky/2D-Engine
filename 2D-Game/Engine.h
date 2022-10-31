#pragma once
#include "Headers.h"
#include "Player.h"
#include "PrimitiveRenderer.h"

#define CUSTOM_RESOLUTION_X 1280
#define CUSTOM_RESOLUTION_Y 720

using namespace sf;

enum WindowMode {FULLSCREEN, WINDOWED, CUSTOM};

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

	PrimitiveRenderer primitiveRenderer;


	//Private functions
	void initWindow(int windowMode);
	void initPlayer();

	void update();
	void render();

	//Unused functions
	/*void input();*/
};