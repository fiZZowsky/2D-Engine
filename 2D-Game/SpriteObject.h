#pragma once
#include "BitmapObject.h"
#include "AnimatedObject.h"
#include "Settings.h"

class SpriteObject : public virtual BitmapObject ,public virtual AnimatedObject
{

private:
	int framesCounter;

public:

	SpriteObject();
	SpriteObject(std::string filename);

	void animate(sf::RenderWindow* window);

};