#pragma once
#include "BitmapObject.h"
#include "AnimatedObject.h"

class SpriteObject : public virtual BitmapObject ,public virtual AnimatedObject
{
public:
	SpriteObject(sf::Image bitmap);
	SpriteObject(std::vector<sf::Image> bitmaps);

	void animate();



};