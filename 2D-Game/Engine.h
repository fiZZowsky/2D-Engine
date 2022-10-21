#pragma once

#include "frameworks.h"
#include "character.h"

using namespace sf;

class Engine {
private:
	RenderWindow m_window;

	character character;

	void input();
	void collision();
	void update(float dtAsSeconds);
	void draw();	

public:
	Engine();

	void start();
};