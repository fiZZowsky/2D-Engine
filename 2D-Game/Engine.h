#pragma once
#include "Headers.h"
#include "PrimitiveRenderer.h"
#include "Point2D.h"
#include "LineSegment.h"
#include <vector>
#include "Settings.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"
#include "Polygon.h"
#include "Player.h"


using namespace sf;

enum WindowMode {FULLSCREEN, WINDOWED, CUSTOM};

class Engine {

protected:
	static Engine* instance;
	Engine();
	virtual ~Engine();

	sf::Clock clock;
	float deltaTime;


	//Private functions
	void initWindow(int windowMode);

	void update();
	void render();

	/*void input();*/
	PrimitiveRenderer primitiveRenderer;
	Player player;

public:
	static Engine *getInstance();

	sf::RenderWindow* window;
	//Functions
	void run();
	float getDeltaTime();

	
};