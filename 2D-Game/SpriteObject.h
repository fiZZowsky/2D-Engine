#pragma once
#include "BitmapObject.h"
#include "AnimatedObject.h"
#include "Settings.h"

class SpriteObject : public virtual BitmapObject ,public virtual AnimatedObject
{

private:
	int framesCounter;

public:
	static const int FRAMES_SPEED = 8;

	SpriteObject();
	SpriteObject(std::string filename);

	void animate(sf::RenderWindow* window);

};