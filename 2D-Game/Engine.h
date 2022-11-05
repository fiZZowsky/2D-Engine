#pragma once
#include "Headers.h"
#include "PrimitiveRenderer.h"
#include "Point2D.h"
#include "LineSegment.h"
#include <vector>
#include "Settings.h"

using namespace sf;

enum WindowMode { FULLSCREEN, WINDOWED, CUSTOM };

class Engine {

public:
	Engine();
	virtual ~Engine();

	sf::RenderWindow* window;

	//Functions
	void run();

private:
	sf::Clock clock;

	//Private functions
	void initWindow(int windowMode);

	void update();
	void render();

	/*void input();*/
	PrimitiveRenderer primitiveRenderer;



};