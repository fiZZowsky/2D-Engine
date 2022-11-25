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
#include "BitmapHandler.h"
#include "BitmapObject.h"
#include "SpriteObject.h"

using namespace sf;

enum WindowMode {FULLSCREEN, WINDOWED, CUSTOM};

class Engine {

	static const std::string PLAYER_SPRITESHEET;

private:
	static Engine* instance;
	Engine();
	virtual ~Engine();

	sf::Clock clock;
	float deltaTime;


	void init(int windowMode);
	void update();
	void render();

	PrimitiveRenderer primitiveRenderer;
	Player player;

public:
	static Engine *getInstance();

	sf::RenderWindow* window;

	bool doFillColor;

	void run();
	float getDeltaTime();

	void initGame();
};